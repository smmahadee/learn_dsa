#include <iostream>

using namespace std;

class Array {
   private:
    int size;
    int length;
    int* A;

   public:
    Array() {
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int sz) {
        size = sz;
        length = 0;
        A = new int[sz];
    }

    ~Array() { delete[] A; }

    int getLength() { return length; }

    void display() {
        for (int i = 0; i < length; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    void append(int el) {
        A[length] = el;
        length++;
    }

    bool insert(int index, int el) {
        if (index > length) return false;

        for (int i = length; i > index; i--) {
            A[i] = A[i - 1];
        }

        A[index] = el;

        length++;
        return true;
    };

    bool remove(int index) {
        if (index >= length) return false;
        for (int i = index; i < length; i++) {
            A[i] = A[i + 1];
        }
        length--;

        return true;
    };

    int lenearSearch(int el) {
        int flag = -1;
        for (int i = 0; i < length; i++) {
            if (A[i] == el) {
                flag = i;
                break;
            }
        }

        return flag;
    }

    int binarySearch(int el) {
        int flag = -1;
        int low = 0;
        int high = length - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (A[mid] == el) {
                flag = mid;
                break;
            } else if (A[mid] > el) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return flag;
    }

    int getEl(int index) {
        if (index < 0 || index >= length) return -1;
        return A[index];
    }

    int setEl(int index, int el) {
        if (index < 0 || index >= length) return -1;
        A[index] = el;
        return A[index];
    }

    int maxArray() {
        int mx = INT_MIN;
        for (int i = 0; i < length; i++) {
            if (A[i] > mx) mx = A[i];
        }

        return mx;
    }

    int minArray() {
        int mn = INT_MAX;
        for (int i = 0; i < length; i++) {
            if (A[i] < mn) mn = A[i];
        }

        return mn;
    }

    long long int sum() {
        int sum = 0;
        for (int i = 0; i < length; i++) {
            sum += A[i];
        }

        return sum;
    }

    void reverseArray() {
        int i = 0;
        int j = length - 1;
        while (i < j) {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }

    void leftShift() {
        for (int i = 0; i < length; i++) {
            A[i - 1] = A[i];
        }

        A[length - 1] = 0;
    }

    void rightShift() {
        for (int i = length - 2; i >= 0; i--) {
            A[i + 1] = A[i];
        }

        A[0] = 0;
    }

    int isSorted() {
        int flag = 1;
        for (int i = 0; i < length - 1; i++) {
            if (A[i] > A[i + 1]) {
                flag = -1;
                break;
            }
        }

        return flag;
    }

    void insertElSortedPosition(int el) {
        int i = length - 1;
        while (A[i] > el) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = el;
        length++;
    }

    void swapPositiveNegativeNum() {
        int i = 0;
        int j = length - 1;

        while (i < j) {
            while (A[i] < 0) i++;
            while (A[j] >= 0) j--;
            if (i < j) swap(A[i], A[j]);
        }
    }

    Array* mergeArray(Array arr2) {
        int i = 0, j = 0, k = 0;
        Array* arr3 = new Array(length + arr2.length);

        while (i < length && j < arr2.length) {
            if (A[i] <= arr2.A[j]) {
                arr3->A[k++] = A[i];
                i++;
            } else {
                arr3->A[k++] = arr2.A[j];
                j++;
            }
        }

        for (; i < length; i++) {
            arr3->A[k++] = A[i];
        }

        for (; j < arr2.length; j++) {
            arr3->A[k++] = arr2.A[j];
        }

        arr3->length = length + arr2.length;

        return arr3;
    }

    Array* basicUnionSet(Array arr2) {
        Array* arr3 = new Array(length + arr2.length);
        int k = 0;

        for (int i = 0; i < length; i++) {
            arr3->A[k++] = A[i];
        }

        for (int i = 0; i < arr2.length; i++) {
            int j;
            for (j = 0; j < arr2.length; j++) {
                if (arr2.A[i] == A[j]) break;
            }

            if (j == arr2.length) {
                arr3->A[k++] = arr2.A[i];
            }
        }

        arr3->length = length + arr2.length;

        return arr3;
    }

    Array* optimizedUnionSet(Array arr2) {
        int i = 0, j = 0, k = 0;

        Array* arr3 = new Array(length + arr2.length);

        while (i < length && j < arr2.length) {
            if (A[i] < arr2.A[j]) {
                arr3->A[k++] = A[i];
                i++;
            } else if (arr2.A[j] < A[i]) {
                arr3->A[k++] = arr2.A[j];
                j++;
            } else {
                arr3->A[k++] = A[i];
                i++;
                j++;
            }
        }

        for (; i < length; i++) {
            arr3->A[k++] = A[i];
        }

        for (; j < arr2.length; j++) {
            arr3->A[k++] = arr2.A[j];
        }

        arr3->length = length + arr2.length;

        return arr3;
    }

    Array* basicIntersection(Array arr2) {
        int mx = max(length, arr2.length);
        int mn = min(length, arr2.length);

        int* maxArr = mx == length ? A : arr2.A;
        int* minArr = mn == length ? A : arr2.A;

        Array* arr3 = new Array(mx);
        int k = 0;

        for (int i = 0; i < mx; i++) {
            for (int j = 0; j < mn; j++) {
                if (maxArr[i] == minArr[j]) {
                    arr3->A[k++] = maxArr[i];
                }
            }
        }

        arr3->length = k;

        return arr3;
    }

    Array* optimizedIntersection(Array arr2) {
        int i = 0, j = 0, k = 0;

        Array* arr3 = new Array(length + arr2.length);

        while (i < length && j < arr2.length) {
            if (A[i] < arr2.A[j]) {
                i++;
            } else if (arr2.A[j] < A[i]) {
                j++;
            } else {
                arr3->A[k++] = A[i];
                i++;
                j++;
            }
        }

        arr3->length = k;

        return arr3;
    }

    Array* basicDifference(Array arr2) {
        Array* arr3 = new Array[length];
        int k = 0;
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < arr2.length; j++) {
                if (A[i] == arr2.A[j]) {
                    arr3->A[k++] = A[i];
                }
            }
        }

        arr3->length = k;

        return arr3;
    }

    Array* optimizedDifference(Array arr2) {
        int i = 0, j = 0, k = 0;

        Array* arr3 = new Array[length];

        while (i < length && j < arr2.length) {
            if (A[i] < arr2.A[j]) {
                arr3->A[k++] = A[i];
                i++;
            } else if (arr2.A[j] < A[i]) {
                j++;
            } else {
                i++;
                j++;
            }
        }

        arr3->length = k;

        return arr3;
    }
};

int main() {
    Array* arr;

    int size;
    cin >> size;
    arr = new Array(size);

    int arrLength = arr->getLength();

    for (int i = 0; i < arrLength; i++) {
        int el;
        cin >> el;
        arr->append(el);
    }

    // arr->display();

        // ADD AN ELEMENT TO THE LAST OF THE ARRAY
        // a.append(100);

        // INSERT ELEMENT TO SPECIFIC INDEX
        // a.insert(5, 500);

        // DELETE SPECIFIC INDEX ELEMENT
        // a.remove(4);

        // LENEAR SEARCH AN ELEMENT
        // int index = a.lenearSearch(30);
        // cout<<index;

        // binary search an element
        // int index = a.binarySearch(10);
        // cout << index;

        // get element by index
        // cout << a.getEl(3);

        // set(replace) element by index
        // a.setEl(3, 100);

        // GET MAX VALUE
        // cout << a.maxArray();

        // get minArray value
        // cout << a.minArray();

        // get total value
        // cout << a.sum();

        // reverse array
        // a.reverseArray();
        // a.leftShift();
        // a.rightShift();

        // check if array sorted or not
        // int result = a.isSorted();
        // cout << result;

        // Insert element in a sorted position of a sorted array
        // a.insertElSortedPosition(45);

        // left side all negative number and right side all positive number
        // a.swapPositiveNegativeNum();

        // merging array and return third array with all elements
        // int* newArr = a.mergeArray(a.arr, a.length, b.arr, b.length);
        // for (int i = 0; i < a.length + b.length; i++) {
        //     cout << newArr[i] << " ";
        // }
        // delete[] newArr;

        // SET OPERATIONS

        // basic union sets between two array
        // int* newArr = a.basicUnionSet(a.arr, a.length, b.arr, b.length);
        // for (int i = 0; i < a.length + b.length; i++) {
        //     cout << newArr[i] << " ";
        // }
        // delete[] newArr;

        // optimized union sets between two sorted array
        // int* newArr = a.optimizedUnionSet(a.arr, a.length, b.arr, b.length);
        // for (int i = 0; i < a.length + b.length; i++) {
        //     cout << newArr[i] << " ";
        // }
        // delete[] newArr;

        // basic intersection
        // int* newArr = a.basicIntersection(a.arr, a.length, b.arr, b.length);
        // for (int i = 0; i < a.length + b.length; i++) {
        //     cout << newArr[i] << " ";
        // }
        // delete[] newArr;

        // optimized intersection
        // int* newArr = a.optimizedIntersection(a.arr, a.length, b.arr,
        // b.length); for (int i = 0; i < a.length + b.length; i++) {
        //     cout << newArr[i] << " ";
        // }
        // delete[] newArr;

        // basic difference set
        // int* newArr = a.basicDifference(a.arr, a.length, b.arr, b.length);
        // for (int i = 0; i < a.length + b.length; i++) {
        //     cout << newArr[i] << " ";
        // }
        // delete[] newArr;

        // optimized difference set
        // int* newArr = a.optimizedDifference(a.arr, b.arr);
        // for (int i = 0; i < a.length + b.length; i++) {
        //     cout << newArr[i] << " ";
        // }
        // delete[] newArr;

        // DISPLAY THE ENITER ARRAY
        // cout << endl;
        // a.display();
        // cout << endl;
        // b.display();

        return 0;
}
