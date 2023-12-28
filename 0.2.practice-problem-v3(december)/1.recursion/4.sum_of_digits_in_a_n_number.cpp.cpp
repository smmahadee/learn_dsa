#include <iostream>

using namespace std;

long long int sumOfDigits(int num) {
    if(num < 10) return num;

    return num % 10 + sumOfDigits(num / 10);
}

int main() {
    int num;
    cin >> num;

    cout << sumOfDigits(num);

    return 0;
}