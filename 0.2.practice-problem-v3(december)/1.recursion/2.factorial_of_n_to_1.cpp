#include <iostream>

using namespace std;

long long int factorialOfN(int num) {
    if (num <= 1) return 1;

    return num * factorialOfN(num - 1);
}

int main() {
    int num;
    cin >> num;

    cout << factorialOfN(num);

    return 0;
}