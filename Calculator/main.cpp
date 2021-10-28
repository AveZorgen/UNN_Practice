#include <stdio.h>
#include "IO.h"
#include "Calc.h"

using namespace std;

int main() {
	float b, res = 0;
	int op;
	input(&res);
	while (inpOption(&op)) {
		input(&b);
		if (!calcThis(op, res, b, &res))
			out(res);
		else outError(calcThis(op, res, b, &res));
	}
	return 0;
}
