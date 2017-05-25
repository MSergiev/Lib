#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using std::ostream;
using std::istream;
using std::endl;

class Complex{
public:
	Complex(const double& real = 0,
			const double& imag = 0);
	void setReal(const double real);
	void setImag(const double imag);
	double getReal() const;
	double getImag() const;
	Complex operator+(Complex& obj);
	Complex operator-(Complex& obj);
	Complex operator*(Complex& obj);
	Complex operator/(Complex& obj);
	Complex operator-();
	Complex operator~();
	bool operator==(const Complex& obj);
	bool operator!=(const Complex& obj);
	friend istream& operator>>(istream& is, Complex& obj);
	friend ostream& operator<<(ostream& os, const Complex& obj);
	~Complex();

private:
	double real, imag;
};

#endif
