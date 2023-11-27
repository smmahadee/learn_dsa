#include <iostream>

using namespace std;

class LowerTri {
   private:
    int *A;
    int n;

   public:
    LowerTri() {
        this->n = 2;
        A = new int[2 * (2 + 1) / 2];
    }
    LowerTri(int n) {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }

    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i >= j) {
                    cout << A[i * (i - 1) / 2 + j - 1] << " ";
                } else {
                    cout << 0 << " ";
                }
            }

            cout << endl;
        }
    };

    int get(int i, int j) {
        if (i >= j) {
            return A[i * (i - 1) / 2 + j - 1];
        } else {
            return 0;
        }
    };

    void set(int i, int j, int el) {
        if (el == 0) return;

        int index = (i * (i - 1) / 2) + j - 1;
        A[index] = el;
    };

    ~LowerTri() { delete[] A; }
};

int main() {
    LowerTri m(3);

    m.set(1, 1, 5);
    m.set(2, 1, 6);
    m.set(2, 2, 7);
    m.set(3, 1, 8);
    m.set(3, 2, 9);
    m.set(3, 3, 10);

    // cout<<m.get(3,3);

    m.display();

    return 0;
}