//Test file

#include <iostream>
#include "lib.h"
using namespace std;

int main(){
	cout << "Currency formatter test: ";
	cout << currencyFormatter(12345.98765, '$');
	return 0;
}
