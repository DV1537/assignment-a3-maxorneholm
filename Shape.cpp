#include "Shape.h"
#include <iostream>
#include <cmath>

 
float Shape::distance(Shape& a){

    //this->position för första objektet.
    //a.position för andra objektet.

    float distance = 0;
    float x0a = this->position()[0];
    float x0b = a.position()[0];
    float y0a = this->position()[1];
    float y0b = a.position()[1];

    float x = pow(x0a-x0b,2);
    float y = pow(y0a-y0b,2);

    distance = sqrt(x+y);

    return distance;

}

void Shape::operator=(Shape& a){
    
}