#include "Vector2d.h"

int Vector2d::_icount = 0;

Vector2d::Vector2d() : _x(0.0f), _y(0.0f) {
    _icount++;
}
Vector2d::Vector2d(float x, float y): _x(x), _y(y) {
    _icount++;
}

Vector2d::Vector2d(const Vector2d& copy) :_x(copy._x), _y(copy._y) {
    _icount++;
}

Vector2d Vector2d::operator+(const Vector2d& secondVector) {
    _x = _x + secondVector._x;
    _x = _y + secondVector._y;
    return Vector2d(_x, _y);
}
Vector2d Vector2d::operator-(const Vector2d& secondVector) {
    _x = _x - secondVector._x;
    _x = _y - secondVector._y;
    return Vector2d(_x, _y);
}

Vector2d::~Vector2d() {
    _icount--;
}

float Vector2d::operator()(){
    return static_cast<float>(sqrt(pow(_x, 2) + pow(_y, 2)));
}

float& Vector2d::operator[](int i) {
    return i > 0 ? _y : _x;
}

Vector2d& Vector2d::operator=(const Vector2d & vec2d) {
    _x = vec2d._x;
    _y = vec2d._y;

    return *this;
}

std::ostream& operator << (std::ostream & out, const Vector2d & vec2d) {
    out << "Output: {" << vec2d._x << "; " << vec2d._y << "}";
    return out;
}

Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector) {
    float x = leftVector._x + rightVector._x;
    float y = leftVector._y + rightVector._y;
    return Vector2d(x, y);
}

Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector) {
    float x = leftVector._x - rightVector._x;
    float y = leftVector._y - rightVector._y;
    return Vector2d(x, y);
}