#include <iostream>

using namespace std;

class Node {
   public:
    int val;
    Node *next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList {
   private:
    Node *head;

   public:
    LinkedList() { head = head->next; };

    LinkedList(int *arr, int size) {
        Node *newNode = new Node(arr[0]);
        head = newNode;
        head->next = head;
        Node *last = head;

        for (int i = 1; i < size; i++) {
            Node *newNode = new Node(arr[i]);

            last->next = newNode;
            last = newNode;
            last->next = head;
        }
    }

    int length() {
        Node *p = head;
        int len = 0;

        do {
            len++;
            p = p->next;
        } while (p != head);

        return len;
    }

    void insertNode(int val) {
        Node *newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node *p = head;
        while (p->next != NULL) {
            p = p->next;
        }

        p->next = newNode;
    }

    void display() {
        Node *p = head;

        do {
            cout << p->val << " ";
            p = p->next;
        } while (p != head);
    }
};

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    LinkedList a(arr, 5);
    // a.display();
    cout << a.length();

    return 0;
}