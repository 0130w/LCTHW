#include "ex22.h"
#include "../ex20/dbg.h"

const char *MY_NAME = "Zzq";

void scope_demo(int count)
{
	log_info("scope_demo", "count is: %d", count);

	if(count > 10) {
		int count = 100; // BAD! BUGS!
	
		log_info("scope_demo", "count in this scope is %d", count);
	}

	log_info("scope_demo", "count is at exit: %d", count);

	count = 3000;

	log_info("scope_demo", "count after assign: %d", count);

	// test
	scope_demo(count);
}

int main(int argc, char **argv)
{
	// test out THE_AGE accessors
	log_info("main", "My name: %s, age: %d", MY_NAME, get_age());

	set_age(100);

	log_info("main", "My age is now: %d", get_age());

	// test out THE_SIZE extern
	log_info("main", "THE_SIZE is: %d", THE_SIZE);
	print_size();

	THE_SIZE = 9;	// extern 在其他文件能改吗？ interesting! 这是可以直接做到的
	
	log_info("main", "THE SIZE is now: %d", THE_SIZE);
	print_size();

	// test the ratio function static
	// 这个还挺有意思的，如果说三个返回的都是传入的值的话
	// 就说明给old_ratio用static的variable赋值的时候
	// 有点像是在使用地址一样

	//log_info("main", "Ratio at first: %f", update_ratio(2.0));
	//log_info("main", "Ratio again: %f", update_ratio(10.0));
	//log_info("main", "Ratio once more: %f", update_ratio(300.0));

	double* ptr = update_ratio(2.0);
	printf("the value of ptr:%lf\n", *ptr);

	// test the scope demo
	int count = 4;
	scope_demo(count);
	scope_demo(count * 20);

	log_info("main", "count after calling scope_demo: %d", count);

	return 0;
}


