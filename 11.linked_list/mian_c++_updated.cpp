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
    LinkedList() { head = NULL; };

    LinkedList(int *arr, int size) {
        Node *newNode = new Node(arr[0]);
        head = newNode;
        Node *last = head;

        for (int i = 1; i < size; i++) {
            Node *newNode = new Node(arr[i]);

            last->next = newNode;
            last = newNode;
        }
    }

    int length() {
        Node *p = head;
        int len = 0;
        while (p) {
            len++;
            p = p->next;
        }
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

        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
    }
};

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    LinkedList a(arr, 5);
    // a.display();
    cout<<a.length();

    return 0;
}