#include <iostream>

using namespace std;

int dummy(int x, int y){

    if (x == 0 || y == 0){
        return 0;
    }

    int cand;
    int cator;

    if (x > y){
        cand = x;
        cator = y;
    } 
    else {
        cand = y;
        cator = x;
    }

    int counter = 2;
    int shift = 0;

    while (counter <= cator){
        shift++;
        counter <<= 1;
    }

    int remainder = y - counter;

    int base = cand;
    cand <<= shift;

    for (int i = 0; i < remainder; i++){
        cand += base;
    }

    return cand;
}

int main(){
    cout << dummy(14, 13);
    return 0;
}