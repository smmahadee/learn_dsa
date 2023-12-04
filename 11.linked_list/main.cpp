#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node * next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void create_node_at_tail(Node *&head, int data) {
    Node * newNode = new Node(data);
    
    if(head == NULL) {
        head = newNode;
        cout<<"Inserted at head."<<endl;
        return;
    }

    while(head != NULL) {
        head = head->next;
    }

    
}

int main() {
    while (true)
    {
        Node *head = NULL;

        cout<<endl<<"0. Terminate program"<<endl;
        cout<<"1. create a node."<<endl;
        cout<<"2. create multiple node."<<endl;

        int op;
        cin>>op;

        switch (op)
        {
        case 0:
            break;
        case 1: 

        
        default:
            break;
        }

        
    }
    

    return 0;
}