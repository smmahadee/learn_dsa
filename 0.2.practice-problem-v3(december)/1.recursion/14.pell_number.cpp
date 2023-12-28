#include <iostream>

using namespace std;

int pellNumber(int index) {
    if (index == 0) return 0;
    if (index == 1) return 1;

    return 2 * pellNumber(index - 1) + pellNumber(index - 2);
}

int main() {
    int index;
    cin >> index;

    cout << pellNumber(index);

    return 0;
}