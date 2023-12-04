#include <iostream>

using namespace std;

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

    int total = size * (size + 1) / 2;

    cout << sum - total;

    return 0;
}