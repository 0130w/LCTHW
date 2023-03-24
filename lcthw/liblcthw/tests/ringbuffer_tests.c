#include <lcthw/ringbuffer.h>
#include "minunit.h"
#include <assert.h>
#include <stdio.h>

#define BUFFER_SPACE 100
#define NUM_TESTS 3

char target[100] = {'\0'};

static RingBuffer *buffer = NULL;
char *tests[] = {"test1 data", "test2 data", "test3 data"};

char *test_create()
{
    buffer = RingBuffer_create(BUFFER_SPACE);
    mu_assert(buffer != NULL, "Failed to create buffer.");
    
    return NULL;
}

char *test_destroy()
{
    mu_assert(buffer != NULL, "Failed to make buffer #2.");
    RingBuffer_destroy(buffer);

    return NULL;
}

char *test_write_read()
{
    int i = 0;
    int rc;
    for(i = 0; i < NUM_TESTS; ++i) {
        rc = RingBuffer_write(buffer, tests[i], sizeof(tests[i]));
        mu_assert(rc == sizeof(tests[i]), "Failed to write tests.");
        // printf("av: %d\n", RingBuffer_available_data(buffer));
    }
    
    for(i = 0; i < NUM_TESTS; ++i) {
        // printf("size:   %zu\n", sizeof(tests[i])); 
        rc = RingBuffer_read(buffer, target, sizeof(tests[i]));
        // printf("now av: %d\n", RingBuffer_available_data(buffer)); 
        mu_assert(rc == sizeof(tests[i]), "Failed to read tests");
    }

    mu_assert(RingBuffer_empty(buffer), "Should be empty.");

    return NULL;
}

char *all_tests() {
    mu_suite_start();

    mu_run_test(test_create);
    mu_run_test(test_write_read);
    mu_run_test(test_destroy);

    return NULL;
}

RUN_TESTS(all_tests);
