#include <iostream>

using namespace std;

class LowerTri {
   private:
    int *p;
    int size;

   public:
    LowerTri() {
        size = 2;
        p = new int[size * (size + 1) / 2];
    }

    LowerTri(int size) {
        this->size = size;
        p = new int[size * (size + 1) / 2];
    }

    ~LowerTri() { delete[] p; }

    void set(int i, int j, int el) {
        if (i >= j) {
            p[size * (j - 1) - (j - 2) * (j - 1) / 2 + i - j] = el;
        }
    }

    int get(int i, int j) {
        if (i >= j) {
            return p[size * (j - 1) - (j - 2) * (j - 1) / 2 + i - j];
        } else {
            return -1;
        }
    }

    void display() {
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++) {
                if (i >= j) {
                    cout << p[size * (j - 1) - (j - 2) * (j - 1) / 2 + i - j]
                         << " ";
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

    LowerTri m(size);
    for (int i = 1; i <= m.getSize(); i++) {
        for (int j = 1; j <= m.getSize(); j++) {
            int x;
            cin >> x;
            m.set(i, j, x);
        }
    }

    // m.set(1, 1, 12);
    // m.set(2, 1, 13);

    m.display();

    return 0;
}