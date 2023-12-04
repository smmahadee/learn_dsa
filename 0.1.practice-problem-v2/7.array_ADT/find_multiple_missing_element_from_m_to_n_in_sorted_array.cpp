#include <iostream>

using namespace std;

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
                cout << i + diff << " ";
                diff++;
            }
        }
    }

    return 0;
}