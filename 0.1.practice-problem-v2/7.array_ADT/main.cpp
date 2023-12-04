#include <iostream>

using namespace std;

class Array {
   private:
    int size;
    int length;
    int* A;

   public:
    Array(int size) {
        this->size = size;
        length = 0;
        A = new int[size];
    }

    int getLength() { return length; }

    void push_back(int el) { A[length++] = el; }

    void create() {
        int length;
        cin >> length;
        for (int i = 0; i < length; i++) {
            int x;
            cin >> x;
            this->push_back(x);
        }
    }

    void display() {
        for (int i = 0; i < length; i++) {
            cout << this->A[i] << " ";
        }

        cout << endl;
    }

    Array* merge(Array arr2) {
        Array* arr3 = new Array(this->length + arr2.length);

        int i = 0, j = 0, k = 0;

        while (i < this->length && j < arr2.length) {
            if (this->A[i] < arr2.A[j]) {
                arr3->A[k++] = this->A[i++];
            } else {
                arr3->A[k++] = arr2.A[j++];
            }
        }

        for (; i < this->length; i++) arr3->A[k++] = this->A[i];
        for (; j < arr2.length; j++) arr3->A[k++] = arr2.A[j];

        arr3->length = k;

        return arr3;
    }

    Array* unionSet(Array arr2) {
        Array* arr3 = new Array(this->length + arr2.length);

        int i = 0, j = 0, k = 0;

        while (i < this->length && j < arr2.length) {
            if (this->A[i] < arr2.A[j]) {
                arr3->A[k++] = this->A[i++];
            } else if (this->A[i] > arr2.A[j]) {
                arr3->A[k++] = arr2.A[j++];
            } else {
                arr3->A[k++] = this->A[i++];
                j++;
            }
        }

        for (; i < this->length; i++) arr3->A[k++] = this->A[i];
        for (; j < arr2.length; j++) arr3->A[k++] = arr2.A[j];

        arr3->length = k;

        return arr3;
    }

    Array* intersectionSet(Array arr2) {
        Array* arr3 = new Array(this->length + arr2.length);

        int i = 0, j = 0, k = 0;

        while (i < this->length && j < arr2.length) {
            if (this->A[i] < arr2.A[j]) {
                i++;
            } else if (this->A[i] > arr2.A[j]) {
                j++;
            } else {
                arr3->A[k++] = this->A[i++];
                j++;
            }
        }

        arr3->length = k;

        return arr3;
    }
};

int main() {
    Array arr(20);
    arr.create();
    // arr.display();

    Array arr2(10);
    arr2.create();
    // arr2.display();


    // Array* arr3 = arr.merge(arr2);
    // Array* arr3 = arr.unionSet(arr2);
    Array* arr3 = arr.intersectionSet(arr2);
    arr3->display();

    return 0;
}