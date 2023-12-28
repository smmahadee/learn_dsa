#include <iostream>

using namespace std;

// print one to n and n to 1

void printOneToN(int num) {
    if (num == 0) return;

    printOneToN(num - 1);
    cout << num << " ";
}

void printNToOne(int num) {
    if (num == 0) return;

    cout << num << " ";
    printNToOne(num - 1);
}

int main() {
    int num;
    cin >> num;
    // printOneToN(num);
    printNToOne(num);

    return 0;
}