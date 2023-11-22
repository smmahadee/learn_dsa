#include <stdio.h>

struct Rectangle {
    int length;
    int height;
};

void initialize(struct Rectangle* r, int l, int h) {
    r->length = l;
    r->height = h;
};

int area(struct Rectangle r) { return r.length * r.height; };

void changeLength(struct Rectangle* r, int l) { r->length = l; }

int main() {
    struct Rectangle r1;

    initialize(&r1, 10, 5);
    area(r1);
    changeLength(&r1, 20);

    printf("%d", r1.length);

    return 0;
}