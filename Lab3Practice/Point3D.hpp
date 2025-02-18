#include <iostream>

using namespace std;

struct Point3D {
    int x;
    int y;
    int z;

    // Point3D(){
    //     x = 0;
    //     y = 0;
    //     z = 0;
    // }

    Point3D(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    // Point3D(int x, int y, int z){
    //     this->x = x;
    //     this->y = y;
    //     this->z = z;	
    // }

};

struct IntArray{
    int length;
    int* data;

    IntArray(int i){
        length = i;
        data = new int[i];
        for (int j = 0; j < i; j++){
            data[j] = j;
        }
    }

    ~IntArray(){
        cout << "Deleting IntArray" << endl;
        delete[] data;
    }
};