#include <iostream>

using namespace std;

class Base {
   public:
    int val;
    int val2;
    // int *arr = new int[3];

   public:
    Base() {
        val = 10;
        val2 = 20;
    };
};

void test(vector<int> *v) {

     (*v)[0] = 1000;
 }

int main() {
    int arr[3] = {1, 2, 3};
    vector<int> v(arr, arr + 3);
    test(&v);

    cout << v[0];

    return 0;
}
