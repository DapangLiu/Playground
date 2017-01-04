#include <stdio.h>
#include <mem.h>

struct Student {

    // 定义三个成员
    int id;
    char name[200];
    int age;

};

void show_Struct(struct Student st) {

    // 把结构体作为一个整体进行赋值 传递数据大小至少是208位 这样效率不高
    printf("%d %s %d\n", st.id, st.name, st.age);
}

void show_Struct_perfect(struct Student * st) {

    // 传的是四个字节的指针 四个字节等于三十二位
    printf("%d %s %d\n", st->id, st->name, st->age);
}

int main() {

    // 结构体 定义
    struct Student st = {9, "ruibo", 10};

    // 第一种操作成员的方法
    st.id = 8;
    st.age = 18;
    strcpy(st.name, "chenyan");

    // 低效率传参法
    show_Struct(st);

    // 只有对指针才可以用箭头
    struct Student * sT_pStr = &st;
    sT_pStr->id = 9;
    strcpy(sT_pStr->name, "dapang");
    sT_pStr->age = 10;

    // 比较好的传参方法
    show_Struct_perfect(sT_pStr);
    return 0;
}