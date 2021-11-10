#include <stdio.h>
#include "IO.h"
#include "Calc.h"

using namespace std;

int main() {
	float b, a = 0;
	int op;
	input(&a);
	while (inpOption(&op)) {
		input(&b);
		if (!calcThis(op, a, b, &a))
			out(a);
		else outError(calcThis(op, a, b, &a));
	}
	return 0;
}