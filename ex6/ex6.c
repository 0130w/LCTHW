#include <stdio.h>

int main(int argc, char* argv[]){
	int distance = 100;
	float power = 2.345f;
	double super_power = 56789.4523;
	char initial = 'A';
	char first_name[] = "Zed";
	char last_name[] = "Shaw";

	printf("You are %d miles away.\n",distance);
	printf("You are %f levels of power.\n",power);
	printf("You have %f awesome super powers.\n",super_power);
	printf("I have an initial %c.\n",initial);
	printf("I have a first name %s.\n",first_name);
	printf("I have a last name %s.\n",last_name);
	printf("My whole name is %s %c. %s.\n",first_name,initial,last_name);

	//This is a sentence to tell the program to print 10 in hex
	printf("%x\vawa\towo\n",10);
	//This is a sentence to tell the program to print empty character
	printf("");
	
	return 0;
}
