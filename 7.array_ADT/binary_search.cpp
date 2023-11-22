#include <iostream>

using namespace std;

int main() {
    int size, findValue;
    cin >> size >> findValue;

    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int low = 0;
    int high = size - 1;

    int index = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == findValue) {
            index = mid;
            break;
        } else if (arr[mid] > findValue) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << index << endl;

    return 0;
}