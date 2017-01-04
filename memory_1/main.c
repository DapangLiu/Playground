#include <stdio.h>

// 这样写一旦f函数执行完毕 分配的内存也会消失
// 因此执行完毕后 j 就没有值了
// 如果想跨函数操作内存 必须用指针指向要操作的内存的首地址
int f (){

    int j = 20;
    return j;

};


int main() {

    int i = 10;

    i = f();

    printf("i: %d!\n", i);
    return 0;
}