#include <iostream>
#include <stack>

using namespace std;

class Node {
   public:
    int val;
    Node* next;

    Node(int val) {
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
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            push(val);
        }
    }

    void push(int val) {
        Node* newNode = new Node(val);

        if (top == NULL) {
            top = newNode;
            return;
        }

        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == NULL) {
            return -1;
        }
        Node* returnedNode = top;
        Node* deletedNode = top;

        top = top->next;
        delete deletedNode;
        return returnedNode->val;
    }

    int stackTop() {
        if (top == NULL) {
            return -1;
        } else {
            return top->val;
        }
    }

    int peek(int pos) {
        int x = -1;
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

    bool is_operand(char ch) {
        if (ch == '+' || ch == '-' || ch == '*') {
            return false;
        } else {
            return true;
        }
    }

    bool precedence(char ch) {
        if (ch == '+' || ch == '-') {
            return 1;
        } else if (ch == '*' || ch == '/') {
            return 2;
        } else {
            return 0;
        }
    }


    void inToPostfix(string str) {
        stack<char> operatorStack;
        string postFix;
        int i = 0, j = 0;

        while (str[i] != '\0') {
            if (is_operand(str[i])) {
                postFix += str[i++];
            } else {
                if (operatorStack.empty() || precedence(str[i]) > precedence(operatorStack.top())) {
                    operatorStack.push(str[i++]);
                } else {
                    postFix += operatorStack.top();
                    operatorStack.pop();
                }
            }
        }

        while (!operatorStack.empty()) {
            postFix += operatorStack.top();
            operatorStack.pop();
        }

        cout << "Postfix expression: " << postFix << endl;
    }
};

int main() {
    StackSinglyLinkedList s;
    string infixExpression;

    cout << "Enter an infix expression: ";
    cin >> infixExpression;

    s.inToPostfix(infixExpression);

    return 0;
}