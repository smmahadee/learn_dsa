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
            return -1;
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

                // if(i == 1 && j == 4) {
                //       cout << p[j * (j - 1) / 2 + i - 1] << " ";
                // }
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
    for (int i = 1; i <= m.getSize(); i++) {
        for (int j = 1; j <= m.getSize(); j++) {
            int x;
            cin >> x;
            m.set(i, j, x);
        }
    }

    cout<<m.get(1, 4);
    // m.set(1, 1, 12);
    // m.set(1, 2, 13);

    // m.display();

    return 0;
}