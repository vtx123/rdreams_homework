#include "Vector2d.h"

int Vector2d::_icount = 0;

Vector2d::Vector2d() : _x(0.0f), _y(0.0f) {
    _icount++;
}
Vector2d::Vector2d(float x, float y) : _x(x), _y(y) {
    _icount++;
}

Vector2d::Vector2d(float x0, float y0, float x1, float y1) : _x(x1 - x0), _y(y1 - y0) {
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

float Vector2d::operator()() {
    return static_cast<float>(sqrt(pow(_x, 2) + pow(_y, 2)));
}

float& Vector2d::operator[](int i) {
    if (i <= 0)
    {
        return _x;
    }
    else
    {
        return _y;
    }
}

Vector2d& Vector2d::operator=(const Vector2d& vec2d) {
    if (_x != vec2d._x) {
        _x = vec2d._x;
    }
    if (_y != vec2d._y) {
        _y = vec2d._y;
    }

    return *this;
}

std::ostream& operator << (std::ostream& out, const Vector2d& vec2d) {
    out << "Output: {" << vec2d._x << "; " << vec2d._y << "}";
    return out;
}

std::istream& operator>>(std::istream& in, Vector2d& vec2d) {
    in >> vec2d._x >> vec2d._y;
    return in;
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

float Vector2d::magnitude() const {
    return static_cast<float>(sqrt(pow(_x, 2) + pow(_y, 2)));
}

float Vector2d::dotProduct(Vector2d& other) const 
{
    return _x * other._x + _y * other._y;
}

Vector2d Vector2d::negate() const 
{
    return Vector2d(_x * -1, _y * -1);
}

VectorRelativeState Vector2d::getRelativeState(const Vector2d& other) const 
{
    float dp = dotProduct(const_cast<Vector2d&>(other));

    if (_x == other._x && _y == other._y && magnitude() == other.magnitude()) {
        return VectorRelativeState::Identical;
    }
    if ( dp > 0) {
        return VectorRelativeState::coDirected;
    }
    if (dp == 0) {
        return VectorRelativeState::RightAngle;
    }
    if (dp < 0) {
        return VectorRelativeState::OppositeDirected;
    }
}

VectorRelativeState Vector2d::getRelativeState2(const Vector2d& other) const 
{
    float dot = _x * other._x + _y * other._y;
    float det = _x * other._y - _y * other._x;
    int angle = static_cast<int>(180 / 3.14 * atan2(det, dot));

    std::cout << "A cos = " << angle << std::endl;
    if (angle < 90 && angle > -90) {
        return VectorRelativeState::AcuteAngle;
    }
    else {
        return VectorRelativeState::ObtuseAngle;
    }
}

void Vector2d::scale(float factorX, float factorY) 
{
    _x *= factorX;
    _y *= factorY;
}

Vector3d::Vector3d() : _x(0), _y(0), _z(0)
{
}
Vector3d::Vector3d(float x, float y, float z) : _x(x), _y(y), _z(z)
{
}

std::ostream& operator << (std::ostream& out, const Vector3d& vec3d) {
    out << "Output: {" << vec3d._x << "; " << vec3d._y << "; " << vec3d._z << "}";
    return out;
}

Vector3d Vector3d::crossProduct(const Vector3d& other)
{
    float x = _y * other._z - _z * other._y;
    float y = _z * other._x - _x * other._z;
    float z = _x * other._y - _y * other._x;
    return Vector3d(x, y, z);
}