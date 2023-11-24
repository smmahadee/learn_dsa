#include <iostream>

using namespace std;

int main() {
    int size = 10, sum = 11;
    int arr[] = {2, 3, 5, 6, 7, 8, 9, 10, 12, 18};

    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < size; i++) {
        mn = min(arr[i], mn);
        mx = max(arr[i], mx);
    }

    int freqArr[mx];
    for (int i = 0; i < mx; i++) {
        freqArr[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        int needNum = sum - arr[i];

        if (freqArr[needNum] > 0 && needNum > 0) {
            cout << arr[i] << " " << needNum << " " << sum << endl;
        } else {
            freqArr[arr[i]]++;
        }
    }

    return 0;
}