#include <iostream>
#include <fstream>
#include <string>
#include "Shape.cpp"
#include "Point.cpp"
#include "Line.cpp"
#include "Triangle.cpp"
#include "Polygon.cpp"
#include <sstream>

int main(){
    float kV = 0;
    float deltaY = 0;
    float deltaX = 0;
    int kCalc = 0;
    int xK = 0;
    int yK = 1;
    float x = 0;
    float x2 = 0;
    std::string line = "";
    std::string line2 = "";
    int coordCounter = 0;
    int coordCounter2 = 0;
    bool isLine = false;
    bool isPolygon = false;

    //Used for 3 decimal places
    std::cout.setf(std::ios::fixed,std::ios::floatfield);
    std::cout.precision(3);

    std::ifstream file;
    file.open("shape.txt");

    std::getline(file, line);
    std::stringstream stream (line);
    while(stream >> x){
            coordCounter++;
    }
    
    std::getline(file, line2);
    std::stringstream stream2 (line2);
    while(stream2 >> x){
            coordCounter2++;
    }


    //check if the file contains to few coords
    if(coordCounter < 2 || coordCounter % 2 != 0){
        std::cout << "Too few coords, edit the shape.txt file." << std::endl;
        getchar();
        exit(EXIT_FAILURE);
    }

    float *coords = new float[coordCounter];
    float *coords2 = new float[coordCounter];
    float *xCoords = new float[coordCounter/2];
    float *yCoords = new float[coordCounter/2];
    float *kValue = new float[coordCounter/2]; 


    file.close();
    file.open("shape.txt");

    for(int i = 0; i < coordCounter; i++){
        file >> coords[i];
    }
    for(int i=0; i < coordCounter2; i++){
        file >> coords2[i];
    }
    file.close();
    
    Polygon polygon1(coords, coordCounter);
    Polygon polygon2(coords2, coordCounter2);


    Polygon p3 = polygon1 + polygon2;

    for(int i = 0; i < coordCounter; i++){
       std::cout << coords[i] << " "; 
    }
    std::cout << '\n';
    for(int i = 0; i < coordCounter2; i++){
       std::cout << coords2[i] << " "; 
    }
    
    std::cout << '\n' << p3.getArea();
   // std::cout << p3;


    delete[] coords;
    delete[] xCoords;
    delete[] yCoords;
    delete[] kValue;

    coords = NULL;
    xCoords = NULL;
    yCoords = NULL;
    kValue = NULL;

    std::cout << '\n';
    getchar();
    return 0;
}