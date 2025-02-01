#include "Stack.hpp"

int main(void){

    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.pop();
    s.printStack();
    s.push(20);
    s.push(25);
    s.printStack();

    Stack y;
    y.printStack();

    Stack z;
    z.push(1);
    z.push(2);
    z.push(3);
    z.push(4);
    z.push(5);
    z.push(6);
    z.push(7);
    z.push(8);
    z.push(9);
    z.push(10);
    z.pop();
    z.pop();
    z.pop();
    z.pop();
    z.pop();
    z.printStack();

    Stack a;
    a.push(1);
    a.pop();
    a.printStack();

    return 0;
}