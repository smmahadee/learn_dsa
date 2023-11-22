#include <iostream>

using namespace std;

int main() {
    // declare and initilize 2d array in STACK
    // int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

    // declare an array IN STACK
    // int arr[2][3];

    // declare array in STACK & HEAP
    // int* arr[2];
    // arr[0] = new int[3];
    // arr[1] = new int[3];

    // declare array full in HEAP
    int **arr;

    arr = new int *[2];
    arr[0] = new int[3];
    arr[1] = new int[3];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
    }

    return 0;
}