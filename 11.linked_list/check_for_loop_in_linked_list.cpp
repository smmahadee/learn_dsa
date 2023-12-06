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

bool checkIsThisLoopLinkedList(Node *head) {
    Node *p, *q;
    q = q = head;

    do {
        p = p->next;
        q = q->next;
        q = q != NULL ? q->next : NULL;
    } while (q && q && p != q);

    return p == q ? true : false;
}

void display_node(Node *head) {
    cout << "Your linked lists are: ";

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


int main() {
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;    
    d->next = NULL;

    // bool result = checkIsThisLoopLinkedList(head);
    // if (result) {
    //     cout << "yes";

    // } else {
    //     cout << "NO";
    // }

    return 0;
}