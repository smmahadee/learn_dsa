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

class QueueByDoublyLinkedList {
   private:
    Node* head;
    Node* tail;

   public:
    QueueByDoublyLinkedList() { head = NULL; }

    void push(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->prev = tail;
        tail->next = newNode;
        tail = tail->next;
    }

    void pop() {
        Node* deletedNode = head;
        head = head->next;

        if (head == NULL) {
            tail = NULL;
            delete deletedNode;
            return;
        }

        head->prev = NULL;
        delete deletedNode;
    }

    int front() {
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
};

int main() {
    QueueByDoublyLinkedList s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    // s.pop();

    // cout << s.front();

    while (!s.isEmpty()) {
        cout << s.front() << " ";
        s.pop();
    }

    return 0;
}