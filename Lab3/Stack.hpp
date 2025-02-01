#include "Node.hpp"
#include <iostream>

using namespace std;

struct Stack{
    private:

        Node* top;
        int size;

    public:
        
        Stack(){
            top = nullptr;
            size = 0;
        }

        void push(int val){
            if (size > 0){
                Node* pushed = new Node(val);
                pushed->setNext(top);
                top = pushed;
                size++;
                cout << "Pushed " << val << " onto the stack." << endl;
            }
            else {
                top = new Node(val);
                size++;
                cout << "Pushed " << val << " onto the stack." << endl;
            }
        }

        void pop(){
            if (size > 0){
                Node* popped = top;
                if (size == 1){
                    top = nullptr;
                }
                else {
                    top = top->returnNext();
                }
                cout << "Popped " << popped->returnValue() << " from the stack." << endl;
                delete popped;
                popped = nullptr;
                size--;
            }
            else {
                cout << "Stack is empty. Cannot pop!" << endl;
            }
        }

        void printStack(){
            if (size == 0){
                cout << "Current Stack is empty." << endl;
                return;
            }
            else {
                cout << endl;
                cout << "Current Stack" << endl;

                Node* next = top->returnNext();

                cout << "Top: " << top->returnValue() << endl;
                while (next != nullptr){
                    cout << "     " << next->returnValue() << endl;
                    next = next->returnNext();
                }
            }
            cout << endl;
        }

        ~Stack(){
            cout << "Stack Deleted!" << endl;
            delete top;
            top = nullptr;
        }
};