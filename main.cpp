//Test file

#include <iostream>
#include <vector>
#include <queue>
#include "CurrencyFormatter.h"
#include "PrintMatrix.h"
#include "DoubleRound.h"
#include "RandomOperations.h"
#include "Division.h"
#include "Epoch.h"
#include "Complex.h"
#include "Rational.h"
#include "IntegerSet.h"
#include "Rectangle.h"
using namespace std;

int main(){

	double curr = 12345.98765;
	cout.precision(5);
	cout << "- Currency formatter test: " << endl;
	cout << fixed << curr << " -> " << currencyFormatter(curr, '$');

	int arr[12];
	for (int i = 0; i < 12; i++) arr[i]=(i+1);
	cout << "\n- Matrix print test: " << endl;
	printMatrix(arr, 4, 3);
	
	double doub = 1446.65443; 
	cout << "\n- Double round test: " << endl;
	cout <<  doub << " -> " << doubleRound(doub) << endl;
	
	cout << "\n- Random operations test: " << endl;
	cout << "Random number from 1 to 100: " << rangeSelect<int>(1, 100) << endl;
	cout << "Random double: " << randDouble() << endl;
	vector<char> vec;
	for(char i = 65; i <= 90; i++) vec.push_back(i);
	cout << "Random char from vector: " << vecSelector(vec) << endl;
	cout << "Initial array: " << endl;
	for (unsigned i = 0; i < vec.size(); i++) cout << vec[i];
	cout << "\nShuffled array: " << endl;
	vecShuffle(vec);
	for (unsigned i = 0; i < vec.size(); i++) cout << vec[i];
	queue<char> que;
	for (unsigned i = 0; i < vec.size(); i++) que.push(vec.back());
	cout << "\nInitial queue: " << endl;
	queue<char> tmpQue = que;
	while(tmpQue.size() > 0){ cout << tmpQue.front(); tmpQue.pop();}
	randomQueue(que);
	tmpQue = que;
	cout << "\nRandomized queue: " << endl;
	while(tmpQue.size() > 0){ cout << tmpQue.front(); tmpQue.pop();}
	cout << endl;

	cout << "\n- Division quotient/remainder test: " << endl;
	divStr d = divide(256, 33);
	cout << "256/33=" << d.quotient << "*33+" << d.remainder << endl;

	cout << "\n- Time test: " << endl;
	Epoch ep(time(0), 2, true);
	cout << ep;

	cout << "\n- Complex number test: " << endl;
	Complex c1(-3,5);
	Complex c2(2,-8);
	cout.precision(0);
	cout << c1 << "+" << c2 << "=" << (c1+c2) << endl;
	cout << c1 << "-" << c2 << "=" << (c1-c2) << endl;
	cout << c1 << "*" << c2 << "=" << (c1*c2) << endl;
	cout << c1 << "/" << c2 << "=";
	cout.precision(3);
	cout << (c1/c2) << endl;
	cout.precision(0);
	cout << c1 << "==" << c2 << "=" << (c1==c2) << endl;
	cout << "~" << c1 << "=" << (~c1) << endl;
	
	cout << "\n- Rational number test: " << endl;
	Rational r1(-4,-8);
	Rational r2(2,-3);
	cout << "r1=" << r1 << endl;
	cout << "r2=" << r2 << endl;
	cout << r1 << " + " << r2 << " = " << (r1+r2) << endl;
	cout << r1 << " - " << r2 << " = " << (r1-r2) << endl;
	cout << r1 << " * " << r2 << " = " << (r1*r2) << endl;
	cout << r1 << " / " << r2 << " = " << (r1/r2) << endl;
	cout << r1 << " > " << r2 << " = " << (r1>r2) << endl;
	cout << r1 << " < " << r2 << " = " << (r1<r2) << endl;
	cout << r1 << " == " << r2 << " = " << (r1==r2) << endl;
	cout << r1 << " != " << r2 << " = " << (r1!=r2) << endl;
	cout << r1 << " ++= " << (r1++) << endl;
	cout << r2 << " --= " << (--r2) << endl;

	cout << "\n- Integer set test: " << endl;
	IntegerSet i1(50);
	IntegerSet i2(50);
	for(int i = 0; i <= 50; i+=2) i1.addElement(i);
	for (int i = 0; i <= 50; i+=3) i2.addElement(i);
	cout << "i1: " << i1;
	cout << "i2: " << i2;
	cout << "i1 + i2 = " << (i1+i2);
	cout << "i1 * i2 = " << (i1*i2);
	cout << "i1 == i2 = " << (i1==i2) << endl;
	
	cout << "\n- Rectangle test: " << endl;
	rPair tl, br;
	tl.x = 0; tl.y = 5;
	br.x = 7; br.y = 0;
	Rectangle rect(tl, br);
	cout << "Point coordinates: " << rect;
	cout << "Perimeter: " << rect.perimeter() << endl;
	cout << "Area: " << rect.area() << endl;
	cout << rect.draw();
	return 0;
}
