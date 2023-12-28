#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// find a pair with sum k in a sorted array

int main() {
    vector<int> v;
    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        int val;
        cin >> val;
        v.push_back(val);
    }

    int el;
    cin >> el;

    int i = 0;
    int j = v.size() - 1;

    while (i < j) {
        if (v[i] + v[j] == el) {
            cout << v[i++] << " + " << v[j--] << endl;
        } else if (v[i] + v[j] < el) {
            i++;
        } else {
            j--;
        }
    }

    return 0;
}
