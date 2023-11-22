#include <iostream>

using namespace std;

int main() {
    int a = 20;
    int &r = a;

    r = 30;

    cout<< r;

    return 0;
}