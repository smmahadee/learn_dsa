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

    int totalOfArr = 0;
    int max = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (max < v[i]) max = v[i];
        totalOfArr += v[i];
        // cout << v[i] << " " << totalOfArr << endl;
    }

    int totalOfN = max * (max + 1) / 2;
    if (totalOfArr != totalOfN) {
        cout << totalOfN - totalOfArr;
    }

    return 0;
}