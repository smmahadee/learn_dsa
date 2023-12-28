#include <iostream>

using namespace std;

class Node {
   public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
   private:
    Node* head;
    Node* tail;

   public:
    DoublyLinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;
    }

    void create() {
        int size;
        cin >> size;

        for (int i = 0; i < size; i++) {
            int val;
            cin >> val;
            insert(val);
        }
    }

    void display() {
        Node* p = head;

        while (p != NULL) {
            cout << p->val << " ";
            p = p->next;
        }

        cout << endl;
    }

    void insert_at_head(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insert_at_tail(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;
    }

    int getSize() {
        int len = 0;
        Node* p = head;
        while (p != NULL) {
            len++;
            p = p->next;
        }

        return len;
    }

    void deleteEl(int pos) {
        if (pos < 0 || pos >= getSize()) {
            cout << " Invalid";
            return;
        }

        if (pos == 0) {
            Node* deletedNode = head;
            head = head->next;
            head->prev = NULL;
            delete deletedNode;
            return;
        }

        Node* p = head;

        for (int i = 0; i < pos && p; i++) {
            p = p->next;
        }

        if (p == NULL) {
            cout << "invalid index";
            return;
        }

        Node* deletedNode = p;
        p->prev->next = p->next;
        if (p->next != NULL) {
            p->next->prev = p->prev;
        }
        delete deletedNode;
    }

    void reverse_list() {
        Node* p = head;

        while (p != NULL) {
            Node* temp = p->next;
            p->next = p->prev;
            p->prev = temp;

            p = p->prev;

            if (p != NULL && p->next == NULL) {
                head = p;
            }
        }
    }
};

int main() {
    DoublyLinkedList s;
    // s.insert_at_head(10);
    // s.insert_at_head(20);
    s.create();
    s.reverse_list();
    // s.insert_at_tail(100);
    // s.insert_at_tail(200);
    // s.insert_at_tail(300);
    // s.insert_at_head(10);
    // s.deleteEl(2);
    s.display();

    return 0;
}