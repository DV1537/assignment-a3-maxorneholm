#ifndef SHAPE_H
#define SHAPE_H

#include <string>


class Shape{
protected:
    std::string type;
    float area = 10;
    float circum;
    Shape* a;
    float *xCoords;
    float *yCoords;
    int coordCounter;
    float* coords;
public: 
    //virtual ~Shape();
    virtual std::string getType() = 0;
    virtual float getArea() = 0;
    virtual float circumference() = 0;
    virtual float* position() = 0;
    virtual bool isConvex() = 0;
    float distance(Shape& a);
    //a3
    virtual void operator=(Shape& a); 
    
};
#endif