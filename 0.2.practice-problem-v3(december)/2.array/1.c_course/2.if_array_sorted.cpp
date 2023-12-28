#include <iostream>

using namespace std;

int main() {
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int flag = 1;
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            flag = 0;
            break;
        }
    }

    cout << flag;

    return 0;
}