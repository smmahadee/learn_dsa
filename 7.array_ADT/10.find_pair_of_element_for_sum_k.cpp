#include <iostream>

using namespace std;

int main() {
    int size = 10, sum = 11;
    int arr[] = {2, 3, 5, 6, 7, 8, 9, 10, 12, 18};

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (arr[i] + arr[j] == sum) {
                cout << arr[i] << " " << arr[j] << " " << sum << endl;
                break;
            }
        }
    }

    return 0;
}