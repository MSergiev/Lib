//Test file

#include <iostream>
#include "lib.h"
using namespace std;

int main(){
	cout << "Currency formatter test: ";
	cout << currencyFormatter(12345.98765, '$');
	int arr[12];
	for (int i = 0; i < 12; i++) arr[i]=(i+1);
	cout << "Matrix print test: " << endl;
	printMatrix(arr, 4, 3);
	
	return 0;
}
