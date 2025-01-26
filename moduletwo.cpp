#include <iostream>
#include <cstdio>

using namespace std;

// int main(void){
//     char s[80];
//     // string s;
//     cout << "Enter a string: ";
//     // scanf("%s", s);
//     // cin >> s;
//     fgets(s, 80, stdin);
//     printf("You entered: %s\n", s);
//     // cout << s;
//     return 0;
// }

// int main(void){
//     int i;
//     char c;
//     float f;

//     cin >> i >> c >> f;
//     cout << "Read: " << i << ", " << c << ", " << f << endl;
//     return 0;
// }

// int main(void){
//     int i;
//     char c;
//     float f;

//     scanf("%d %c %f", &i, &c, &f);
//     printf("Read: %d, %c, %f\n", i, c, f);
//     // cout << i;
//     // cout << c;
//     // cout << f;
//     return 0;
// }

// int main(void){
//     int i;
//     int j;
    
//     cout << "Enter two numbers: ";
//     int ret = scanf("%d %d", &i, &j);
//     cout << "scanf() returned: " << ret << endl;
//     cout << "Checking i: " << i << endl;
//     cout << "Checking j: " << j << endl;
    
//     return 0;
// }

// int main(void){
//     int i;
//     string s;

//     cin >> s;

//     i = atoi(s.c_str());
//     cout << "Converted: " << i << endl;

//     return 0;
// }

int main(void){
    int age;
    string s = "John Doe, Age ";

    cin >> age;
    char numStr[10];
    
    sprintf( numStr, "%d", age );
    s += numStr;
    cout << s << endl;
}


// int main(void){
//     int i;

//     cin >> i;
//     // getline(cin, i);
//     cout << i;

//     return 0;
// }