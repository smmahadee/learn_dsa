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

    void create() {
        int val;
        cout << "Enter value, write -1 to exit: ";
        int flag = 1;
        while (flag) {
            cin >> val;
            if (val == -1) {
                flag = 0;
                break;
            };

            insert_at_tail(val);
        }
    }

    void display() {
        Node *p = head;

        cout << "Your values are: ";
        while (p != NULL) {
            cout << p->val << " ";
            p = p->next;
        }

        cout << endl;
    }

    void display_node_recursive() {}

    int size() {
        Node *p = head;
        int len = 0;
        while (p != NULL) {
            len++;
            p = p->next;
        }

        return len;
    }

    void insert_at_head(int val) {
        Node *newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insert_at_tail(int val) {
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

    void insert_at_any_position(int pos, int val) {
        if (pos < 0 || pos > size()) {
            cout << "Invalid position";
            return;
        }

        if (pos == 0) {
            insert_at_head(val);
        } else {
            Node *newNode = new Node(val);
            Node *p = head;
            for (int i = 0; i < pos - 1; i++) {
                p = p->next;
            }

            newNode->next = p->next;
            p->next = newNode;
        }
    }

    long long int sum() {
        Node *p = head;

        long long int sum = 0;
        while (p != NULL) {
            sum += p->val;
            p = p->next;
        }

        return sum;
    }

    int find_index(int el) {
        Node *p = head;
        int index = 0;
        while (p != NULL) {
            if (p->val == el) {
                return index;
            }

            index++;
            p = p->next;
        }

        return -1;
    }

    void insert_in_sorted_list(int el) {
        Node *newNode = new Node(el);

        Node *p = head;
        Node *q = NULL;

        while (p && p->val < el) {
            q = p;
            p = p->next;
        }

        if (p == head) {
            insert_at_head(el);
        } else {
            newNode->next = q->next;
            q->next = newNode;
        }
    }

    void delete_a_node(int pos) {
        if (pos < 0 || pos >= size()) return;

        Node *p = head;
        Node *q = NULL;

        for (int i = 0; i < pos; i++) {
            q = p;
            p = p->next;
        }

        if (q == NULL) {
            head = head->next;
            delete p;
        } else {
            q->next = q->next->next;
            delete p;
        }
    }

    void reverse_list_by_elements() {
        int arr[size()];

        Node *p = head;
        int i = 0;

        while (p != NULL) {
            arr[i++] = p->val;
            p = p->next;
        }

        i--;
        p = head;

        while (p != NULL) {
            p->val = arr[i--];
            p = p->next;
        }
    }

    void reverse_list_by_pointers() {
        Node *p = head;
        Node *q = NULL;
        Node *r = NULL;

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
    LinkedList a;

    while (true) {
        cout << endl << "1. Create a linked list" << endl;
        cout << "2. Display linked list" << endl;
        cout << "3. Insert a value at any position" << endl;
        cout << "4. Sum of linked list" << endl;
        cout << "5. Find index of an element" << endl;
        cout << "6. Insert in a sorted list" << endl;
        cout << "7. Delete an element by index" << endl;
        cout << "8. Reverse list" << endl;

        cout << endl << "Choose an option: ";

        int op;
        cin >> op;

        if (op == 1) {
            a.create();
        } else if (op == 2) {
            a.display();
        } else if (op == 3) {
            int pos, val;
            cin >> pos >> val;
            a.insert_at_any_position(pos, val);
        } else if (op == 4) {
            cout << "Sum is : " << a.sum() << endl;
        } else if (op == 5) {
            cout << "Enter a valid element: ";
            int el;
            cin >> el;
            cout << "Index of the element is: " << a.find_index(el) << endl;
        } else if (op == 6) {
            int el;
            cin >> el;
            a.insert_in_sorted_list(el);
        } else if (op == 7) {
            int pos;
            cin >> pos;
            a.delete_a_node(pos);
        } else if (op == 8) {
            a.reverse_list_by_elements();
        } else {
            break;
        }
    }

    return 0;
}