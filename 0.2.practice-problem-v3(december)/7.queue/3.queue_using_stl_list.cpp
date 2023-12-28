#include <iostream>
#include <list>

using namespace std;

class QueueStlList {
   private:
    list<int> head;

   public:
    void push(int val) { head.push_back(val); }

    void pop() { head.pop_front(); }

    int front() { return head.front(); }

    int size() { return head.size(); }

    bool isEmpty() { return head.empty(); }
};

int main() {
    QueueStlList s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    // s.pop();

    // cout << s.front();

    while (!s.isEmpty()) {
        cout << s.front() << " ";
        s.pop();
    }

    return 0;
}