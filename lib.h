//EGT required functions library

#ifndef LIB_H
#define LIB_H

#include <sstream>
#include <deque>
#include <algorithm>
#include <cmath>
using std::string;
using std::stringstream;
using std::endl;
using std::deque;
using std::reverse;

//Currency formatter function
string currencyFormatter(double value, const char symbol){
	//Handle decimal part
	stringstream str;
	int dec = value;
	value-=dec;
	deque<unsigned> digits;
	while(dec!=0){
		digits.push_back(dec%10);
		dec/=10;
	}
	int count=0;
	str << symbol;
	//Position formatting commas
	stringstream tmp;
	while(!digits.empty()){
		tmp << digits.front();
		digits.pop_front();
		count++;
		if(count==3){
		tmp << ",";
		count = 0;
		}
	}
	//Reverse string
	string rev = tmp.str();
	reverse(rev.begin(), rev.end());
	str << rev;

	//Handle decimal part
	value*=100;
	value = round(value);
	dec = value;
	if(value!=0) str << "." << dec;
	str << endl;
	return str.str();
}

#endif
