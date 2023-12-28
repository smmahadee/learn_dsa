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

    vector<int> freqV(high + 1, 0);

    for (int i = 0; i < size; i++) {
        freqV[v[i]]++;
    }

    for (int i = low; i < freqV.size(); i++) {
        if (freqV[i] == 0) {
            cout << i << " ";
        }
    }

    return 0;
}