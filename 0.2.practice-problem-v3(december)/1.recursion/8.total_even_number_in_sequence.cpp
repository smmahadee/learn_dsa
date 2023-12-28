#include <iostream>

using namespace std;

long long int totalEvenNum() {
    int val;
    cin >> val;

    if (val == -1) return 0;

    if (val % 2 == 0) {
        return 1 + totalEvenNum();
    } else {
        return 0 + totalEvenNum();
    }
}

int main() {
    cout << totalEvenNum();

    return 0;
}