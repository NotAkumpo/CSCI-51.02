#include <iostream>

using namespace std;

int dummy(int x, int y){

    // Base case, if either variable is 0, just output 0
    if (x == 0 || y == 0){
        return 0;
    }

    bool negative = false;
    // Use this boolean later to set number to appropriate sign
    if ( (x > 0 && y < 0) || (x < 0 && y > 0) ){
        negative = true;
    }

    // Make variables for the multiplicand and multiplicator
    int multiplicand;
    int multiplicator;
    int result = 0;

    // Set everything to positive, then fix sign at the end
    if (x < 0){
        x = -x;
    }
    if (y < 0){
        y = -y;
    }

    // Whichever is larger should be the one getting shifted and added for less operations
    if (x > y){
        multiplicand = x;
        multiplicator = y;
    }
    else {
        multiplicand = y;
        multiplicator = x;
    }
    
    // The algorithm used is an implementation of the Russian Peasant Algorithm, and it allows for multiplication 
    // of 2 numbers using only * 2 or /2, which is exactly what arithmetic shifts do
    while (multiplicator > 0){
        // If multiplicator is odd, add the multiplicand to the result
        if (multiplicator & 1){
            result += multiplicand;
        }
        // Shift multiplicand left by 1, which does a *2
        multiplicand <<= 1;
        // Shift multiplicator right by 1, which does a /2 floored
        multiplicator >>= 1;
    }


    if (negative){
        return -result;
    }

    return result;

}

int main(){
    // Correct
    cout << dummy(-666, 999) << endl;
    // Correct
    cout << dummy(0, 0) << endl;
    return 0;
}