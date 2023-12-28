#include <iostream>

using namespace std;

class Node {
   public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        next = NULL;
    }
};

class SinglyLinkedList {
   private:
    Node* head;
    Node* tail;
    int size;

   public:
    SinglyLinkedList() {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    void insert(int val) {
        Node* newNode = new Node(val);

        size++;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
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
        head = newNode;
    }

    void insert_at_tail(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
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

        size--;

        if (pos == 0) {
            Node* deletedNode = head;
            head = head->next;
            delete deletedNode;
            return;
        }

        Node* p = head;

        for (int i = 0; i < pos - 1 && p; i++) {
            p = p->next;
        }

        if (p == NULL || p->next == NULL) {
            cout << "invalid index";
            return;
        }

        Node* deletedNode = p->next;
        p->next = p->next->next;
        delete deletedNode;
    }

    int maxEl() {
        int max = INT_MIN;
        Node* p = head;
        while (p != NULL) {
            if (p->val > max) max = p->val;
            p = p->next;
        }
        return max;
    }

    void insert_in_a_sorted_list(int val) {
        Node* newNode = new Node(val);

        Node* p = head;
        Node* q = NULL;

        while (p != NULL && p->val <= val) {
            q = p;
            p = p->next;
        }

        if (p == head) {
            newNode->next = head;
            head = newNode;

        } else {
            newNode->next = p;
            q->next = newNode;
        }
    }

    void reverse_list_by_elements() {
        int arr[getSize()];
        Node* p = head;
        int i = 0;

        while (p != NULL) {
            arr[i++] = p->val;
            p = p->next;
        }

        p = head;
        i--;

        while (p != NULL) {
            p->val = arr[i--];
            p = p->next;
        }
    }

    void reverse_list_by_pointer() {
        Node* p = head;
        Node* q = NULL;
        Node* r = NULL;

        while (p != NULL) {
            r = q;
            q = p;
            p = p->next;

            q->next = r;
        }

        head = q;
    }
};

int main() {
    SinglyLinkedList s;
    // s.insert_at_head(20);
    // s.insert_at_head(10);
    // s.insert_in_a_sorted_list(15);
    s.create();
    // s.reverse_list_by_elements();
    s.reverse_list_by_pointer();
    // s.insert_at_tail(100);
    // s.deleteEl(2);
    // cout << s.maxEl()<<endl;
    s.display();

    return 0;
}