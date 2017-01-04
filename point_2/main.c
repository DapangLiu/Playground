#include <stdio.h>

int main() {
    // 一维数组名 a 是一个指针常量 （不可被改变），它指向的是第一个元素
    int a[5] = {1,2,3,4,5};

    // 因此这个关系是成立的
    a[3] == *(3+a);

    printf("%d\n", *(3+a));

    printf("%d\n", a+1);
    printf("%d\n", a+2);
    printf("%d\n", *a+3);


    return 0;
}