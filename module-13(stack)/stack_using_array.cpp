#include <iostream>

using namespace std;

// stack using array
class StackArray {
   private:
    int sz;
    int top;
    int *arr;

   public:
    StackArray(int sz = 10) {
        this->sz = sz;
        this->top = -1;
        arr = new int[sz];
    }

    void create() {
        int n;
        cin >> n;

        arr = new int[n];
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            push(val);
        }
    }

    void push(int val) {
        if (top == sz - 1) {
            cout << "Stack full";
            return;
        }

        arr[++top] = val;
    }

    int pop() {
        int x = -1;
        if (top == -1) {
            cout << "Stack empty";

        } else {
            x = arr[top--];
        }

        return x;
    }

    int stackTop() {
        if (top == -1) {
            return -1;
        } else {
            return arr[top];
        }
    }

    int peek(int pos) {
        int x = -1;

        if (top - pos + 1 < 0) {
            cout << "Invalid position";
        } else {
            x = top - pos + 1;
        }

        return x;
    }

    bool isEmpty() {
        if (top == -1) {
            return true;
        } else {
            return false;
        }
    }

    bool isFull() {
        if (top == sz - 1) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    StackArray s;
    s.create();
    // s.push(10);
    // s.push(20);
    // s.push(30);
    cout << s.stackTop();

    return 0;
}