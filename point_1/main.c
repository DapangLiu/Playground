#include <stdio.h>

// 定义了一个形参，名字为i。不是*i。*的意思是接受的参数变量类型是指针（地址），
// 更准确的说，形参的的变量类型应该是 int*
void f(int *i){
    // *i 就是 i，因此就是一个简单的变量赋值
    *i = 100;
}

int main() {
    int i = 9;
    f(&i);
    printf("%d\n",i);
    return 0;
}