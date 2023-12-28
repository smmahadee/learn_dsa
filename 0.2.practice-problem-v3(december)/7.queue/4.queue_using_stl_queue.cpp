#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    int size;
    cin >> size;
    while (size--) {
        int val;
        cin >> val;
        q.push(val);
    }

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}