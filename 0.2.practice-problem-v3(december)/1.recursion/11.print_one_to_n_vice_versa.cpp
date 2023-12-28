#include <iostream>

using namespace std;

// print one to n and n to 1 (1 duplications)

void printOneToNViceVersa(int num) {
    if (num == 1) {
        cout << num << " ";
        return;
    }

    cout << num << " ";
    printOneToNViceVersa(num - 1);
    cout << num << " ";
}

int main() {
    int num;
    cin >> num;
    printOneToNViceVersa(num);

    return 0;
}