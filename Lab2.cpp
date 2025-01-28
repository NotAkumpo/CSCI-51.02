#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
    int n = 0;

    cin >> n;

    string output = "(";
    string rest;
    char randomSpace[2];
    int var1;
    int var2;
    int agent = 1;

    for(int i=0; i<n; i++){
        cin >> var1 >> var2;
        fgets(randomSpace, 2, stdin);
        getline(cin, rest);
        output += to_string(var1) + ", " + to_string(var2) + ")";
        cout << "Agent#" << to_string(agent) << " is at " << output << endl;

        if (i < n-1){
            cout << "Says: " << rest << endl;
        }
        else {
            cout << "Says: " << rest;
        }
        
        output = "(";
        agent++;
    }

    return 0;
}