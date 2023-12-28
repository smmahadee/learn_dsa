#include <iostream>

using namespace std;

void fun(int size, char ch1) {
    if (size == 0) return;

    cout << ch1 << " ";
    fun(size - 1, ch1);
    int val = ch1 - 32;
    cout << (char)val << " ";
}

int main() {
    int total;
    char ch1;
    cin >> total >> ch1;

    fun(total, ch1);    

    return 0;
}