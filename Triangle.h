#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape{
private:
    std::string type = "Triangle";
    float area = 0;
    float circum;
    float* xCoords;
    float* yCoords;
    float distanceAtoB = 0, distanceAtoC = 0, distanceBtoC = 0;
    float hypo = 0, base = 0, height = 0, circumFormula = 0;
    float centerCoords[2];

public:
    Triangle();
    Triangle(float*, int);
    std::string getType();
    float getArea();
    float circumference();
    float* position();
    bool isConvex();
    void operator=(const Triangle& a);
    void operator=(const Shape& a);
    ~Triangle();
};
#endif