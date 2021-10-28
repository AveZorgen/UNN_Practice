#include "Calc.h"
#include <math.h>
int add(float a, float b, float* res) {
	*res = a + b;
	return 0;
}
int minus(float a, float b, float* res) {
	*res = a - b;
	return 0;
}
int division(float a, float b, float* res) {
	if (b == 0) return -1;
	*res = a / b;
	return 0;
}
int multiplication(float a, float b, float* res) {
	*res = a * b;
	return 0;
}

float calcThis(int op, float a, float b, float* res) {
	int errCode;
	switch (op)
	{
	case 1:
		errCode = add(a, b, res);
		break;
	case 2:
		errCode = minus(a, b, res);
		break;
	case 3:
		errCode = division(a, b, res);
		break;
	case 4:
		errCode = multiplication(a, b, res);
		break;
	default:
		errCode = -2;
		break;
	}
	return errCode;

}
