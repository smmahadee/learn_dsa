#include <iostream>

using namespace std;

int main() {
    int size, targetEl;
    cin >> size >> targetEl;

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

    int freqArr[max];
    for (int i = 0; i < max; i++) {
        freqArr[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        freqArr[arr[i]] += 1;
    }

    for (int i = 0; i < size; i++) {
        if (freqArr[targetEl - arr[i]] != 0 && targetEl - arr[i] != arr[i]) {
            cout << arr[i] << " " << targetEl - arr[i] << " " << targetEl
                 << endl;
            // freqArr[targetEl - arr[i]]--;
            freqArr[arr[i]]--;
        }
    }

    return 0;
}