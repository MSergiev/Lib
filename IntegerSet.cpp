#include "IntegerSet.h"

IntegerSet::IntegerSet(const int & size):set(new bool[size+1]) {
	for (int i = 0; i <= size; i++) set[i] = false;	
	setSize(size);
}

void IntegerSet::setSize(const int size) {
	this->size=size;
}

int IntegerSet::getSize() const {
    return size;
}

void IntegerSet::addElement(int element) {
	if(element<=size) set[element]=true;
}

void IntegerSet::removeElement(int element) {
	if(element<=size) set[element]=false;
}

bool IntegerSet::exists(const int element) {
    if(element<=size) return set[element];
	return false;
}

IntegerSet IntegerSet::operator+(IntegerSet & obj) {
    int s = (size>obj.size?size:obj.size);
	IntegerSet c(s);
	for(int i = 0; i <= s; i++)
		c.set[i]=(set[i]|obj.set[i]);	
	return c;
}

IntegerSet IntegerSet::operator*(IntegerSet & obj) {
	int s = (size<obj.size?size:obj.size);
    IntegerSet c(s);
	for(int i = 0; i <= s; i++)
		c.set[i]=(set[i]&obj.set[i]);	
	return c;
}

bool IntegerSet::operator==(IntegerSet & obj) {
    for(int i = 0; i < size; i++)
		if(set[i]!=obj.set[i]) return false;
    return true;
}

ostream & operator<<(ostream & os, const IntegerSet & obj) {
    for (int i = 0; i <= obj.size; i++)
		if(obj.set[i]) os << i << " ";
	os << endl;
	return os;
}

istream & operator>>(istream & is, IntegerSet & obj) {
    int tmp;
	while(!is.eof()){
		is >> tmp;
		obj.addElement(tmp);
		is.ignore();
	}
	return is;
}

IntegerSet::~IntegerSet() {
	delete[] set;
}

