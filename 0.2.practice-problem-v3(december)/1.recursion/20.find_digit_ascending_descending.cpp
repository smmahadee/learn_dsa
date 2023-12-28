#include <iostream>

using namespace std;

// find if digits are ascending or descending

int findAscDesc(int num) {
    if (num < 100) {
        if (num / 10 < num % 10) {
            return 1;
        } else {
            return -1;
        }
    }

    int result = findAscDesc(num / 10);

    if (num % 10 >= num / 10 % 10) {
        if (result == 1) {
            return 1;
        } else if (result == -1) {
            return 0;
        }
    } else {
        if (result == -1) {
            return -1;
        } else {
            return 0;
        }
    }
}

int main() {
    int num;
    cin >> num;
    cout << findAscDesc(num);

    return 0;
}