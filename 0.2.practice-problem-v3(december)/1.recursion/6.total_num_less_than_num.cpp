#include <iostream>

using namespace std;

long long int lessThanNum(int num) {
    int val;
    cin >> val;

    if (val == -1) return 0;

    if (val >= num) {
        return 0 + lessThanNum(num);
    } else {
        return 1 + lessThanNum(num);
    }
}

int main() {
    int num;
    cin >> num;

    cout << lessThanNum(num);

    return 0;
}