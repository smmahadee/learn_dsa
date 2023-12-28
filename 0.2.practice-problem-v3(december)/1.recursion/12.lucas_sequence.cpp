#include <iostream>

using namespace std;

long long int lucasSequence(int num) {
    if (num == 0) return 2;
    if (num == 1) return 1;

    return lucasSequence(num - 1) + lucasSequence(num - 2);
}

int main() {
    int num;
    cin >> num;
    cout << lucasSequence(num);

    return 0;
}