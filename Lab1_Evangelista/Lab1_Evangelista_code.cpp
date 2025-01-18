#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void incrementLetter(char* c){
    if (*c == 'z'){
        *c = 'a';
    }
    else if (*c == 'Z'){
        *c = 'A';
    }
    else if (isalpha(*c)){
        *c = *c + 1;
    }
}

int main(void){
    string name;
    cout << "1. Enter your name: ";

    getline(cin, name);
    cout << "2. Here's your name: " << name << endl;

    cout << "3. Your name with hashtags: " << name[0];
    for (int i=1; i<name.length(); i++){
        cout << "#";
    }
    printf("\n");

    cout << "4. Your name incremented by a letter: ";
    for(char c : name){
        char nextletter;
        if (c == 'z'){
            nextletter = 'a';
        }
        else if (c == 'Z'){
            nextletter = 'A';
        }
        else if (isalpha(c)){
            nextletter = c + 1;
        }
        else {
            nextletter = c;
        }
        cout << nextletter;
    }
    printf("\n");

    for( int i=0; i<name.length(); i++){    
        incrementLetter(&name[i]);
    }
    cout << "5. Your name incremented by a letter but using a function: " << name << endl;
    
    return 0;
}