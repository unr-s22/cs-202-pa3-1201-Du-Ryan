#include "header.h"

int main() {

	Money initial(300,23);
	Account a(initial);

	std::cout << a <<std::endl;

	Money dep1(200,00);
	Money dep2(300,24);
	Money dep3(501,22);
	Money withd1(300,10);
	Money withd2(201,34);

	a.makeDeposit(dep1);
	a.makeDeposit(dep2);
	a.makeDeposit(dep3);

	std::cout << a <<std::endl;

	a.makeWithdrawal(withd1);
	a.makeWithdrawal(withd2);

	std::cout << a <<std::endl;

	//Relational operater tests
	if ((withd1 > dep2) && (withd1 >= dep2)) {
		std::cout << "The first withdrawal is greater than or equal to the thrid deposit" << std::endl;
	}
	else {
		std::cout << "The first withdrawal is less than the thrid deposit" << std::endl;
	}	

	if ((dep1 < dep2) && (dep1 <= dep2)) {
		std::cout << "The second deposit is less than or equal to the third deposit" << std::endl;
	}
	else {
		std::cout << "The second deposit is greater than the third deposit" << std::endl;
	}
	
	if (withd2 != withd1) {
		std::cout << "The first withdrawal is not equal to the second withdrawal" << std::endl;
	}
	else {
		std::cout << "The first withdrawal is equal to the second withdrawal" << std::endl;
	}



	return 0;
}
