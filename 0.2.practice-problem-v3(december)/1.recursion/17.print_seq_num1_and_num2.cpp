#include <iostream>

using namespace std;

void fun(int size, int num1, int num2) {
    if (size == 0) return;

    cout << num1 << " ";
    fun(size - 1, num1, num2);
    cout << num2 << " ";
}

int main() {
    int total, num1, num2;
    cin >> total >> num1 >> num2;

    fun(total, num1, num2);

    return 0;
}