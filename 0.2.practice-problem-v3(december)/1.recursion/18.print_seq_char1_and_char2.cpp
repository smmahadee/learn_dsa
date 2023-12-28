#include <iostream>

using namespace std;

void fun(int size, char ch1, char ch2) {
    if (size == 0) return;

    cout << ch1 << " ";
    fun(size - 1, ch1, ch2);
    cout << ch2 << " ";
}

int main() {
    int total;
    char ch1, ch2;
    cin >> total >> ch1 >> ch2;

    fun(total, ch1, ch2);

    return 0;
}