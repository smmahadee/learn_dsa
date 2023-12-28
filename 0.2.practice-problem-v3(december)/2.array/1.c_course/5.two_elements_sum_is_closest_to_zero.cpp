#include <iostream>

using namespace std;

// find two elements their sum is closest to zero

int main() {
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int min = INT_MAX;

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (abs(arr[i] + arr[j]) < min) min = arr[i] + arr[j];
        }
    }

    cout << min;

    return 0;
}