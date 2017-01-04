#include <stdio.h>
#include <mem.h>

struct Student {

    // 定义三个成员
    int id;
    char name[200];
    int age;

};

int main() {

    // 普通数据类型 定义
    int i = 9;

    // 结构体 定义
    struct Student st = {9, "ruibo", 10};

    printf("%d %s %d\n", st.id, st.name, st.age);

    // 第一种操作成员的方法
    st.id= 8,
    st.age = 18,
    strcpy(st.name, "chenyan");

    // 只有对指针才可以用箭头
    struct Student * sT = &st;
    sT->id = 9;
    strcpy(sT->name, "dapang");
    sT->age = 10;

    printf("%d %s %d\n", st.id, st.name, st.age);
    return 0;
}