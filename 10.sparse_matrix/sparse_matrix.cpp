#include <iostream>

using namespace std;

class Element {
   public:
    int i;
    int j;
    int x;
};

class Sparse {
   private:
    int m;
    int n;
    int num;
    Element *el;

   public:
    Sparse(int m, int n, int num) {
        this->m = m;
        this->n = n;
        this->num = num;
        this->el = new Element[num];
    }

    void read() {
        for (int i = 0; i < num; i++) {
            cin >> el[i].i >> el[i].j >> el[i].x;
        }
    }

    void display() {
        int k = 0;

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

    Sparse add(Sparse &s) {
        if (m != s.m || n != s.n) return s;

        Sparse *sum = new Sparse(m, n, num + s.num);

        int i = 0, j = 0, k = 0;
        while (i < num && j < s.num) {
            if (el[i].i < s.el[j].i) {
                sum->el[k++] = el[i++];
            } else if (el[i].i > s.el[j].i) {
                sum->el[k++] = s.el[j++];
            } else {
                if (el[i].j < s.el[j].j) {
                    sum->el[k++] = el[i++];
                } else if (el[i].j > s.el[j++].j) {
                    sum->el[k++] = el[j++];
                } else {
                    sum->el[k] = el[i];
                    sum->el[k++].x = el[i++].x + s.el[j++].x;
                }
            }
        }∏

        for (; i < num; i++) sum->el[k++] = el[i];
        for (; j < s.num; j++) sum->el[k++] = el[j];
        sum->num = k;

        return *sum;
    }
};

int main() {
    Sparse s1(5, 5, 5);
    s1.read();
    s1.display();

    cout << endl;

    Sparse s2(5, 5, 5);
    s2.read();
    s2.display();

    cout << endl;

    Sparse sum = s1.add(s2);
    sum.display();

    // for (int i = 0; i < 6; i++) {
    //     cout << sum->el[i].i << " " << sum->el[i].j << " " << sum->el[i].x
    //          << endl;
    // }
}
