#include "IntStack.hpp"

int main(void){

    cout << endl;

    IntStack* a = new IntStack();
    a->push(5);
    a->push(10);
    a->push(15);
    a->push(20);
    a->push(25);
    a->pop();
    a->printStack();
    a->push(30);
    a->pop();
    a->push(35);
    a->printStack();
    delete a;

    IntStack* b = new IntStack();
    b->pop();
    b->printStack();
    b->push(1);
    b->push(2);
    b->push(3);
    b->push(4);
    b->push(5);
    b->pop();
    b->pop();
    b->pop();
    b->pop();
    b->pop();
    b->pop();
    b->printStack();
    delete b;

    IntStack* c = new IntStack();
    c->push(-12345);
    c->push(45678);
    c->push(0);
    c->push(999);
    c->pop();
    c->printStack();
    delete c;

    return 0;
}