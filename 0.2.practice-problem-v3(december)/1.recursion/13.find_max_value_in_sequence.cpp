#include <iostream>

using namespace std;

int findMax() {
    int val;
    cin >> val;
    if (val == -1) return INT_MIN;

    int result = findMax();
    if (result > val) {
        return result;
    } else {
        return val;
    }
}

int findMin() {
    int val;
    cin >> val;
    if (val == -1) return INT_MAX;

    int result = findMin();
    if (result < val) {
        return result;
    } else {
        return val;
    }
}

int main() {
    // cout << findMax();
    cout << findMin();

    return 0;
}