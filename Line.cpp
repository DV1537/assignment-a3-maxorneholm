#include "Line.h"

Line::Line(){}

Line::Line(float* coords, int coordCounter){
        this->xCoords = new float[coordCounter/2];
        this->yCoords = new float[coordCounter/2];
        this->coordCounter = coordCounter;
        int yK = 1;
        int xK = 0;

        for(int i=0; i < coordCounter/2; i++){
            this->xCoords[i] = coords[xK];
            this->yCoords[i] = coords[yK];
            yK += 2;
            xK += 2;
        }
}

std::string Line::getType(){
    return type;
}

float Line::getArea(){
    return area;
}

float Line::circumference(){
    return circum;
}

float* Line::position(){
    float x = 0 , y = 0;
    for (int i=0; i < coordCounter/2 ;i++){
        x += xCoords[i];
        y += yCoords[i];
    }
    x /= coordCounter/2;
    y /= coordCounter/2;
    centerCoords[0] = x;
    centerCoords[1] = y;
    return centerCoords;
}
bool Line::isConvex(){
    return 1;
}

void Line::operator=(const Line& a){
    this->xCoords = a.xCoords;
    this->yCoords = a.yCoords;
}

void Line::operator=(const Shape& a){
    std::cout << "\nNot possible with this shape.";
}

Line::~Line(){
    delete[] xCoords;
    delete[] yCoords;
    xCoords = NULL;
    yCoords = NULL;
}