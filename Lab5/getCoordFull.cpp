#include <iostream>
using namespace std;

struct Point3D{
    int x;
    int y;
    int z;
};

int getCoord (Point3D p){
    return p.x;
}

int main(void){
    Point3D p;
    p.x = 5;
    p.y = 7;
    p.z = -2;
    cout << getCoord(p) << endl;
    return 0;
}