#include <iostream>

using namespace std;

class Node {
   public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class StackByDoublyLinkedList {
   private:
    Node* head;
    Node* tail;

   public:
    StackByDoublyLinkedList() { head = NULL; }

    void push(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->prev = tail;
        newNode->next = tail->next;
        tail->next = newNode;
    }

    void pop() {
        Node* deletedNode = tail;
        tail = tail->prev;
        delete deletedNode;

        if (tail == NULL) {
            head = NULL;
        } else {
            tail->next = NULL;
        }
    }

    int top() {
        int el = -1;

        if (head != NULL) {
            el = tail->val;
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
};

int main() {
    StackByDoublyLinkedList s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.pop();

    cout<<s.top();

    // while (!s.isEmpty()) {
    //     cout << s.top() << " ";
    //     s.pop();
    // }

    return 0;
}