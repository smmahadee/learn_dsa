#include <iostream>

using namespace std;

class Element {
   public:
    int i;
    int j;
    int x;
};

class Sparse_Matrix {
   private:
    int m;
    int n;
    int num;
    Element *el;

   public:
    Sparse_Matrix() {
        m = 2;
        n = 2;
        num = 1;
    }

    Sparse_Matrix(int m, int n, int num) {
        this->m = m;
        this->n = n;
        this->num = num;
    }

    void create() {
        cin >> m >> n >> num;
        el = new Element[num];

        for (int i = 0; i < num; i++) {
            cin >> el[i].i >> el[i].j >> el[i].x;
        }
    }

    void display() {
        int i, j, k = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == el[k].i && j == el[k].j) {
                    cout << el[k++].x << " ";
                } else {
                    cout << 0 << " ";
                }
            }

            cout << endl;
        }
    }
};

int main() {
    Sparse_Matrix s;
    s.create();
    s.display();
}