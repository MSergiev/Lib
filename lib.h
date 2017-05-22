//EGT required functions library

#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <sstream>
#include <deque>
#include <algorithm>
#include <cmath>
using std::string;
using std::stringstream;
using std::endl;
using std::deque;
using std::reverse;
using std::cout;
using std::endl;

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

//Array printing function
template <class T>
void printMatrix(T* arr, 
		const unsigned& cols=0,
		const unsigned& rows=1,
		const unsigned& spaces=1){

//Get max number of digits for spacing
	T* tmpPtr = arr;
	T largest = *arr, smallest = *arr;
	for (unsigned i = 0; i < rows*cols-1; i++){
		tmpPtr++;
		if(*tmpPtr > largest) largest = *tmpPtr;
		if(*tmpPtr < smallest) smallest = *tmpPtr;
	}
	
	unsigned countSmallest=(smallest<0?1:0), 
			 countLargest=0;
	smallest = abs(smallest);
	while(smallest!=0){
		countSmallest++;
		smallest/=10;
	}
	while(largest!=0){
		countLargest++;
		largest/=10;
	}
	unsigned spaceMod = (countSmallest>countLargest?countSmallest:countLargest);

//Formatter
	for(unsigned i = 0; i < rows; ++i){
		for(unsigned j = 0; j < cols; j++){
			T tmp = *arr;
			unsigned digitCount = (tmp<0?1:0);
			while(tmp!=0){
				digitCount++;
				tmp/=10;
			}
			cout << *arr;
			arr++;
			if(j!=cols-1)
				for(unsigned k = 0; k < spaceMod-digitCount+spaces; k++)
					cout << " ";
		}
		if(i!=rows-1)
			for(unsigned k = 0; k < spaces+1; k++)
				cout << endl;
	}
	cout << endl;
}

#endif
