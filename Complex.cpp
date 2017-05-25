#include "Complex.h"

Complex::Complex(const double& real, const double& imag) {
	setReal(real);
	setImag(imag);
}

void Complex::setReal(const double real) {
	this->real=real;
}

void Complex::setImag(const double imag) {
	this->imag=imag;
}

double  Complex::getReal() const {
    return real;
}

double Complex::getImag() const {
    return imag;
}

Complex Complex::operator+(Complex & obj) {
	return Complex(real+obj.getReal(), imag+obj.getImag());
}

Complex Complex::operator-(Complex & obj) {
    Complex c = -obj;
	return *this+c;
}

Complex Complex::operator*(Complex & obj) {
    return Complex((real*obj.getReal()-imag*obj.getImag()), (real*obj.getImag()+imag*obj.getReal()));
}

Complex Complex::operator/(Complex & obj) {
    Complex conj = ~obj;
	Complex c = (*this)*conj;
	c.setReal(c.getReal()/(obj.getReal()*obj.getReal() + obj.getImag()*obj.getImag()));
	c.setImag(c.getImag()/(obj.getReal()*obj.getReal() + obj.getImag()*obj.getImag()));
	return c;
}

Complex Complex::operator~(){
	return Complex(real, -imag);
}

Complex Complex::operator-(){
	return Complex(-real, -imag);
}

bool Complex::operator==(const Complex & obj) {
	if(real==obj.getReal() and imag==obj.getImag()) return true;
	return false;
}

bool Complex::operator!=(const Complex & obj) {
    return !(*this==obj);
}

istream& operator>>(istream& is, Complex& obj){
	double real, imag;
	bool realNeg = false, imagNeg = false;
	if(is.peek()=='-'){ realNeg = true; is.ignore(); }
	is >> real;
	if(is.get()=='-') imagNeg = true;
	is >> imag;
	obj.setReal(realNeg?(-real):real);
	obj.setImag(imagNeg?(-imag):imag);
	return is;
}

ostream& operator<<(ostream& os, const Complex& obj){
	if(obj.getReal()==0) os << obj.getImag() << "i";
	else os << obj.getReal() << (obj.getImag()>=0?"+":"") << obj.getImag() << "i";
	return os;
}

Complex::~Complex() {

}

