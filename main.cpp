#include <iostream>
#include <fstream>
#include <string>
#include "Shape.cpp"
#include "Point.cpp"
#include "Line.cpp"
#include "Triangle.cpp"
#include "Polygon.cpp"

int main(){
    float kV = 0;
    float deltaY = 0;
    float deltaX = 0;
    int kCalc = 0;
    int xK = 0;
    int yK = 1;
    float x = 0;
    std::string test;
    std::string test2;
    int coordCounter = 0;
    bool isLine = false;
    bool isPolygon = false;

    //Used for 3 decimal places
    std::cout.setf(std::ios::fixed,std::ios::floatfield);
    std::cout.precision(3);

    std::ifstream file;
    file.open("shape.txt");

    if(file.is_open()){
        //while(std::getline(file, test)){
            while(file >> x){
                coordCounter++;
          //  }
        }
    }else{
        std::cout << "No file could be found." << std::endl;
    }

    std::cout <<"cc:" << coordCounter << '\n';
    std::cout <<"test:" << test << '\n';

    //check if the file contains to few coords
    if(coordCounter < 2 || coordCounter % 2 != 0){
        std::cout << "Too few coords, edit the shape.txt file." << std::endl;
        getchar();
        exit(EXIT_FAILURE);
    }

    float *coords = new float[coordCounter];
    float *xCoords = new float[coordCounter/2];
    float *yCoords = new float[coordCounter/2];
    float *kValue = new float[coordCounter/2]; 


    file.close();
    file.open("shape.txt");

    for(int i = 0; i < coordCounter; i++){
        file >> coords[i];
    }
    file.close();

    //std::cout << "Raw input:" << std::endl;
    for(int i = 0; i < coordCounter; i++){
        std::cout << coords[i] << " ";
    }

    //Split the coordinates into two seperate arrays
    for(int i=0; i < coordCounter/2; i++){
        xCoords[i] = coords[xK];
        yCoords[i] = coords[yK];
        yK += 2;
        xK += 2;
    }


    //Calculate incline
   for(int i = 0; i < (coordCounter/2)-1; i++){
        deltaY = (yCoords[i+1] - yCoords[i]);
        deltaX = (xCoords[i+1] - xCoords[i]);
        kV = (deltaY/deltaX);
        kValue[i] = kV;
        kCalc++;
    }


    //If there's only one k-value, it must be a line.
    if(kCalc == 1){
        isLine = true;
    }

    //Checks if incline-values are same. 
    //If they are, it's a line, else it's a polygon (or triangle).
    if(kCalc > 1){
        for(int i=0; i < kCalc-1; i++){
            if(kValue[i] == kValue[i+1]){
                isLine = true;
            }else{
                isLine = false;
                isPolygon = true;
            }
        }
    }

    //create all possible objects:
        Point point(coords, coordCounter); 
        Line line(coords, coordCounter);
        Triangle triangle(coords, coordCounter);
        Polygon polygon(coords, coordCounter);
    
    //point
    if(coordCounter/2 == 1){
        std::cout << "\nType: " << point.getType();
        std::cout << "\nArea: " << point.getArea();
        std::cout << "\nConvex: " << point.isConvex();
        point.position();
       // point.~Point();
    }
    
    //line
    if(isLine == true){
        std::cout << "\nType: " << line.getType();
        std::cout << "\nArea: " << line.getArea();
        std::cout << "\nConvex: " << line.isConvex();
        line.position();
        //line.~Line();
    }
    //triangle.
    if(isPolygon == true && coordCounter/2 == 3 && isLine == false){
        std::cout << "\nType: " << triangle.getType();
        std::cout << "\nArea: " << triangle.getArea();
        std::cout << "\nCircumference: " << triangle.circumference();
        std::cout << "\nConvex: " << triangle.isConvex();
        triangle.position();
        //triangle.~Triangle();
    }
    //polygon.
    if(isPolygon == true && coordCounter/2 > 3 && isLine == false){
        std::cout << "\nType: " << polygon.getType();
        std::cout << "\nArea: " << polygon.getArea();
        std::cout << "\nCircumference: " << polygon.circumference();
        std::cout << "\nPosition: " << polygon.position()[0] << ", " << polygon.position()[1];
        std::cout << "\nConvex: " << polygon.isConvex();
        //polygon.~Polygon();
    }

   coords[0] = 8;
   coords[1] = 3;
   coords[2] = 5;
   coords[3] = 7;
   coords[4] = 10;
   coords[5] = 9;
   coords[4] = 14;
   coords[5] = 2;

    Polygon nyP(coords, coordCounter);

    //polygon.operator+(coords);
   /*coords[0] = 8;
   coords[1] = 3;
   coords[2] = 5;
   coords[3] = 7;
   coords[4] = 10;
   coords[5] = 9;
   coords[6] = 12;
   coords[7] = 6;

    Point p2(coords, coordCounter);
    std::cout << '\n';
    std::cout << "p2 pos: " << p2.position()[0] << " " << p2.position()[1] << "\n";
    std::cout << "\nDist between p1 and p2: " << polygon.distance(p2);
    */

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