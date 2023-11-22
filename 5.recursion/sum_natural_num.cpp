#include <iostream>

using namespace std;

int sumOfNatural(int num) {
    if (num == 0) return 0;

    return num + sumOfNatural(num - 1);
}

int main() {
    int result = sumOfNatural(5);
    cout << result << endl;

    return 0;
}