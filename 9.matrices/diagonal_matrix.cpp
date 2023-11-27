#include <iostream>

using namespace std;

class Diagonal {
   private:
    int *A;
    int n;

   public:
    Diagonal(int n) {
        this->n = n;
        A = new int[n];
    }

    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    cout << A[i] << " ";
                } else {
                    cout << 0 << " ";
                }
            }

            cout << endl;
        }
    };

    int get(int i, int j) {
        if (i == j) {
            return A[i - 1];
        } else {
            return 0;
        }
    };

    void set(int i, int j, int el) {
        if (i == j) {
            A[i - 1] = el;
        }
    };

    ~Diagonal() { delete[] A; }
};

int main() {
    Diagonal m(4);

    m.set(1, 1, 5);
    m.set(2, 2, 23);
    m.set(3, 3, 52);

    m.display();

    return 0;
}