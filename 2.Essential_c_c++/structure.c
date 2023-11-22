#include <stdio.h>

struct Card {
    int face;
    int shape;
    int color;
};

struct Student {
    char name[100];
    int roll;
};

int main() {
    struct Card deck[5];
    deck[0].face = 0;
    deck[0].shape = 1;
    deck[0].color = 2;

    struct Student rahim = {"Rahim", 23};

    printf("%s %d", rahim.name, rahim.roll);

    return 0;
}