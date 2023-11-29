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
        el = new Element[num];
    }

    Sparse_Matrix(int m, int n, int num) {
        this->m = m;
        this->n = n;
        this->num = num;
        el = new Element[num];
    }

    void create() {
        cin >> m >> n >> num;
        el = new Element[num];

        for (int i = 0; i < num; i++) {
            cin >> el[i].i >> el[i].j >> el[i].x;
        }
    }
};

int main() { 
    Sparse_Matrix s;
    s.create();
 }