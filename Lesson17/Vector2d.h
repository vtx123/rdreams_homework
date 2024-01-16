#pragma once
#include <iostream>

class Vector2d {
    static int _icount;
public:
    Vector2d();
    Vector2d(float x, float y);
    Vector2d(const Vector2d& copy);
    Vector2d& operator=(const Vector2d &vec2d);
    Vector2d operator+(const Vector2d& secondVector);
    Vector2d operator-(const Vector2d& secondVector);
    friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector);
    friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector);
    friend std::ostream& operator<<(std::ostream& out, const Vector2d &vec2d);
    float operator()();
    float& operator[](int i);

    static int instanceCount()
    {
        return _icount;
    }

    ~Vector2d();
private:
    float _x;
    float _y;

};