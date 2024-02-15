#pragma once
#include <iostream>

enum class VectorRelativeState
{
    Identical,
    coDirected,
    OppositeDirected,
    AcuteAngle,
    ObtuseAngle,
    RightAngle
};

inline std::string relativeToStr(VectorRelativeState vrs) {
    switch (vrs)
    {
    case VectorRelativeState::Identical:
        return "Identical";
        break;
    case VectorRelativeState::coDirected:
        return "coDirected";
        break;
    case VectorRelativeState::OppositeDirected:
        return "OppositeDirected";
        break;
    case VectorRelativeState::AcuteAngle:
        return "AcuteAngle";
        break;
    case VectorRelativeState::ObtuseAngle:
        return "ObtuseAngle";
        break;
    case VectorRelativeState::RightAngle:
        return "RightAngle";
        break;
    default:
        return "WOW-WOW smth went wrong in funciton relativeToStr()";
        break;
    }
}

class Vector2d {
    static int _icount;
public:
    Vector2d();
    Vector2d(float x, float y);
    Vector2d(const Vector2d& copy);
    Vector2d(float x0, float y0, float x1, float y1);
    Vector2d& operator=(const Vector2d& vec2d);
    Vector2d operator+(const Vector2d& secondVector);
    Vector2d operator-(const Vector2d& secondVector);
    friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector);
    friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector);
    friend std::ostream& operator<<(std::ostream& out, const Vector2d& vec2d);
    friend std::istream& operator>>(std::istream& in, Vector2d& vec2d);
    float operator()();
    float& operator[](int i);
    float magnitude() const;
    float dotProduct(Vector2d& other) const;
    Vector2d negate() const;
    VectorRelativeState getRelativeState(const Vector2d& other) const;
    VectorRelativeState getRelativeState2(const Vector2d& other) const;
    void scale(float factorX, float factorY);

    static int instanceCount()
    {
        return _icount;
    }

    ~Vector2d();
private:
    float _x;
    float _y;

};

class Vector3d
{
public:
    Vector3d();
    Vector3d(float x, float y, float z);
    Vector3d crossProduct(const Vector3d& other);
    friend std::ostream& operator<<(std::ostream& out, const Vector3d& vec3d);
private:
    float _x;
    float _y;
    float _z;
};