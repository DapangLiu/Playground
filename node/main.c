#include <stdio.h>

typedef struct Node {

    int data; //数据域 数据域可以非常复杂
    struct Node * pNode; // 指针域

}NODE, *PNODE;

int main() {
    printf("Hello, World!\n");
    return 0;
}