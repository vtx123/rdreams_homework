#pragma once

class Rectangle {
public:
    Rectangle();
    Rectangle(float length, float height);
    ~Rectangle();

    float getArea();
    float getPerimeter();
private:
    float _length = 0.0;
    float _height = 0.0;
};