#include <iostream>

using namespace std;

struct IntNode {
    private:

        int value;
        IntNode* next;

    public:

        IntNode(int val){
            value = val;
            next = nullptr;
        }

        void setNext(IntNode* n){
            next = n;
        }

        int returnValue(){
            return value;
        }

        IntNode* returnNext(){
            return next;
        }

        ~IntNode(){
            delete next;
            cout << "Deleted Node with value " << value << endl;
            next = nullptr;
        }
        
};