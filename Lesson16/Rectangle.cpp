#include "Rectangle.h"

Rectangle::Rectangle() : _length(0), _height(0) {

}

Rectangle::Rectangle(float length, float height) : _length(length), _height(height) {

}

float Rectangle::getArea() {
    return _length * _height;
}

float Rectangle::getPerimeter() {
    return (_length + _height) * 2.f;
}

Rectangle::~Rectangle() {

}