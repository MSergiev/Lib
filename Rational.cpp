#include "Rational.h"

Rational::Rational(const int & num, const int & denom) {
	//(num*denom<0)?negative=true:negative=false; 
	setNum(num);
	setDenom(denom);
	simplify();
}

void Rational::setNum(const int num) {
	this->num=num;
}

void Rational::setDenom(const int denom) {
	if(denom==0) { cerr << "Denominator cannot be zero" << endl; return; }
	this->denom=denom;
}

int Rational::getNum() const {
    return num;
}

int Rational::getDenom() const {
    return denom;
}

bool Rational::isNegative() const{
	return negative;
}

double Rational::asDouble() const {
    return (static_cast<double>(num)/denom);
}

Rational Rational::operator+(Rational & obj) {
	if(denom == obj.getDenom())
		return Rational((num+obj.num), denom);
	else 
		return Rational((num*obj.denom+denom*obj.num), (denom*obj.denom));
}

Rational Rational::operator-(Rational & obj) {
	Rational c((-obj.num), obj.denom);
    return (*this)+c;
}

Rational Rational::operator*(Rational & obj) {
	return Rational((num*obj.num), (denom*obj.denom));
}

Rational Rational::operator/(Rational & obj) {
    Rational c(obj.denom, obj.num);
	return (*this)*c;
}

Rational & Rational::operator+=(Rational & obj) {
    *this = (*this)+obj;
	return *this;
}

Rational & Rational::operator-=(Rational & obj) {
	*this = (*this)-obj;
	return *this;
}

Rational & Rational::operator++(int a) {
    a=0;
	setNum(num+1);
	simplify();
	return *this;
}

Rational & Rational::operator++() {
	setNum(num+1);
	simplify();
	return *this;
}

Rational & Rational::operator--(int a) {
    a=0;
	setNum(num-1);
	simplify();
	return *this;
}

Rational & Rational::operator--() {
	setNum(num-1);
	simplify();
	return *this;
}

bool Rational::operator>(Rational & obj) {
	return asDouble()>obj.asDouble();
}

bool Rational::operator<(Rational & obj) {
    return asDouble()<obj.asDouble();
}

bool Rational::operator>=(Rational & obj) {
    return asDouble()>=obj.asDouble();
}

bool Rational::operator<=(Rational & obj) {
    return asDouble()<=obj.asDouble();
}

bool Rational::operator==(Rational & obj) {
    return asDouble()==obj.asDouble();
}

bool Rational::operator!=(Rational & obj) {
    return asDouble()!=obj.asDouble();
}

void Rational::simplify(){
	int g = gcd(abs(num), abs(denom));
	bool negative = num*denom<0;
	setNum((negative?num:abs(num))/g);
	setDenom((negative?denom:abs(denom))/g);
	if(denom<0&&num>=0){
		num=-num;
		denom=-denom;
	}
}

int Rational::gcd(int a, int b){
	int d = 0;
	while(a%2==0 and b%2==0){
		a/=2;
		b/=2;
		d++;
	}
	while(a!=b){
		if(a%2==0) a/=2;
		else if(b%2==0) b/=2;
		else if(a>b) a=((a-b)/2);
		else b=((b-a)/2);	
	}
	return (a*pow(2,d));
}

ostream& operator<<(ostream& os, const Rational& obj){
	os << "(" << obj.num;
	if(obj.denom!=1) os	<< "/" << obj.denom;
	os << ")";
	return os;
}

istream& operator>>(istream& is, Rational& obj){
	int num, denom;
	bool numNeg = false, denomNeg = false;
	if(is.peek()=='-'){ numNeg = true; is.ignore(); }
	is >> num;
	is.ignore();
	if(is.peek()=='-'){ denomNeg = true; is.ignore(); }
	is >> denom;
	obj.setNum(num);
	obj.setDenom(denom);
	return is;
}

Rational::~Rational() {
}

