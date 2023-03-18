#include <stdio.h>

int main()
{
	int maxn = 1;
	if(maxn == 2)
	{
		return 0;
	} else {
		goto error;
	}

	return 0;

error:
	printf("You failed\n");
	return 1;
}
