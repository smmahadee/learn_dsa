#include <iostream>

using namespace std;

// find missing element from 1 to n

int main() {
    int size;
    cin >> size;
    int arr[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    int nthTotal = (arr[size - 1] * (arr[size - 1] + 1)) / 2;

    cout << nthTotal - sum << endl;

    return 0;
}