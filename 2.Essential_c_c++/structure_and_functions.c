#include <stdio.h>

struct Rectangle {
    int length;
    int height;
};

void changeLength(struct Rectangle* r, int l) { r->length = l; }

int main() {
    struct Rectangle r1 = {10, 5};

    changeLength(&r1, 20);

    printf("%d", r1.length);

    return 0;
}