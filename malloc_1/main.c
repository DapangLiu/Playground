#include <stdio.h>
#include <malloc.h>

int main() {

    // 静态分配内存
    int a[5] = {1,2,3,4,5};

    int len;

    printf("Please input the length of the array: len = ");

    scanf("%d", &len);

    // 注意 这一步会开辟20个字节的空间 但是 malloc 函数只会返回第一个字节的地址
    // 但是直到第一个字节地址没什么意义 （干地址） 因为你不知道存储的是什么类型的变量 换句话说 不知道大小
    // 因此还需要指定 变量类型 这就是强制类型转换在这里的意义
    int *pArr = (int *) malloc (sizeof(int) * len);
    //printf("%d %d\n", *pArr, pArr[1]);

//    *pArr = 4; // 类似于 a[0] =4
//    pArr[1] = 10; // 类似于 a[1] = 10

    for (int i=0; i<5; ++i) {
        // 完成了一个输入
        scanf("%d\n", &pArr[i]);
    }

    for (int i=0; i<5; ++i) {
        // 完成输出
        //printf("%d\n", pArr[i]);
        printf("%d\n", *(pArr+i));
        printf("%d\n", a[i]);
    }

    // 可以在程序运行中释放
    free(pArr);

    return 0;
}