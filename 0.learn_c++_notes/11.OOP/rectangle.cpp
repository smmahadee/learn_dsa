#include <iostream>

using namespace std;

class Rectagle {
   private:
    int length;
    int height;

   public:
    int area() { return length * height; };
    void setLength(int length) { this->length = length; };
    void setHeight(int height) { this->height = height; };

    Rectagle(int length, int height) {
        this->length = length;
        this->height = height;
    }
};

int main() {
    Rectagle r1(10, 5);
    Rectagle * p = &r1;


    cout << p->area() << endl;
    return 0;
}