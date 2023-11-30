#include <iostream>

using namespace std;

class Tridiagonal_Matrix {
   private:
    int size;

   public:
    int *p;
    Tridiagonal_Matrix() {
        size = 2;
        p = new int[3 * size - 2];
    }

    Tridiagonal_Matrix(int size) {
        this->size = size;
        p = new int[3 * size - 2];
    }

    ~Tridiagonal_Matrix() { delete[] p; }

    void set(int i, int j, int el) {
        if (i - j == 1) {
            p[i -2] = el;
        }
        if (i - j == 0) {
            p[size - 1 + i - 1] = el;
        }

        if (i - j == -1) {
            p[2 * size - 1 + i - 1] = el;
        }

        // else if (i - j == 0) {
        //     p[size - 1 + i - 1] = el;
        // } else if (i - j == -1) {
        //     p[2 * size - 1 + i - 1] = el;
        // }
    }

    int get(int i, int j) {
        int element = -1;
        if (i - j == 1) {
            element = p[i - 1];
        } else if (i - j == 0) {
            element = p[size - 1 + i - 1];
        } else if (i - j == -1) {
            element = p[2 * size - 1 + i - 1];
        }
        return element;
    }

    void display() {
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++) {
                if (i - j == 1) {
                    cout << p[i - 2] << " ";
                } else if (i - j == 0) {
                    cout << p[size - 1 + i - 1] << " ";
                } else if (i - j == -1) {
                    cout << p[2 * size - 1 + i - 1] << " ";
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

    Tridiagonal_Matrix m(size);
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
    cout<<endl;
    for (int i = 0; i < 3 * m.getSize() - 2; i++) {
        cout << m.p[i] << " ";
    }

    return 0;
}