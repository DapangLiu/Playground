#include <stdio.h>

void show_Bit(int ** q) {

    // 指针都是4个字节 一个字节是8位 8位十六进制整数是32位二进制整数
    // 1111 + 1= 1 0000 = 16
    *q = (int *) 0xFFFFFFFF;
}


int main() {

    double i = 9.0;
    double * p = &i;

    printf("%p\n", p);
    // 这样操作其实是不安全的
    show_Bit(&p);
    printf("%p\n", p);

    printf("%lu\n", sizeof(p));

    return 0;
}