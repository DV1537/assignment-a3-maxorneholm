#ifndef POLYGON_H
#define POLYGON_H
#include "Shape.h"

class Polygon : public Shape{
private:
    std::string type = "Polygon";
    float area = 0;
    float circum;
    int coordCounter;
    float* xCoords;
    float* yCoords;
    float* kValue;
    bool convexReturn = false;
    float center;
    float centerCoords[2];

public:
    Polygon();
    Polygon(float*, int);
    std::string getType();
    float getArea();
    float circumference();
    float* position();
    bool isConvex();
    void operator=(const Polygon& a);
    void operator=(const Shape& a);
    void operator+(const Shape& a);
    ~Polygon();
};
#endif