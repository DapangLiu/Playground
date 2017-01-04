#include <stdio.h>

void show_Array(int pInt[], int i) {
    // *pInt[5] = * &a[0] = a[0]
    // pInt[i] = pInt[0+i] = *(pInt + i) = *(a+i)
   pInt[i-1] = -1;
}

int main() {
    int a [6] = {1,2,3,4,5,6};
    show_Array(a, 6);
    // a = &a[0]
    printf("%d\n", a[5]);
    return 0;
}

