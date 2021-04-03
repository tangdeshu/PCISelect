#include "wtapi.h"
#include <stdio.h>

int main()
{
	int val = 10;

	val = ar_FindDevice(0, 1);
	printf("test value = %d \n", val);
	system("pause");
	return 0;
}