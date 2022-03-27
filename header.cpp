#include "header.h"

Money::Money() {
	totalCents = 0;
}

Money::Money(int in_dollar, int in_cent) {
	totalCents = (in_dollar * 100) + in_cent;
}


