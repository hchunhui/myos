/*
 * Simple Unix-like program to list the files in a directory.
 *
 * Copyright (C) 1997 Massachusetts Institute of Technology
 * See section "MIT License" in the file LICENSES for licensing terms.
 *
 * Derived from the MIT Exokernel and JOS.
 */

/* 2013.7.16 modify */

#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <assert.h>
#include <unistd.h>

int flag[256];

void lsdir(const char *path, const char *realpath);
void lsfile(const char *path, const char *realpath);

void
ls(const char *path)
{
	int r;
	struct stat st;

	const char *realpath = path;
	if (stat(realpath, &st) < 0)
	{
		printf("stat %s: %s\n", realpath, strerror(errno));
		exit(1);
	}
	if (S_ISDIR(st.st_mode) && !flag['d'])
		lsdir(path, realpath);
	else
		lsfile(path, realpath);
}

void
lsdir(const char *path, const char *realpath)
{
	DIR *d;
	struct dirent *de;

	if ((d = opendir(realpath)) == NULL)
	{
		printf("opendir %s: %s\n", realpath, strerror(errno));
		exit(1);
	}
	while ((de = readdir(d)) != NULL) {
		char depath[PATH_MAX];
		snprintf(depath, PATH_MAX, "%s%s%s", path,
			(path[0] && path[strlen(path)-1] != '/') ? "/" : "",
			de->d_name);
		lsfile(depath, depath);
	}
	closedir(d);
}

void
lsfile(const char *path, const char *realpath)
{
	char *sep;

	// Get information about the file
	struct stat st;
	if (stat(realpath, &st) < 0) {
		printf("error reading %s: %s\n", realpath, strerror(errno));
		return;
	}
	int isdir = S_ISDIR(st.st_mode);

	if(flag['l'])
		printf("%c %11d ", 
			isdir ? 'd' : '-',
			st.st_size);
	printf("%s", path);
	if(flag['F'] && isdir)
		printf("/");
	printf("\n");
}

void
usage(void)
{
	fprintf(stderr, "usage: ls [-dFl] [file...]\n");
	exit(EXIT_FAILURE);
}

int
main(int argc, char **argv)
{
	int i;
	int opt;

	while ((opt = getopt(argc, argv, "dFl")) != -1)
	{
		switch (opt)
		{
		default:
			usage();
		case 'd':
		case 'F':
		case 'l':
			flag[opt] = 1;
			break;
		}
	}

	if (optind < argc) {
		for (i = optind; i < argc; i++)
			ls(argv[i]);
	} else
		ls("/");

	return 0;
}

