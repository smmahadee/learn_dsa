#include <iostream>

using namespace std;

// find two elements their sum is closest to zero

long long int sumOfArr(int *arr, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }

    return total;
}

int main() {
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << sumOfArr(arr, size);

    return 0;
}