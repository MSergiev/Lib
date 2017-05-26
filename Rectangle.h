#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <sstream>
#include <cmath>
using std::ostream;
using std::endl;
using std::string;
using std::stringstream;

struct rPair{
	int x = 0, y = 0;
};

class Rectangle{
public:
	Rectangle(const rPair& topLeft, const rPair& bottomRight);
	void setBottomLeft(const rPair bottomLeft);
	void setTopLeft(const rPair topLeft);
	void setBottomRight(const rPair bottomRight);
	void setTopRight(const rPair topRight);
	rPair getBottomLeft() const;
	rPair getTopLeft() const;
	rPair getBottomRight() const;
	rPair getTopRight() const;
	void calculateLength();
	bool isSquare() const;
	int perimeter() const;
	int area() const;
	string draw() const;
	friend ostream& operator<<(ostream& os, const Rectangle& obj);
	~Rectangle();

private:
	rPair bottomLeft;
	rPair topLeft;
	rPair bottomRight;
	rPair topRight;
	rPair length;
};

#endif
