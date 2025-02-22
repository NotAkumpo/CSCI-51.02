#include <iostream>

using namespace std;

int dummy(int x, int y){

    // Base case, if either one is 0, just output 0
    if (x == 0 || y == 0){
        return 0;
    }

    // Set the multiplicand and multiplicator
    int multiplicand;
    int multiplicator;

    // Shift counter counts how many times to shift, base counter adds the rest
    int shiftCounter = 0;
    int baseCounter = 2;

    // Whichever is larger should be the one getting shifted and added for less operations
    if (x > y){
        multiplicand = x;
        multiplicator = y;
    }
    else {
        multiplicand = y;
        multiplicator = x;
    }

    // Set everything to positive
    if (multiplicand < 0){
        multiplicand = 0 - multiplicand;
    }
    if (multiplicator < 0){
        multiplicator = 0 - multiplicator;
    }

    int baseMultiplicand = multiplicand;

    while (baseCounter < multiplicator){
        shiftCounter++;
        baseCounter <<= 1;
    }

    baseCounter >>= 1;
    multiplicand <<= shiftCounter;

    for (int i=0; i < (multiplicator - baseCounter); i++){
        multiplicand += baseMultiplicand;
    }

    // Make it so that in the case of different signs, the multiplicator is the negative term
    // to make the shifts and adds work with these special cases
    if ( (x > 0 && y < 0) || (x < 0 && y > 0) ){
        multiplicand = 0 - multiplicand;
    }

    return multiplicand;

}

int main(){
    // Correct
    cout << dummy(666, -999) << endl;
    // Correct
    cout << dummy(0, 0) << endl;
    return 0;
}