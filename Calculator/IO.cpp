#include "IO.h"
#include <stdio.h>

int input(float* a) {
	printf("Enter Num\n");
	scanf_s("%f", a);
	return 1;
}

void out(float a) {
	printf("Result: %.2f\n\n", a);
}

void outError(int err) {
	switch (err)
	{
	case -1:
		printf("Zero division");
		break;
	case -2:
		printf("Undefinded option");
		break;
	default:
		printf("Unknown Error");
		break;
	}
	printf("\n\n");
}

int inpOption(int* op) {
	printf("Enter option: 1 - '+', 2 - '-', 3 - '/', 4 - '*'\n");
	scanf_s("%d", op);
	return 1;
}