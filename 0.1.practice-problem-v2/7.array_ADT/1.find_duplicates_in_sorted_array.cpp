#include <iostream>

using namespace std;

int main() {
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < size - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            int j = i + 1;
            while (arr[j] == arr[i]) j++;

            cout << arr[i] << " " << j - i << " times" << endl;
            i = j - 1;
        }
    }

    return 0;
}