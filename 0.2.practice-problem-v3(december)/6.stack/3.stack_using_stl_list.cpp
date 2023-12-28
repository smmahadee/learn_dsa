#include <iostream>
#include <list>

using namespace std;

class StackByStlList {
   private:
    list<int> head;

   public:
    void push(int val) { head.push_back(val); }

    void pop() { head.pop_back(); }

    int top() { return head.back(); }

    int size() { return head.size(); }

    bool isEmpty() { return head.empty(); }
};

int main() {
    StackByStlList s;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        s.push(val);
    }

    while (s.isEmpty() == false) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}