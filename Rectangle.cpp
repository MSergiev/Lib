#include "Rectangle.h"

Rectangle::Rectangle(const rPair & topLeft, const rPair & bottomRight) {
	setTopLeft(topLeft);
	setBottomRight(bottomRight);
	rPair bottomLeft, topRight;
	bottomLeft.x = topLeft.x;
	bottomLeft.y = bottomRight.y;
	topRight.x = bottomRight.x;
	topRight.y = topLeft.y;
	setTopRight(topRight);
	setBottomLeft(bottomLeft);
	calculateLength();
}

void Rectangle::setBottomLeft(const rPair bottomLeft) {
	this->bottomLeft=bottomLeft;
}

void Rectangle::setTopLeft(const rPair topLeft) {
	this->topLeft=topLeft;
}

void Rectangle::setBottomRight(const rPair bottomRight) {
	this->bottomRight=bottomRight;
}

void Rectangle::setTopRight(const rPair topRight) {
	this->topRight=topRight;
}

rPair Rectangle::getBottomLeft() const {
    return bottomLeft;
}

rPair Rectangle::getTopLeft() const {
    return topLeft;
}

rPair Rectangle::getBottomRight() const {
    return bottomRight;
}

rPair Rectangle::getTopRight() const {
    return topRight;
}

void Rectangle::calculateLength() {
	length.x = abs(bottomLeft.x - bottomRight.x);
	length.y = abs(topLeft.y - bottomLeft.y);
}

bool Rectangle::isSquare() const {
	if(length.x==length.y) return true;
	return false;
}

int Rectangle::perimeter() const {
	return (length.x*2+length.y*2);
}

int Rectangle::area() const {
	return length.x*length.y;
}

string Rectangle::draw() const {
	stringstream str;
	for(int i = 0; i <= length.y; i++){
		for(int j = 0; j <= length.x; j++){
			if(i==0){
				if(j==0) str << "┌";
				else if(j==length.x) str << "┐";
				else str << "─";
			} else if(i==length.y){
				if(j==0) str << "└";
				else if(j==length.x) str << "┘";
				else str << "─";
			}
			else {
				if(j==0 || j==length.x) str << "│";
				else str << " ";
			}
		}
		str << endl;
	}
	return str.str();
}

ostream & operator<<(ostream & os, const Rectangle & obj) {
    os << "(" << obj.topLeft.x << ", " << obj.topLeft.y << ") ";
	os << "(" << obj.bottomLeft.x << ", " << obj.bottomLeft.y << ") ";
	os << "(" << obj.bottomRight.x << ", " << obj.bottomRight.y << ") ";
	os << "(" << obj.topRight.x << ", " << obj.topRight.y << ")\n";
	return os;
}

Rectangle::~Rectangle() {

}

