// diagonal matrix : if i < j then element must be zero, if i >= then element
// can be zero or not

#include <iostream>

using namespace std;

class LowerTriangleMatrixColumnMajor {
   public:
    int *arr;
    int size;

    LowerTriangleMatrixColumnMajor(int size) {
        arr = new int[size * (size + 1) / 2];
        this->size = size;
    }

    void set(int i, int j, int el) {
        if (i < j) {
            cout << "Error";
            return;
        }
        int index = size * (j - 1) - (j - 2) * (j - 1) / 2 + i - j;
        arr[index] = el;
    }

    int get(int i, int j) {
        if (i < j) {
            cout << "Error";
            return -1;
        }
        int index = size * (j - 1) - (j - 2) * (j - 1) / 2 + i - j;
        return arr[index];
    }

    void display() {
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++) {
                if (i < j) {
                    cout << 0 << " ";
                } else {
                    int index = size * (j - 1) - (j - 2) * (j - 1) / 2 + i - j;
                    cout << arr[index] << " ";
                }
            }

            cout << endl;
        }
    }
};

int main() {
    int size;
    cin >> size;

    LowerTriangleMatrixColumnMajor m(size);
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            int val;
            cin >> val;
            if (i >= j) {
                m.set(i, j, val);
            }
        }
    }

    // m.set(0, 0, 1);
    // m.set(2, 1, 2);

    // for (int i = 0; i < m.size; i++)
    // {
    //     cout<<m.arr[i]<<" ";
    // }

    m.display();

    return 0;
}