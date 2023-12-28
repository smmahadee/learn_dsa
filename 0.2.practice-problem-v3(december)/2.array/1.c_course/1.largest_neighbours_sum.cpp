#include <iostream>

using namespace std;

// 1, 4, 3, 7 , 1 = 10

int main() {
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int max = INT_MIN;
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] + arr[i + 1] > max) max = arr[i] + arr[i + 1];
    }

    cout << max;

    return 0;
}