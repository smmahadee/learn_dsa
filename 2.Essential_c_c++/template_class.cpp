#include <iostream>

using namespace std;

template <class T>
class Arithmatic {
   public:
    T a;
    T b;

   public:
    Arithmatic(T a, T b);
    T add();
    T sub();
};

template <class T>
Arithmatic<T>::Arithmatic(T a, T b) {
    this->a = a;
    this->b = b;
}

template <class T>
T Arithmatic<T>::add() {
    return this->a + this->b;
}

template <class T>
T Arithmatic<T>::sub() {
    return this->a - this->b;
}

int main() {
    Arithmatic<int> a1(10, 5);

    cout << a1.add() << endl;
    cout << a1.sub() << endl;

    return 0;
}