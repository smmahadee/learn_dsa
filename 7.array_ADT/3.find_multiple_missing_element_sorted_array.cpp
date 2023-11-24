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

    int diff = arr[0] - 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] - i != diff) {
            while (diff < arr[i] - i) {
                cout << i + diff << endl;
                diff++;
            }
        }
    }

    return 0;
}