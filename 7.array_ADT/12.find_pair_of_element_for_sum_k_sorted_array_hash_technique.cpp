#include <iostream>

using namespace std;

int main() {
    int size = 10, sum = 11;
    int arr[] = {2, 3, 5, 6, 7, 8, 9, 10, 12, 18};

    int i = 0;
    int j = size - 1;
    while (i < j) {
        int total = arr[i] + arr[j];
        if (total == sum) {
            cout << arr[i] << " " << arr[j] << " " << sum << endl;
            i++, j--;

        } else if (total > sum) {
            j--;
        } else {
            i++;
        }
    }

    return 0;
}