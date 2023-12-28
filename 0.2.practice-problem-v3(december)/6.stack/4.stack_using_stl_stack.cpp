#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s;
    int size;
    cin >> size;
    while (size--) {
        int val;
        cin >> val;
        s.push(val);
    }

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}