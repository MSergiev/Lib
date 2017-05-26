#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <cmath>
using std::ostream;
using std::istream;
using std::string;
using std::cerr;
using std::endl;

class Rational{
public:
	Rational(const int& num = 0,
			const int& denom = 1);
	void setNum(const int num);
	void setDenom(const int denom);
	int getNum() const;
	int getDenom() const;
	bool isNegative() const;
	double asDouble() const;
	Rational operator+(Rational& obj);
	Rational operator-(Rational& obj);
	Rational operator*(Rational& obj);
	Rational operator/(Rational& obj);
	Rational& operator+=(Rational& obj);
	Rational& operator-=(Rational& obj);
	Rational& operator++(int a);
	Rational& operator++();
	Rational& operator--(int a);
	Rational& operator--();
	bool operator>(Rational& obj);
	bool operator<(Rational& obj);
	bool operator>=(Rational& obj);
	bool operator<=(Rational& obj);
	bool operator==(Rational& obj);
	bool operator!=(Rational& obj);
	friend ostream& operator<<(ostream& os, const Rational& obj);
	friend istream& operator>>(istream& is, Rational& obj);
	~Rational();

private:
	void simplify();
	int gcd(int a, int b);
	int num, denom;
	bool negative;
};

#endif
