#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int size;
    cin >> size;

    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    vector<int> freqArr(max + 1, 0);

    for (int i = 0; i < size; i++) {
        int index = arr[i];
        freqArr[index]++;
    }

    int uniqueTotal = 0;
    for (int i = min; i <= max; i++) {
        if (freqArr[i] > 1) {
            cout << i << " ";
            uniqueTotal += i;
        }
    }

    cout << endl << uniqueTotal;

    return 0;
}
