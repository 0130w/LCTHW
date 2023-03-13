#include <stdio.h>
#include <ctype.h>
#include <string.h>

// forward declarations
void print_letters(char argv[]);

// print the arguments of command line
void print_arguments(int argc,char *argv[])
{
	int i = 0;

	for(i = 0; i < argc; ++i){
		print_letters(argv[i]);
	}
}

void print_letters(char arg[])
{
	int i = 0;
	
	printf("strlen: %zu\n",strlen(arg));

	for(i = 0; i < strlen(arg); ++i){
		char ch = arg[i];

		if(isalpha(ch) || isblank(ch))
			printf("'%c' == %d ", ch, ch);
	}

	printf("\n");
}

int main(int argc, char* argv[])
{
	print_arguments(argc,argv);
	return 0;
}
