#include "dbg.h"
#include <stdlib.h>
#include <stdio.h>

void test_debug()
{
	// notice you don't need the \n
	debug("I have Brown Hair.");

	// passint in arguments like printf
	debug("I am %d years old.", 37);
}

void test_log_err()
{
	log_err("test_log_err", "I believe everything is broken.");
	log_err("test_log_err", "There are %d problems in %s.", 0, "space");
}

void test_log_warn()
{
	log_warn("test_log_warn", "You can safely ignore this.");
	log_warn("test_log_warn", "Maybe consider looking at: %s.", "/etc/passwd");
}

void test_log_info()
{
	log_info("test_log_info", "Well I did something mundane.");
	log_info("test_log_info", "It happened %f times today.", 1.3f);
}

int test_check(char *file_name)
{
	FILE *input = NULL;
	char *block = NULL;

	block = malloc(100);
	check_mem(block, "test_check"); // should work
	
	input = fopen(file_name, "r");
	check(input,"test_check", "Failed to open %s.", file_name);

	free(block);
	fclose(input);
	return 0;

// ???还可以这么写啊
error:
	if(block) free(block);
	if(input) free(input);
	return -1;

}

int test_sentinel(int code)
{
	char *temp = malloc(100);
	check_mem(temp, "test_sentinel");

	switch(code) {
		case 1:
			log_info("test_sentinel", "It worked.");
			break;
		default:
			sentinel("test_sentinel", "I shouldn't run.");
	}

	free(temp);
	return 0;

error:
	if(temp) free(temp);
	return -1;

}

int test_check_mem()
{
	char *test = NULL;
	check_mem(test, "test_check_mem");

	free(test);
	return 0;

error:
	return -1;
}

int test_check_debug()
{
	int i = 0;
	check_debug(i != 0, "Oops, I was 0.");

	return 0;

error:
	return -1;
}

int main(int argc, char **argv)
{
	check(argc == 2, "main", "Need an argument");

	test_debug();
	test_log_err();
	test_log_warn();
	test_log_info();

	check(test_check("ex20.c") == 0, "main", "failed with ex20.c");
	check(test_check(argv[1]) == -1, "main", "failed with argv");
	check(test_sentinel(1) == 0, "main", "test_sentinel failed.");
	check(test_sentinel(100) == -1, "main", "test_sentinel failed.");
	check(test_check_mem() == -1, "main", "test_check_mem failed.");
	check(test_check_debug() == -1, "main", "test_check_debug failed.");

	return 0;

error:
	return 1;
}
