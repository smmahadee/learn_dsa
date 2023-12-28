#include <iostream>

using namespace std;

// swap value between two array elements

int main() {
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int arr2[size];
    for (int i = 0; i < size; i++) {
        cin >> arr2[i];
    }

    for (int i = 0; i < size; i++) {
        swap(arr[i], arr2[i]);
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << arr2[i] << " ";
    }

    return 0;
}