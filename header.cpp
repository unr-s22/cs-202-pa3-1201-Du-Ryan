#include "header.h"

Money::Money() {
	totalCents = 0;
}

Money::Money(int in_dollar, int in_cent) {
	totalCents = (in_dollar * 100) + in_cent;
}

Account::Account(Money m) {
	deposit.push_back(m);
	needUpdate = true;
}

void Account::makeDeposit(Money m) {
	deposit.push_back(m);
	needUpdate = true;
}

void Account::makeWithdrawal(Money m) {
	withdraw.push_back(m);
	needUpdate = true;
}
