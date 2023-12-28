#include <iostream>

using namespace std;

int evenOddPosition(int num) {
    if (num < 10) {
        if (num % 2 == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    if (num < 100) {
        if (num / 10 % 2 == 1 && num % 10 % 2 == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    if (num % 10 % 2 == 0 && num / 10 % 10 % 2 == 1) {
        return evenOddPosition(num / 100);
    } else {
        return 0;
    }
}

int main() {
    int num;
    cin >> num;

    cout << evenOddPosition(num);

    return 0;
}