#include <iostream>

using namespace std;

long long int sumOfFibonacci(int num) {
    if (num == 0) return 0;
    if (num == 1) return 1;

    return sumOfFibonacci(num - 1) + sumOfFibonacci(num - 2);
}

int main() {
    int num;
    cin >> num;

    cout << sumOfFibonacci(num);

    return 0;
}