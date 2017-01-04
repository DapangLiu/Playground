#include <stdio.h>

int main() {

    // 注意 无论指针指向的变量占几个字节 指针变量永远只占四个字节
    double * p;
    double x = 66.6;

    p = &x; // x 占八个字节， 一个字节是八位。 p 里面存放的是一个地址 八个字节里的第一个字节 共八位）

    double arr[3] = {1.1,2.2,3.3};
    double * q = & arr[0];
    printf("%p\n", q); // 这里用的 %p 就是以十六进制输出地址
}
