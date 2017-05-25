#ifndef DOUBLEROUND_H
#define DOUBLEROUND_H

#include <cmath>
#include <vector>
using std::vector;

//Double rounding function
double doubleRound(double num, 
		unsigned before = 2, unsigned after = 2){
//Handle whole part
	unsigned dec = num;
	num-=dec;
	vector<unsigned> digits;
	while(dec!=0){
		digits.push_back(dec%10);
		dec/=10;
	}
	before=digits.size()-before-1;
	unsigned decRight=0;
	for(unsigned i = 0; i < digits.size(); ++i)
		(i<before?decRight:dec)+=digits[i]*pow(10,i);

	decRight = (round(decRight/pow(10,before))*pow(10,before));
	dec+=decRight;
//Handle fraction part
	unsigned frac = round(num*pow(10,after));
	num = dec+(frac/pow(10, after));
	return num;
}

#endif
