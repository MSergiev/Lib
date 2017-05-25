#ifndef DIVISION_H
#define DIVISION_H

struct divStr{
	int quotient;
	int remainder;
};

template <class T>
divStr divide(T a, T b){
	divStr d;
	d.quotient = 0;
	while(a >= b){
		a-=b;
		d.quotient++;
	}
	d.remainder = a;
	return d;
}
#endif
