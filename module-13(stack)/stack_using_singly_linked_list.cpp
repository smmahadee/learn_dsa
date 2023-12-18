#include <iostream>

using namespace std;

// stack using singly linked list

class Node {
   public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class StackSinglyLinkedList {
   private:
    Node* top;

   public:
    StackSinglyLinkedList() { top = NULL; }
    
    void create() {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            push(val);
        }
    }

    void push(int val) {
        Node* newNode = new Node(val);

        if (top == NULL) {
            top = newNode;
            return;
        }

        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == NULL) {
            return -1;
        }
        Node* returnedNode = top;
        Node* deletedNode = top;

        top = top->next;
        delete deletedNode;
        return returnedNode->val;
    }

    int stackTop() {
        if (top == NULL) {
            return -1;
        } else {
            return top->val;
        }
    }

    int peek(int pos) {
        int x = -1;
        Node* p = top;

        for (int i = 0; p != NULL && i < pos - 1; i++) {
            p = p->next;
        }
        if (p != NULL) {
            x = p->val;
        }
        return x;
    }

    bool isEmpty() { return top == NULL ? true : false; }

    bool isFull() {
        Node* newNode = new Node(10);
        if (newNode) {
            return false;
        } else {
            return true;
        }

        delete newNode;
    }

    // this code not necessary , follow above code
    // int size() {
    //     int len = 0;
    //     Node* p = top;
    //     while (p != NULL) {
    //         len++;
    //         p = p->next;
    //     }

    //     return len;
    // }
};

int main() {
    StackSinglyLinkedList s;
    s.create();
    // s.push(10);
    // s.push(20);
    // s.push(40);
    // s.pop();
    // s.pop();
    cout << s.stackTop();

    return 0;
}