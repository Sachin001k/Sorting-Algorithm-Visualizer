#pragma once //header guard prevents the header file to be included in same files multiple times
#include <cmath>

struct Location{ //struct is like a class biut with members are by default public
    double x;
    double y;
    //construtor
    Location(double a=0, double b=0){
        x = a;
        y = b;
    }
       

    double distance(const Location& other) const{
        return sqrt((x-other.x)*(x-other.y) + (y-other.y)*(y-other.y));
    }
};

