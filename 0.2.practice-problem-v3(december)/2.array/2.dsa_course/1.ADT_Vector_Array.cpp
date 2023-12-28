#include <iostream>

using namespace std;

class myVector {
   private:
    vector<int> arr;

   public:
    void create(int num) {
        for (int i = 0; i < num; i++) {
            int val;
            cin >> val;
            arr.push_back(val);
        }
    }

    void display() {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insert(int index, int el) {
        if (index < 0 || index >= arr.size()) {
            cout << "invalid indexition" << endl;
            return;
        }

        arr.insert(arr.begin() + index, el);
    }

    void insertInSortedArr(int el) {
        // old
        // int i = arr.size() - 1;
        // while (i >= 0 && arr[i] > el) {
        //     arr[i + 1] = arr[i];
        //     i--;
        // }
        //  arr[i + 1] = el;

        // vector
        int i = arr.size() - 1;
        while (i >= 0 && arr[i] > el) {
            i--;
        }
        arr.insert(arr.begin() + i + 1, el);
    }

    void deleteEl(int index) {
        if (index < 0 || index >= arr.size()) {
            cout << "invalid indexition" << endl;
            return;
        }
        arr.erase(arr.begin() + index);
    }

    void lenearSearch(int el) {
        vector<int>::iterator it = arr.begin();
        vector<int>::iterator it2 = find(arr.begin(), arr.end(), el);
        if (it2 != arr.end()) {
            cout << distance(it, it2);
        } else {
            cout << "element not found";
        }
    }

    void binarySearch(int el) {
        int low = 0;
        int high = arr.size();

        while (low < high) {
            int middle = (low + high) / 2;
            int middleEl = arr[middle];

            if (middleEl == el) {
                cout << middle;
                break;
            } else if (middleEl > el) {
                high--;
            } else {
                low++;
            }
        }
        if (low >= high) {
            cout << "element not found";
        }
    }

    void reverseArr() {
        // static array technique
        // int first = 0;
        // int last = arr.size() - 1;

        // while (first < last) {
        //     swap(arr[first], arr[last]);
        //     first++;
        //     last--;
        // }

        // vector method
        reverse(arr.begin(), arr.end());
    }

    vector<int> mergeArray(vector<int> arr2) {
        vector<int> newArr;

        // for (int val : arr2) {
        //     cout << val << " ";
        // }

        int i = 0, j = 0;

        while (i < arr.size() && j < arr2.size()) {
            if (arr[i] == arr[j]) {
                newArr.push_back(arr[i++]);
                j++;
            } else if (arr[i] < arr2[j]) {
                newArr.push_back(arr[i++]);
            } else {
                newArr.push_back(arr2[j++]);
            }
        }

        while (i < arr.size()) newArr.push_back(arr[i++]);
        while (j < arr2.size()) newArr.push_back(arr[j++]);

        for (int val : newArr) {
            cout << val << " ";
        }

        return newArr;
    }
};

int main() {
    myVector v;
    v.create(3);
    vector<int> v2;
    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);
    // v.display();
    // v.insert(1, 10);
    // v.deleteEl(0);

    // v.lenearSearch(3);
    // v.binarySearch(3);
    // v.reverseArr();
    // v.insertInSortedArr(2);
    v.mergeArray(v2);
    // v.display();

    return 0;
}  