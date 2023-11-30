#include <iostream>

using namespace std;

class Toeplitz_Matrix {
   private:
    int *p;
    int size;

   public:
    Toeplitz_Matrix() {
        size = 2;
        p = new int[2 * size - 1];
    }

    Toeplitz_Matrix(int size) {
        this->size = size;
        p = new int[2 * size - 1];
    }

    ~Toeplitz_Matrix() { delete[] p; }

    void set(int i, int j, int el) {
        if (i == 1 && j >= i) {
            p[j - i] = el;
        }

        if (i > 1 && j == 1) {
            p[size + i - j - 1] = el;
        }
    }

    int get(int i, int j) {
        int element = -1;
        if (i <= j) {
            element = p[j - i];
        } else {
            element = p[i - j - 1];
        }
        return element;
    }

    void display() {
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++) {
                if (i <= j) {
                    cout << p[j - i] << " ";
                } else {
                    cout << p[size + i - j - 1] << " ";
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

    Toeplitz_Matrix m(size);
    for (int i = 1; i <= m.getSize(); i++) {
        for (int j = 1; j <= m.getSize(); j++) {
            int x;
            cin >> x;
            m.set(i, j, x);
        }
    }

    // m.set(1, 1, 6);
    // m.set(1, 2, 13);
    // m.set(2, 1, 10);

    // cout << m.get(3, 4);
    // cout << m.get(4, 3);

    m.display();
    // for (int i = 0; i < 2 * m.getSize() - 1; i++) {
    //     cout << m.p[i] << " ";
    // }

    return 0;
}