#include <iostream>

using namespace std;

// find multiple missing element from a sorted array

int main() {
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] < mn) mn = arr[i];
        if (arr[i] > mx) mx = arr[i];
    }

    int freqArr[mx];
    for (int i = 0; i < mx; i++) {
        freqArr[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        freqArr[arr[i]]++;
    }

    for (int i = mn; i < mx; i++) {
        if (freqArr[i] == 0) {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}