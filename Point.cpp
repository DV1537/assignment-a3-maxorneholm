#include "Point.h"
#include <iostream>
#include <cmath>

Point::Point(){}

Point::Point(float* coords, int coordCounter){
        this->xCoords = new float[coordCounter/2];
        this->yCoords = new float[coordCounter/2];

        this->coordCounter = coordCounter;
        this->coords = coords;
        int yK = 1;
        int xK = 0;

        for(int i=0; i < coordCounter/2; i++){
            this->xCoords[i] = coords[xK];
            this->yCoords[i] = coords[yK];
            yK += 2;
            xK += 2;
        }
}

std::string Point::getType(){
    return type;
}

float Point::getArea(){
    return area;
}
float Point::circumference(){
    return 0;
}
float* Point::position(){
    centerCoords[0] = xCoords[0];
    centerCoords[1] = yCoords[0];
    return centerCoords;

}
bool Point::isConvex(){
    return 1;
}

void Point::operator=(const Point& a){
    this->xCoords = a.xCoords;
    this->yCoords = a.yCoords;
}

void Point::operator=(const Shape& a){
    std::cout << "\nNot possible with this shape.";
}

Point::~Point(){
    delete[] xCoords;
    delete[] yCoords;
    xCoords = NULL;
    yCoords = NULL;
}