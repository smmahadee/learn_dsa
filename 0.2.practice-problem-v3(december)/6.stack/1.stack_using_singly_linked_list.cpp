#include <iostream>

using namespace std;

class Node {
   public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class StackBySinglyLinkedList {
   private:
    Node* head;
    Node* tail;

   public:
    StackBySinglyLinkedList() { head = NULL; }

    void push(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    int pop() {
        int el = -1;

        if (head != NULL) {
            el = head->val;
            Node* deletedNode = head;
            head = head->next;
            delete deletedNode;
        }

        return el;
    }

    int top() {
        int el = -1;

        if (head != NULL) {
            el = head->val;
        }

        return el;
    }

    int size() {
        int len = 0;
        Node* p = head;
        while (p != NULL) {
            len++;
            p = p->next;
        }

        return len;
    }

    bool isEmpty() {
        if (size() == 0) {
            return true;
        } else {
            return false;
        }
    }

    void display() {
        Node* p = head;
        while (p != NULL) {
            cout << p->val << " ";
            p = p->next;
        }
    }
};

int main() {
    StackBySinglyLinkedList s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.pop();
    s.display();
    return 0;
}