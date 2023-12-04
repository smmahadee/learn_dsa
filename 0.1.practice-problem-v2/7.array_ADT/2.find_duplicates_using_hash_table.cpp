#include <iostream>

using namespace std;

int main() {
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (max < arr[i]) max = arr[i];
        if (min > arr[i]) min = arr[i];
    }

    int freArr[max];
    for (int i = 0; i < max; i++) {
        freArr[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        freArr[arr[i]]  += 1;
    }

    for (int i = min; i <= max; i++) {
        if (freArr[i] > 1) {
            cout << i << " apeared " << freArr[i] << " times" << endl;
        }
    }

    return 0;
}