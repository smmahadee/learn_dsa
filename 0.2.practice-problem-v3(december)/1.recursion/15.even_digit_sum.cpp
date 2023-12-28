#include <iostream>

using namespace std;

int evenDigitSum(int num) {
    if (num < 10) {
        return num % 2 == 0 ? 1 : 0;
    }

    if (num % 2 == 0) {
        return evenDigitSum(num / 10);
    } else {
        return !evenDigitSum(num / 10);
    }
}

int main() {
    int num;
    cin >> num;

    cout << evenDigitSum(num);

    return 0;
}