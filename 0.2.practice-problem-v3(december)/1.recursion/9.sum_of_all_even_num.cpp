#include <iostream>

using namespace std;

long long int sumOfAllEven() {
    int val;
    cin >> val;

    if (val == -1) return 0;

    if (val % 2 == 0) {
        return val + sumOfAllEven();
    } else {
        return 0 + sumOfAllEven();
    }
}

int main() {
    cout << sumOfAllEven();

    return 0;
}