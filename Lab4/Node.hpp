
struct Node {
    private:

        int value;
        Node* next;

    public:

        Node(int val){
            value = val;
            next = nullptr;
        }

        void setNext(Node* n){
            next = n;
        }

        int returnValue(){
            return value;
        }

        Node* returnNext(){
            return next;
        }

        ~Node(){
            // delete next;
            next = nullptr;
        }
        
};