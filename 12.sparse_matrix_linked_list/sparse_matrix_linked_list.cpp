#include <iostream>

using namespace std;

class Node {
   public:
    int col;
    int value;
    Node* next;

    Node() { next = NULL; }

    Node(int col, int value) {
        this->col = col;
        this->value = value;
        this->next = NULL;
    }
};

void insert_at_tail(Node*& head, Node* newNode) {
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = newNode;
}

void print_list(Node* head) {
    while (head != NULL) {
        cout << head->col << " " << head->value << " " << endl;
        head = head->next;
    }
}

int main() {
    int size;
    cin >> size;

    int arr[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> arr[i][j];
        }
    }

    Node* linkedListArr[size];
    for (int i = 0; i < size; i++) {
        linkedListArr[i] = NULL;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] > 0) {
                Node* newNode = new Node(j, arr[i][j]);
                insert_at_tail(linkedListArr[i], newNode);
            }
        }
    }

    for (int i = 0; i < size; i++) {
        cout << i << " ";
        print_list(linkedListArr[i]);
        cout << endl;
    }

    return 0;
}