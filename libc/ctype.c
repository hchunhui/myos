/* ctype.c */
#include <os/type.h>
#include <os/unistd.h>
#include <libc/libc.h>

int isdigit(int x)
{
	return (x>='0' && x<='9');
}

int isxdigit(int x)
{
	return ((x>='0' && x<='9') || (x>='a' && x<='f') || (x>='A' && x<='F'));
}

int islower(int x)
{
	return (x>='a' && x<='z');
}

int isspace(int x)
{
	return (x==' ') || (x=='\n') || (x=='\r');
}

int isalpha(int x)
{
	return (x>='a' && x<='z') || (x>='A' && x<='Z');
}

int isupper(int x)
{
	return (x>='A' && x<='Z');
}

int toupper(int x)
{
	return (x>='a' && x<='z')?(x-'a'+'A'):x;
}
