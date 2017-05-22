//Test file

#include <iostream>
#include "CurrencyFormatter.h"
#include "PrintMatrix.h"
#include "DoubleRound.h"
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
	
	double doub = 98765.98765; 
	cout << "\n- Double round test: " << endl;
	cout <<  doub << " -> " << doubleRound(doub) << endl;
	
	return 0;
}
