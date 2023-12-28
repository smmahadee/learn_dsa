#include <climits>
#include <iostream>
#include <vector>

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

    for (int i = 0; i < size; i++) {
        if (low > v[i]) low = v[i];
        if (high < v[i]) high = v[i];
    }

    vector<int> freqV(high + 1, 0);

    for (int i = 0; i < size; i++) {
        freqV[v[i]]++;
    }

    // cout << endl;

    // for (int i = 0; i < freqV.size(); i++) {
    //     cout << i << " index " << freqV[i] << endl;
    // }

    for (int i = low; i < freqV.size(); i++) {
        if (freqV[i] > 1) {
            cout << i << " ";
        }
    }

    return 0;
}
