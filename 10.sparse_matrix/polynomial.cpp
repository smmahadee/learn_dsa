#include <iostream>

using namespace std;

class Term {
   public:
    int coef;
    int expo;
};

class Poly {
   private:
    int num;
    Term *terms;

   public:
    Poly(int num) {
        this->num = num;
        this->terms = new Term[num];
    }

    void read() {
        for (int i = 0; i < num; i++) {
            cin >> terms[i].coef >> terms[i].expo;
        }
    }

    void display() {
        int k = 0;

        for (int i = 0; i < num; i++) {
            cout << terms[i].coef << " " << terms[i].expo << endl;
        }
    }

    int sum(int x) {
        int sum = 0;
        for (int i = 0; i < num; i++) {
            sum += terms[i].coef * pow(x, terms[i].expo);
        }

        return sum;
    }

    Poly add(Poly &p2) {
        Poly *p3 = new Poly(num + p2.num);
        int i = 0, j = 0, k = 0;

        while (i < num && j < p2.num) {
            if (terms[i].expo < p2.terms[j].expo) {
                p3->terms[k++] = terms[i++];

            } else if (terms[i].expo > p2.terms[j].expo) {
                p3->terms[k++] = terms[j++];

            } else {
                p3->terms[k] = terms[i];
                p3->terms[k].expo = terms[i].expo + p2.terms[j].expo;
                k++;
                i++;
                j++;
            }
        }

        for (; i < num; i++) p3->terms[k++] = terms[i];
        for (; j < num; j++) p3->terms[k++] = p2.terms[j];
        p3->num = k;

        return *p3;
    }
};

int main() {
    Poly p1(5);
    p1.read();

    Poly p2(5);
    p2.read();

    // p1.display();
    // cout << endl;
    // p2.display();

    Poly p3 = p1.add(p2);
    p3.display();

    cout << endl;
    cout << p3.sum(5) << endl;
}
