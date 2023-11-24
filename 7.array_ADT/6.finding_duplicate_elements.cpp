#include <iostream>

using namespace std;

int main() {
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int lastDuplicate;
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] == arr[i + 1] && lastDuplicate != arr[i]) {
            cout << arr[i] << " ";
            lastDuplicate = arr[i];
        }
    }

    cout << endl;

    return 0;
}