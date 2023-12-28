#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> l;
    l.push_back(10);
    l.push_back(25);
    l.push_back(25);
    l.push_back(25);
    l.push_back(20);
    l.push_back(20);
    l.push_back(20);
    l.push_back(30);

    // insert element
    // l.insert(l.begin(), 15);
    // list<int>::iterator it = prev(l.end(), 1);
    // l.insert(it, 5);

    // erase an element
    // l.erase(next(l.begin()));

    // remove element by value
    // l.remove(10);

    // sort
    // l.sort(greater<int>());

    // unique value
    // l.unique();

    // print list reverse
    // for (list<int>::iterator i = prev(l.end()); i != prev(l.begin()); i--) {
    //     cout << *i << " ";
    // }

    cout << endl;

    // print list
    for (list<int>::iterator i = l.begin(); i != l.end(); i++) {
        cout << *i << " ";
    }

    return 0;
}