#include <iostream>

using namespace std;

class Matrix {
   private:
    int *p;
    int size;

   public:
    Matrix() {
        size = 2;
        p = new int[size];
    }

    Matrix(int size) {
        this->size = size;
        p = new int[size];
    }

    ~Matrix() { delete[] p; }

    void set(int i, int j, int el) {
        if (i == j) {
            p[i - 1] = el;
        }
    }

    int get(int i, int j) {
        if (i == j) {
            return p[i - 1];
        } else {
            return -1;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == j) {
                    cout << p[i] << " ";
                } else {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    }

    int getSize() { return size; }
};

int main() {
    int size;
    cin >> size;

    Matrix m(size);
    for (int i = 1; i <= m.getSize(); i++) {
        for (int j = 1; j <= m.getSize(); j++) {
            int x;
            cin >> x;
            m.set(i, j, x);
        }
    }

    // m.set(1, 1, 1);

    m.display();

    return 0;
}