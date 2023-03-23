#undef NDEBUG
#ifndef _minunit_h
#define _minunit_h

#include <stdio.h>
#include <lcthw/dbg.h> 
#include <stdlib.h>

#define mu_suite_start() char *message = NULL

#define mu_assert(test, message) if(!(test)) { log_err("mu_assert", message); return message; }
// 这里是说在我们刚开头要mu_suite_start创建一个message为了mu_run_test调用
// 在调用的时候，如果test错误，由mu_assert返回错误信息到mu_run_test
// 否则函数成功就会返回NULL，就不返回信息了
#define mu_run_test(test) debug("\n-----%s", " "#test); \
	message = test(); tests_run++; if(message) return message;

#define RUN_TESTS(name) int main(int argc, char **argv){\
    argc = 1;\
	debug("\n----- RUNNING: %s", argv[0]);\
	char *result = name();\
	if(result != 0) {\
		printf("FAILED: %s\n", result);\
	}\
	else {\
		printf("ALL TESTS PASSED\n");\
	}\
	printf("Tests run: %d\n", tests_run);\
	exit(result != 0);\
}

int tests_run;

#endif
