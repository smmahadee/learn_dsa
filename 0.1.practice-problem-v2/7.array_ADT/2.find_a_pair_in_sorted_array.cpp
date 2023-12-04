#include <iostream>

using namespace std;

int main() {
    int size, targetEl;
    cin >> size >> targetEl;

    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int i = 0, j = size - 1;
    while (i < j) {
        int total = arr[i] + arr[j];

        if (total == targetEl) {
            cout << arr[i] << " " << arr[j] << " " << targetEl << endl;
            i++;
            j--;
        } else if (total < targetEl) {
            i++;
        } else {
            j--;
        }
    }

    return 0;
}