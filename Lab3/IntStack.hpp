#include "IntNode.hpp"
#include <iostream>

using namespace std;

struct IntStack{
    private:

        IntNode* top;
        int size;

    public:
        
        IntStack(){
            top = nullptr;
            size = 0;
        }

        void push(int val){
            if (size > 0){
                IntNode* pushed = new IntNode(val);
                pushed->setNext(top);
                top = pushed;
                size++;
                cout << "-> " << val << " was PUSHED onto the stack." << endl;
            }
            else {
                top = new IntNode(val);
                size++;
                cout << "-> " << val << " was PUSHED onto the stack." << endl;
            }
        }

        void pop(){
            if (size > 0){
                IntNode* popped = top;
                if (size == 1){
                    top = nullptr;
                }
                else {
                    top = top->returnNext();
                }
                cout << "<- " << popped->returnValue() << " was POPPED from the stack." << endl;
                operator delete(popped);
                popped = nullptr;
                size--;
            }
            else {
                cout << "Stack is empty. Cannot pop!" << endl;
            }
        }

        void printStack(){
            if (size == 0){
                cout << endl;
                cout << "Current Stack is empty." << endl;
            }
            else {
                cout << endl;
                cout << "Current Stack" << endl;

                IntNode* next = top->returnNext();

                cout << "Top: " << top->returnValue() << endl;
                while (next != nullptr){
                    cout << "     " << next->returnValue() << endl;
                    next = next->returnNext();
                }
            }
            cout << endl;
        }

        ~IntStack(){
            delete top;
            top = nullptr;
            cout << "Stack Deleted!" << endl;
            cout << endl;
        }
};