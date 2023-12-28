#include <iostream>

using namespace std;

int main() {
    // 1. we can compare two strings by "=" sign
    string s = "hello";
    s += "gello";
    // string s2 = "hello";

    // bool isEqual = s == s2;
    // if (isEqual) {
    //     cout << "True";
    // } else {
    //     cout << "false";
    // }

    // s.clear();
    // cout << s[1];

    // erase string
    // first parameter is position and second number of elements
    // s.erase(5, 2);

    // replace string
    // first : position, second: how many element will be removed, third: which
    // string will be inserted, fourth: string position of inserted element,
    // five: how many character will be inserted s.replace(0, 0,  "what");
    // s.replace(0, 0, "mehedi", 2, 2);

    // insert string
    // s.insert(2, "many", 2);

    // find string
    // int pos = s.find("gello");
    // if (pos != s.npos) {
    //     cout << pos;
    // } else {
    //     cout << "element not found";
    // }

    // cut some portion of a string -> substr
    // 1: from which position
    // 2: how many character
    // string s2 = s.substr(3, 5);

    // cout << " " << s2;

    return 0;
}