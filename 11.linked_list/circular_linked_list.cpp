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

class c_linked_list {
   private:
    Node *head;

   public:
    c_linked_list() { head = head->next; };

    c_linked_list(int *arr, int size) {
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

    void display() {
        Node *p = head;

        do {
            cout << p->val << " ";
            p = p->next;
        } while (p != head);
    }

    void insertNode(int pos, int val) {
        Node *newNode = new Node(val);
        Node *p = head;

        if (pos == 0) {
            newNode->next = head;
            while (p->next != head) {
                p = p->next;
            }
            p->next = newNode;
            // If you want to move head also
            // head = newNode;
            return;
        }

        for (int i = 0; i < pos - 1; i++) {
            p = p->next;
        }

        newNode->next = p->next;
        p->next = newNode;
    }

    void delete_node(int pos) {
        if (pos < 0 || pos > this->length()) {
            cout << "Invalid position";
            return;
        }

        if (pos == 0) {
            Node *p = head;
            while (p->next != head) {
                p = p->next;
            }

            p->next = head->next;
            delete head;
            head = p->next;
        }
    }
};

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    c_linked_list a(arr, 5);

    cout << "Enter a position: ";
    int pos;
    cin >> pos;
    // cout << "Enter a value: ";
    // int val;
    // cin >> val;

    // a.insertNode(pos, val);
    a.delete_node(pos);
    a.display();
    // cout << a.length();

    return 0;
}