#include <iostream>

using namespace std;

int main() {
    int row, column;
    cin >> row >> column;

    int arr[row][column];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin >> arr[i][j];
        }
    }

    int arr2[row];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == j) {
                arr2[i] = arr[i][j];
            }
        }
    }

    for (int i = 0; i < row; i++) {
        cout << arr2[i] << " ";
    }

    return 0;
}