#include "header.h"

int main() {

	Money initial(300,23);
	Account a(initial);

	Money dep1(200,00);
	Money dep2(300,24);
	Money dep3(501,22);
	Money withd1(300,10);
	Money withd2(201,34);

	a.makeDeposit(dep1);
	a.makeDeposit(dep2);
	a.makeDeposit(dep3);
	a.makeWithdrawal(withd1);
	a.makeWithdrawal(withd2);
	
	//TODO actually show the current balance instead of just showing the initial bal
	//TODO Write code to verify that your relational operators are working correctly, make outputs into the console

	std::cout << a << std::endl;

	return 0;
}
