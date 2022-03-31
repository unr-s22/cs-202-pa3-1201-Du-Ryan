#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <numeric>

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

	Money operator + (const Money& other) {
		int sum = totalCents + other.totalCents;
		Money m((sum - sum%100) / 100, sum%100);
		return m;
	}
	Money operator - (const Money& other) {
		int diff = totalCents - other.totalCents;
		Money m((diff - diff%100) / 100, diff%100);
		return m;
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
	bool needUpdate = false;
public:

	explicit Account(const Money m);
	
	void makeDeposit(const Money m);
	void makeWithdrawal(const Money m);

	friend std::ostream &operator<< (std::ostream &out, Account &a) {
		out << "Account Details" << std::endl;
		out << "--------------------------" << std::endl;
		if (a.needUpdate) {
			Money s;
			auto sumBal = std::accumulate(a.deposit.begin(), a.deposit.end(), s);

			Money d;
			auto debt = std::accumulate(a.withdraw.begin(), a.withdraw.end(), d);
			
			out << "Current Balance: " << sumBal - debt << std::endl;
			
			a.needUpdate = false;
		}
		else {
			out << "Current Balance: " << a.deposit[0] << std::endl;
		}
		out << "--------------------------" << std::endl;
		out << "Number of Deposits: " << a.deposit.size() << std::endl;
		out << "--------------------" << std::endl;
		for (int d = 0; d<a.deposit.size(); d++) {
			out << "(" << d + 1 << ") " << a.deposit[d] << std::endl;
		}
		out << "--------------------------" << std::endl;
		out << "Number of Withdrawals: " << a.withdraw.size() << std::endl;
		for (int w = 0; w<a.withdraw.size(); w++) {
			out << "(" << w + 1 << ") " << a.withdraw[w] << std::endl;
		}

		return out;
	}
};

#endif
