#include <stdio.h>

typedef struct Student {

    int id;
    char name;
    int score;

} * PST, ST; // 可以这样 重复定义

int main() {

    ST st;

    PST pst = &st;

    printf("%d %s %d!\n", pst->id, pst->name, pst->score);

    return 0;
}