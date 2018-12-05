#ifndef LINE_H
#define LINE_H
#include "Shape.h"
class Line : public Shape{
private:
    std::string type = "Line";
    float area = -1;
    float circum;
    float* xCoords;
    float* yCoords;
    int coordCounter;
    float centerCoords[2];
public:
    Line();
    Line(float*, int);
    std::string getType();
    float getArea();
    float circumference();
    float* position();
    bool isConvex();
    void operator=(const Line& a);
    void operator=(const Shape& a);
    ~Line();
};
#endif