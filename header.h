#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>

class Money {
private:
	int totalCents;
public:
	explicit Money();
	explicit Money(int inputDollar, int inputCents);
	
	bool operator > (const Money& other) {
		return totalCents > other.totalCents;
	}
	bool operator < (const Money& other) {
		return totalCents < other.totalCents;
	}
	bool operator >= (const Money& other) {
		return totalCents >= other.totalCents;
	}
	bool operator <= (const Money& other) {
		return totalCents <= other.totalCents;
	}
	bool operator != (const Money& other) {
		return totalCents != other.totalCents;
	}
	bool operator == (const Money& other) {
		return totalCents == other.totalCents;
	}

	int operator + (const Money& other) {
		return totalCents + other.totalCents;
	}
	int operator - (const Money& other) {
		return totalCents - other.totalCents;
	}

	friend std::ostream &operator<< (std::ostream &out, const Money &m) {
		//This is done instead of multiplying totalCents by 0.01 to keep the zero (prints $1.10 instead of $1.1)
		out << "$" << (m.totalCents - m.totalCents%100) / 100 << "." << m.totalCents%100;

		//Ensures both zeroes are printed for cents
		if ((m.totalCents%100) == 0) {
		out << 0;
		}
		return out;
	}

};

class Account: public Money {
private:
	std::vector <Money> deposit;
	std::vector <Money> withdraw;
public:

	explicit Account(const Money m);
	
	void makeDeposit(const Money m);
	void makeWithdrawal(const Money m);

	friend std::ostream &operator<< (std::ostream &out, const Account &a) {
		out << "Account Details" << std::endl;
		out << "--------------------------" << std::endl;
		out << "Current Balance: " << a.deposit[0] << std::endl;
		out << "--------------------------" << std::endl;
		out << "Number of Deposits: " << a.deposit.size() - 1 << std::endl;
		out << "--------------------" << std::endl;
		for (int d = 1; d<a.deposit.size(); d++) {
			out << "(" << d << ") " << a.deposit[d] << std::endl;
		}
		out << "--------------------------" << std::endl;
		out << "Number of Withdrawals: " << a.withdraw.size() << std::endl;
		for (int w = 0; w<a.withdraw.size(); w++) {
			out << "(" << w << ") " << a.withdraw[w] << std::endl;
		}

		return out;
	}
};

#endif
