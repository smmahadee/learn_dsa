#include <iostream>

using namespace std;

int main() {
    int size = 10;
    int arr[10] = {5, 2 , 5, 20, 12, 20, 5, 20, 5, 20};

    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] < mn) mn = arr[i];
        if (arr[i] > mx) mx = arr[i];
    }


    int freqArr[mx];
    for (int i = 0; i <= mx; i++) {
        freqArr[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        freqArr[arr[i]]++;
    }


    for (int i = mn; i <= mx; i++) {
        if (freqArr[i] > 1) {
            cout << i << " is appearing " << freqArr[i] << " times" << endl;
        }
    }

    return 0;
}