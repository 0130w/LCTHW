#include <stdio.h>

int main(int argc, char* argv[])
{
	char** arg = argv;

	int i=0;

	while(i < argc)
	{
		printf("arg %d: %s , address: %p\n",i,*(arg + i),arg+i);
		++i;
	}

	return 0;
}
