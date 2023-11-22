#include <iostream>

using namespace std;

int power(int m, int n) {
    if (n == 0) return 1;

    if (n % 2 == 0) {
        return power(m * m, n / 2);
    } else {
        return m * power(m * m, (n - 1) / 2);
    }
}

// function v1
// int power(int m, int n) {
//     if (n == 0) return 1;

//     return m * power(m, n - 1);
// }

int main() {
    cout << power(5, 3) << endl;
    return 0;
}