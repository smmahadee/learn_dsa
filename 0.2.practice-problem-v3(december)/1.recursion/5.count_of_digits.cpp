#include <iostream>

using namespace std;

long long int countOfDigits(int num) {
    if (num < 10) return 1;

    return 1 + countOfDigits(num / 10);
}

int main() {
    int num;
    cin >> num;

    cout << countOfDigits(num);

    return 0;
} 