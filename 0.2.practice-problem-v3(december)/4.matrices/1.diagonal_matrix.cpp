// diagonal matrix : if i != j then element must be zero, if equal then element
// can be zero or not

#include <iostream>

using namespace std;

class DiagonalMatrix {
   public:
    int *arr;
    int size;

    DiagonalMatrix(int size) {
        arr = new int[size];
        this->size = size;
    }

    void set(int i, int j, int el) {
        if (i != j) {
            cout << "Error";
            return;
        }

        arr[i] = el;
    }

    int get(int i, int j) {
        if (i != j) {
            cout << "Error";
            return -1;
        }

        return arr[i];
    }

    void display() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i != j) {
                    cout << 0 << " ";
                } else {
                    cout << arr[i] << " ";
                }
            }

            cout << endl;
        }
    }
};

int main() {
    int size;
    cin >> size;

    DiagonalMatrix m(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int val;
            cin >> val;
            if (i == j) {
                m.set(i, j, val);
            }
        }
    }

    m.display();

    return 0;
}