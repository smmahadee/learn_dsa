#include <iostream>

using namespace std;

class Symentic_Matrix {
   private:
    int *p;
    int size;

   public:
    Symentic_Matrix() {
        size = 2;
        p = new int[size * (size + 1) / 2];
    }

    Symentic_Matrix(int size) {
        this->size = size;
        p = new int[size * (size + 1) / 2];
    }

    ~Symentic_Matrix() { delete[] p; }

    void set(int i, int j, int el) {
        if (i <= j) {
            int index = j * (j - 1) / 2 + i - 1;
            // cout << index << endl;
            p[index] = el;
        }
    }

    int get(int i, int j) {
        if (i <= j) {
            return p[j * (j - 1) / 2 + i - 1];
        } else {
            // int temp = i;
            // i = j;
            // j = temp;

            // return p[j * (j - 1) / 2 + i - 1];
            return p[i * (i - 1) / 2 + j - 1];
        }
    }

    void display() {
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++) {
                if (i <= j) {
                    cout << p[j * (j - 1) / 2 + i - 1] << " ";
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

    Symentic_Matrix m(size);
    for (int i = 1; i <= m.getSize(); i++) {
        for (int j = 1; j <= m.getSize(); j++) {
            int x;
            cin >> x;
            m.set(i, j, x);
        }
    }

    // m.set(1, 1, 12);
    // m.set(1, 2, 13);
    cout << m.get(3, 4);
    cout << m.get(4, 3);

    // m.display();

    return 0;
}