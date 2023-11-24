#include <iostream>

using namespace std;

int main() {
    int arr[] = {2, 3, 3, 3, 4, 5, 5, 6, 7, 7};

    for (int i = 0; i < 10 - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            int j = i + 1;
            while (arr[j] == arr[i]) j++;
            cout << arr[i] << " is appearing " << j - i << " times" << endl;
            i = j - 1;
        }
    }

    return 0;
}