#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
	void* handle;
	int (*add)(int, int);
	char* error;

	handle = dlopen("./mathlib.so", RTLD_LAZY);

	if(!handle)
	{
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}

	add = dlsym(handle, "add");

	if((error = dlerror()) != NULL)
	{
		fprintf(stderr, "%s\n", error);
		exit(1);
	}

	int sum = add(10, 20);

	printf("%d\n", sum);

	if(dlclose(handle) <0)
	{
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}
}