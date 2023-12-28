#include <iostream>

using namespace std;

// even odd count in a digit occurence in a num

int evenOddCount(int num, int digit) {
    if (num < 10) {
        return num == digit ? 0 : 1;
    }

    if (num % 10 == digit) {
        return !evenOddCount(num / 10, digit);
    } else {
        return evenOddCount(num / 10, digit);
    }

    // if (num % 10 == digit) {
    //     if (result == 0) {
    //         return 1;
    //     } else {
    //         return 0;
    //     }
    // } else {
    //     if (result == 0) {
    //         return 0;
    //     } else {
    //         return 1;
    //     }
    // }

    // if (result == 0) {
    //     if (num % 10 == digit) {
    //         return 1;
    //     } else {
    //         return 0;
    //     }
    // } else {
    //     if (num % 10 == digit) {
    //         return 0;
    //     } else {
    //         return 1;
    //     }
    // }
}

int main() {
    int num, digit;
    cin >> num >> digit;
    cout << evenOddCount(num, digit);

    return 0;
}