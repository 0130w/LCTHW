#include <stdio.h>
#include <string.h>


void print_first_way(int *ages, char **names, int count)
{
	for(int i = 0; i < count; ++i){
		printf("%s has %d years alive.\n",names[i],ages[i]);
	}
}

void print_second_way(int *ages, char **names, int count)
{
	int *cur_age = ages;
	char **cur_name = names;

	for(int i = 0; i < count; ++i){
		printf("%s is %d years old.\n",*(cur_name + i), *(cur_age + i));
	}
}

void print_third_way(int *ages, char **names, int count) 
{
	int *cur_age = ages;
	char **cur_name = names;

	for(int i = 0; i < count; ++i) {
		printf("%s is %d years old again.\n",cur_name[i],cur_age[i]); 
	}
}

void print_fourth_way(int *ages, char **names, int count)
{
	int *cur_age = ages;
	char **cur_name = names;

	for(;(cur_age - ages) < count; ++cur_age,++cur_name) {
		printf("%s lived %d years so far.\n",*cur_name,*cur_age);
	}
}

int main(int argc, char* argv[])
{
	// create two arrays we care about

	int ages[] = {23, 43, 12, 89, 2};
	char* names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};

	//safely get the size of ages
	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	//first way using indexing
	print_first_way(ages,names,count);

	printf("---\n");

	// setup the pointers to the start of the arrays

	print_second_way(ages,names,count);

	printf("---\n");

	// third way, pointers are just arrays

	print_third_way(ages,names,count);

	printf("---\n");

	// fourth way with pointers in a stupid complex way
	
	print_fourth_way(ages,names,count);

	return 0;
}
