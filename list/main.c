#include <stdio.h>
#include <malloc.h>

typedef struct Node {

    int data; // data field
    struct Node * pNext; // point field

} NODE, * pNODE;

pNODE create_list();

void traverse_list(pNODE pNode);

int main() {

    pNODE pHead = NULL;

    // create the list
    pHead = create_list();

    // traverse the list
    traverse_list(pHead);

    return 0;
}

// should not use a[i] format because the storage is not continuous
void traverse_list(pNODE pHead) {


    pNODE pNode = pHead->pNext; // pNode always equals to pNext

    // do the condition check at beginning
    while (NULL != pNode) {

        printf("%d \n", pNode->data);
        pNode = pNode->pNext; // assign the pNode to the next node

    }
    return;
}

// create the list, return the pointer of head
pNODE create_list(void) {

    int length;
    int i;
    int val;

    // use malloc to arrange the storage which could enable calling from other function
    pNODE pHead = (pNODE) malloc(sizeof(NODE));
    if (NULL == pHead) {
        printf("Init fails!");
        exit(-1);
    } else {
        printf("Init succeeds!");
    }

    // init pTail
    pNODE pTail = pHead;
    pTail->pNext = NULL; // if length = 0, pTail has to point to NULL


    printf("Please input the length:");
    scanf("%d", &length);

    // do the for loop
    for (i = 0; i < length; ++i) {

        printf("input the %d th value: ", i + 1);

        scanf("%d", &val);

        pNODE pNode = (pNODE) malloc(sizeof(NODE));
        if (NULL == pNode) {
            exit(-1);
        } else {
            pNode->data = val;
            pTail->pNext = pNode;
            pNode->pNext = NULL;
            pTail = pNode;
        }

    }

    return pHead;

}