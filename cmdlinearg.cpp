#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char* argv[])
{
    printf("\n");
    for(int i = 0; i < argc; i++)
    {
        cout << "arg" << i << ": " << strrev(argv[i]);
        cout << endl;
        printf("%c\n", argv[i][0]);
        printf("%s\n", argv[i]+1);
        printf("\n");
    }
    return 0;
}

//Answer to Question 3:
//The line printf("%c\n", argv[i][0]); outputs the first character of the string since string objects in C and C++ are treated as an array of
//characters. So doing argv[i][0] takes the first element of the argv[i] character array (which is actually the string) and prints it out.
//The line printf("%s\n", argv[i]+1); outputs the rest of the string without the first character since the way the strings are handled in the 
//main method is through using a char pointer to the very first character of each string. In C and C++, strings can be represented by a pointer
//to the first character in the array of characters of the string. As such, when argv[i]+1 is called, the pointer is moved to the character after
//the first one instead so what gets printed out is the rest of the string without the first character.