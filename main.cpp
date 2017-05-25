//Test file

#include <iostream>
#include <vector>
#include <queue>
#include "CurrencyFormatter.h"
#include "PrintMatrix.h"
#include "DoubleRound.h"
#include "RandomOperations.h"
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

	

	return 0;
}
