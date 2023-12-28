#include <iostream>

using namespace std;

long long int totalCharInSeq(char ch) {
    char val;
    cin >> val;

    if (val == '$') return 0;

    if (val == ch) {
        return 1 + totalCharInSeq(ch);
    } else {
        return 0 + totalCharInSeq(ch);
    }
}

int main() {
    char num;
    cin >> num;

    cout << totalCharInSeq(num);

    return 0;
}