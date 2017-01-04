#include <stdio.h>
#include <malloc.h>

struct Student {
    int id;
    int score;
};

struct Student * CreateStudent (void) {

    // 使用 malloc 函数返回结构体的首地址 使用 sizeof 函数测出结构体所占大小
    struct Student * ps = (struct Student *)malloc(sizeof(struct Student));

    ps->id = 2;
    ps->score = 3;

    return ps;

};

void ShowStudent (struct Student * ps){
    printf("id = %d, score = %d\n", ps->id, ps->score);
};


int main() {

    struct Student * ps;

    ps = CreateStudent();

    ShowStudent(ps);
    //ShowStudent_ins(ps_ins);

    return 0;
}

