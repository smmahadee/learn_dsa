#include <iostream>

using namespace std;

long long int sumOfN(int num) {
    if (num == 0) return 0;

    return num + sumOfN(num - 1);
}

int main() {
    int num;
    cin >> num;

    cout << sumOfN(num);

    return 0;
}