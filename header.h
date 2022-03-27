#ifndef HEADER_H
#define HEADER_H

#include <iostream>

class Money {
private:
	int totalCents;
public:
	explicit Money();
	explicit Money(int inputDollar, int inputCents);
	
	bool operator> (const Money& other) {
		return totalCents > other.totalCents;
	}
	bool operator< (const Money& other) {
		return totalCents < other.totalCents;
	}
	bool operator>= (const Money& other) {
		return totalCents >= other.totalCents;
	}
	bool operator<= (const Money& other) {
		return totalCents <= other.totalCents;
	}
	bool operator!= (const Money& other) {
		return totalCents != other.totalCents;
	}
	bool operator== (const Money& other) {
		return totalCents == other.totalCents;
	}

	int operator+ (const Money& other) {
		return totalCents + other.totalCents;
	}
	int operator- (const Money& other) {
		return totalCents - other.totalCents;
	}


	friend std::ostream &operator<< (std::ostream &out, const Money &m) {
		//This is done instead of multiplying totalCents by 0.01 to keep the zero (prints $1.10 instead of $1.1)
		out << "$" << (m.totalCents - m.totalCents%100) / 100 << "." << m.totalCents%100;
		return out;
	}

};

#endif
