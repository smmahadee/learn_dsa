#include <iostream>

using namespace std;

int fun(int n) {
    if (n == 0) return 0;

    static int val = 0;
    val++;

    return fun(n - 1) + val;
}

int fun2(int n) {
    if( n == 0) return 1;

    return fun2(n - 1);
}

int main() {
    int n = 3;

    int total = fun(n);
    cout << total << endl;

    return 0;
}