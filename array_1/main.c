#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

// 再强调一遍 结构体是数据类型 名字叫 Arr 并没有分配内存
struct Arr {
    int * pBase; //存储的时数组第一个元素的地址
    int len; // 数组所能容纳的最大元素的个数
    int cnt; // 当前数组有效元素的个数
};

// 初始化
void init_arr(struct Arr * pArr, int length){

    // 开辟内存空间
    pArr->pBase = (int *) malloc(sizeof(int) * length);

    // 分配内存失败
    if (NULL == pArr->pBase) {
        printf("Error! Memory malloc fails!");
        exit(-1);
    } else {
        pArr->len = length;
        pArr->cnt = 0;
        }
    return; // 给使用的人一个提示

};

bool is_full(struct Arr * pArr) {

    if (pArr->cnt == pArr->len)
        return true;
    else
        return false;
};

// 判断数组是否为空
bool is_empty(struct Arr * pArr){

    if (0 == pArr->cnt)
        return true;
    else
        return false;
};


// 追加
bool append_arr(struct Arr * pArr, int val) {

    // 如果满了 就返回 false
    if (is_full(pArr)) {
        printf("Cannot append more content in this array.\n");
        return false;
    } else {
        pArr->pBase[pArr->cnt] = val;
        ++pArr-> cnt;
    }
    return true;
};

// 需要准确的定义什么是 pos 以及是在指定元素的之前还是之后插入
// 在这里 我们用的是之前 pos 指的是下标
bool insert_arr(struct Arr * pArr, int pos, int val) {

    int i;

    // 如果满了 返回 false
    if (is_full(pArr))
        return false;

    // 如果 pos 是一个负数 或者 pos 插入的位置前没有值 返回 false
    if (pos<1 || pos>pArr->cnt+1)
        return false;

    for (i = pArr->cnt-1; i>=pos-1; --i) {
        pArr->pBase[i+1] = pArr->pBase[i];
    }

    pArr->pBase[pos-1] = val;
    ++pArr->cnt; // 别忘了对个数的操作

    return true;
};

// 删除
// 这里的点在于 你用什么方法去返回被删除的值
// 因为删除有可能成功有可能失败 如果把函数定义成 int 类型 那删除失败就没办法返回了
bool delete_arr(struct Arr * pArr, int pos, int * del_value) {

    if (is_empty(pArr))
        return false;
    if (pos<1 || pos>pArr->cnt)
        return false;

    int i;

    // 先赋值
    *del_value = pArr->pBase[i-1];

    // 再移位
    for (i=pos; i<pArr->cnt; ++i) {

        pArr->pBase[i-1] = pArr->pBase[i];
    }

    // 别忘了操作个数
    --pArr->cnt;

    return true;
};
int get();



// 排序
void sort_arr(struct Arr * pArr) {

    int i, j, t;

    for (i=0; i<pArr->cnt;++i) {
        for (j=i+1;j<pArr->cnt;++j) {
            
            // 如果是大于 就移位 说明最终结果是一个升序
            if (pArr->pBase[i]>pArr->pBase[j]) {
                t = pArr->pBase[i];
                pArr->pBase[i] = pArr->pBase[j];
                pArr->pBase[j] = t;
            }
        }
    }
};

void show_arr(struct Arr * pArr){

    if (true == is_empty(pArr))
        printf("The array is empty.");
    else
        printf("The arrasy is: \n");
        for (int i=0; i<pArr->cnt; ++i)
            printf("%d ", pArr->pBase[i]);
        printf("\n");
};

// 倒置
void inverse_arr(struct Arr * pArr) {

    int i = 0;
    int j = pArr->cnt-1;
    int t;

    // 背下来
    while (i<j) {
        t = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[j];
        pArr->pBase[j] = t;
        ++i;
        --j;
    }

};


int main() {

    // 这个时候就分配内存了 里面都是垃圾数字
    struct Arr arr;
    int del_value;

    init_arr(&arr, 6);
    append_arr(&arr, 1);
    append_arr(&arr, 2);
    append_arr(&arr, 3);
    append_arr(&arr, 4);
    append_arr(&arr, 5);
    //append_arr(&arr, 4);

    if (insert_arr(&arr, 1, 99)){
        printf("Insert value success!\n");
        show_arr(&arr);
    } else {
        printf("Insert value fails!\n");
    };


    if (delete_arr(&arr, 1, &del_value)){
        printf("Delete value success!\n");
        show_arr(&arr);
    } else {
        printf("Delete value fails!\n");
    };

    inverse_arr(&arr);
    show_arr(&arr);

    sort_arr(&arr);
    show_arr(&arr);

    return 0;
}

