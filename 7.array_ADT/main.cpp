#include <iostream>

using namespace std;

class Array {
   public:
    int* arr;
    int size;
    int length;

    void init(int* arr, int length, int size) {
        // cin >> size >> length;
        // arr = new int[size];
        // for (int i = 0; i < length; i++) {
        //     cin >> arr[i];
        // }

        this->size = size;
        this->length = length;
        this->arr = new int[size];

        for (int i = 0; i < length; i++) {
            this->arr[i] = arr[i];
        }
    }

    void display() {
        for (int i = 0; i < length; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void append(int el) {
        arr[length] = el;
        length++;
    }

    bool insert(int index, int el) {
        if (index > length) return false;

        for (int i = length; i > index; i--) {
            arr[i] = arr[i - 1];
        }

        arr[index] = el;

        length++;
        return true;
    };

    bool remove(int index) {
        if (index >= length) return false;
        for (int i = index; i < length; i++) {
            arr[i] = arr[i + 1];
        }
        length--;

        return true;
    };

    int lenearSearch(int el) {
        int flag = -1;
        for (int i = 0; i < length; i++) {
            if (arr[i] == el) {
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

            if (arr[mid] == el) {
                flag = mid;
                break;
            } else if (arr[mid] > el) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return flag;
    }

    int getEl(int index) {
        if (index < 0 || index >= length) return -1;
        return arr[index];
    }

    int setEl(int index, int el) {
        if (index < 0 || index >= length) return -1;
        arr[index] = el;
        return arr[index];
    }

    int max() {
        int mx = INT_MIN;
        for (int i = 0; i < length; i++) {
            if (arr[i] > mx) mx = arr[i];
        }

        return mx;
    }

    int min() {
        int mn = INT_MAX;
        for (int i = 0; i < length; i++) {
            if (arr[i] < mn) mn = arr[i];
        }

        return mn;
    }

    long long int sum() {
        int sum = 0;
        for (int i = 0; i < length; i++) {
            sum += arr[i];
        }

        return sum;
    }

    void reverseArray() {
        int i = 0;
        int j = length - 1;
        while (i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    void leftShift() {
        for (int i = 0; i < length; i++) {
            arr[i - 1] = arr[i];
        }

        arr[length - 1] = 0;
    }

    void rightShift() {
        for (int i = length - 2; i >= 0; i--) {
            arr[i + 1] = arr[i];
        }

        arr[0] = 0;
    }

    int isSorted() {
        int flag = 1;
        for (int i = 0; i < length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                flag = -1;
                break;
            }
        }

        return flag;
    }

    void insertElSortedPosition(int el) {
        int i = length - 1;
        while (arr[i] > el) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = el;
        length++;
    }

    void swapPositiveNegativeNum() {
        int i = 0;
        int j = length - 1;

        while (i < j) {
            while (arr[i] < 0) i++;
            while (arr[j] >= 0) j--;
            if (i < j) swap(arr[i], arr[j]);
        }
    }

    int* mergeArray(int* a, int m, int* b, int n) {
        int i = 0, j = 0, k = 0;
        int* newArr = new int[length * 2];

        while (i < m && j < n) {
            if (a[i] <= b[j]) {
                newArr[k++] = a[i];
                i++;
            } else {
                newArr[k++] = b[j];
                j++;
            }
        }

        for (; i < m; i++) {
            newArr[k++] = a[i];
        }

        for (; j < n; j++) {
            newArr[k++] = b[j];
        }
    }
};

int main() {
    Array a;
    Array b;

    // ARRAY INITIALIZATION
    int a1[] = {10, 20, 30, 40, 50};
    a.init(a1, 5, 20);

    int a2[] = {15, 25, 35, 45, 55};
    b.init(a2, 5, 20);

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
    // cout << a.max();

    // get total value
    // cout << a.min();

    // get min value
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
    int * newArr = a.mergeArray(a.arr, a.size, b.arr, b.size);
    for (int i = 0; i < ; i++)
    {
        /* code */
    }
    

    // DISPLAY THE ENITER ARRAY
    cout << endl;
    a.display();
    cout << endl;
    b.display();

    return 0;
}
