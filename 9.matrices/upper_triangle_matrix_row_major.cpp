#include <iostream>

using namespace std;

class UperTri {
   private:
    int *p;
    int size;

   public:
    UperTri() {
        size = 2;
        p = new int[size * (size + 1) / 2];
    }

    UperTri(int size) {
        this->size = size;
        p = new int[size * (size + 1) / 2];
    }

    ~UperTri() { delete[] p; }

    void set(int i, int j, int el) {
        if (i >= j) {
            p[(i - 1) * size - (i - 2) * (i - 1) / 2 + (j - i)] = el;
        }
    }

    int get(int i, int j) {
        if (i >= j) {
            return p[(i - 1) * size - (i - 2) * (i - 1) / 2 + (j - i)];
        } else {
            return -1;
        }
    }

    void display() {
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++) {
                if (i >= j) {
                    cout << p[(i - 1) * size - (i - 2) * (i - 1) / 2 + (j - i)]
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

    UperTri m(size);
    // for (int i = 1; i <= m.getSize(); i++) {
    //     for (int j = 1; j <= m.getSize(); j++) {
    //         int x;
    //         cin >> x;
    //         m.set(i, j, x);
    //     }
    // }

    m.set(1, 1, 12);
    m.set(1, 3, 13);

    m.display();

    return 0;
}