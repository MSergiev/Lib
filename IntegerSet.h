#ifndef INTEGERSET_H
#define INTEGERSET_H

#include <iostream>
using std::ostream;
using std::istream;
using std::endl;

class IntegerSet{
public:
	IntegerSet(const int& size=0);
	void setSize(const int size);
	int getSize() const;
	void addElement(int element);
	void removeElement(int element);
	bool exists(const int element);
	IntegerSet operator+(IntegerSet& obj);
	IntegerSet operator*(IntegerSet& obj);
	bool operator==(IntegerSet& obj);
	friend ostream& operator<<(ostream& os, const IntegerSet& obj);
	friend istream& operator>>(istream& is, IntegerSet& obj);
	~IntegerSet();

private:
	int size;
	bool* set;
};

#endif
