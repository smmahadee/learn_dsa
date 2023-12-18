#include <iostream>

using namespace std;
class Node {
   public:
    char val;
    Node* next;

    Node(char val) {
        this->val = val;
        this->next = NULL;
    }
};

class StackSinglyLinkedList {
   private:
    Node* top;

   public:
    StackSinglyLinkedList() { top = NULL; }

    void create() {
        // int n;
        // cin >> n;
        // for (int i = 0; i < n; i++) {
        //     char val;
        //     cin >> val;
        //     push(val);
        // }

        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            push(s[i]);
        }
    }

    void push(char val) {
        Node* newNode = new Node(val);

        if (top == NULL) {
            top = newNode;
            return;
        }

        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (top == NULL) {
            return '1';
        }
        Node* returnedNode = top;
        Node* deletedNode = top;

        top = top->next;
        delete deletedNode;
        return returnedNode->val;
    }

    char stackTop() {
        if (top == NULL) {
            return '1';
        } else {
            return top->val;
        }
    }

    char peek(int pos) {
        char x = '1';
        Node* p = top;

        for (int i = 0; p != NULL && i < pos - 1; i++) {
            p = p->next;
        }
        if (p != NULL) {
            x = p->val;
        }
        return x;
    }

    bool isEmpty() { return top == NULL ? true : false; }

    bool isFull() {
        Node* newNode = new Node(10);
        if (newNode) {
            return false;
        } else {
            return true;
        }

        delete newNode;
    }

    // this code not necessary , follow above code
    // int size() {
    //     int len = 0;
    //     Node* p = top;
    //     while (p != NULL) {
    //         len++;
    //         p = p->next;
    //     }

    //     return len;
    // }

    bool is_balance(string str) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') {
                push(str[i]);
            } else if (str[i] == ')') {
                if (top != NULL) {
                    pop();
                } else {
                    return false;
                }
            }
        }
        if (top != NULL) {
            return false;

        } else {
            return true;
        }
    }
};
int main() {
    StackSinglyLinkedList sl;
    string str;
    cin >> str;
    if (sl.is_balance(str)) {
        cout << "true";
    } else {
        cout << "false";
    }
    // sl.create();
    // cout << sl.stackTop();
    return 0;
}