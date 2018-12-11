#ifndef POINT_H
#define POINT_H

#include "Shape.h"
class Point : public Shape{
public:
    std::string type = "Point";
    float area = -1;
    float circum;
    float* xCoords;
    float* yCoords;
    int coordCounter;
    float* coords;
    float centerCoords[2];
public:
    Point();
    Point(float*, int);
    std::string getType();
    float getArea();
    float circumference();
    float* position();
    bool isConvex();
    void operator=(const Point& a);
    void operator=(const Shape& a);
    ~Point();
};

#endif