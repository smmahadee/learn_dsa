#include <iostream>

using namespace std;

int main() {
    vector<int> v;
    int size;
    cin >> size;
    for (int i = 0; i < size; i++) {
        int val;
        cin >> val;
        v.push_back(val);
    }

    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < v[i]; i++) {
        if (low > v[i]) low = v[i];
        if (high < v[i]) high = v[i];
    }

    int diff = low - 0;

    // find multiple missing element
    for (int i = 0; i < size; i++) {
        if (v[i] - i != diff) {
            while (diff < v[i] - i) {
                cout << i + diff << " ";
                diff++;
            }
        }
    }

    // find single missing element
    // for (int i = 0; i < size; i++) {
    //     if (v[i] - i != diff) {
    //         cout << i + diff << " ";
    //         diff = v[i] - i;
    //     }
    // }

    return 0;
}