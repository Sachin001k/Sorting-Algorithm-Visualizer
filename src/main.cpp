#include<iostream>
#include "Location.h"

using namespace std;

int main(){
    Location a(2.0, 2.0);
    Location b(5.0, 5.0);

    cout<<"a distance: "<<a.distance(b)<<endl;

}