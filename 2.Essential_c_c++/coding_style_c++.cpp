#include <iostream>

using namespace std;

class Rectangle {
   private:
    int length;
    int height;

   public:
    Rectangle(int l, int h) {
        this->length = l;
        this->height = h;
    };

    int area() { return this->length * this->height; };

    void changeLength(int l) { this->length = l; }

    int getLength() { return this->length; }
};

int main() {
    Rectangle r1(10, 5);

    cout << r1.area() << endl;

    r1.changeLength(20);

    cout << r1.getLength() << endl;

    return 0;
}