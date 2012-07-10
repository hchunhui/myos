
void inbuf_init();
void malloc_init();

char **environ;

void libc_init(int argc, char **argv, char **envp)
{
	environ = envp;
	malloc_init();
	inbuf_init();
}

