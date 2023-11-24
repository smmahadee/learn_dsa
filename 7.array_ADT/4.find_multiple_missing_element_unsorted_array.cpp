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

    for (int i = 0; i < size - 1; i++) {
        int count = 1;
        if (arr[i] != -1) {
            for (int j = i + 1; j < size; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    arr[j] = -1;
                }
            }

            if(count > 1) {
                cout<<arr[i]<<" is appearing "<<count<< " times"<<endl;
            }
        }
    }

    return 0;
}