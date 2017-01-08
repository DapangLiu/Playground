#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Node {

    int data; // data field
    struct Node * pNext; // point field

} NODE, * pNODE;


// Declare
pNODE create_list();

void traverse_list(pNODE pNode);

bool is_empty(pNODE pHead);

int length_list(pNODE pHead);

bool insert_list(pNODE pHead, int pos, int val);

bool delete_list(pNODE pHead, int pos, int * pVal);

void sort_list(pNODE pHead, int length);

// Main
int main() {

    int length = 0;

    int delete_val;

    pNODE pHead = NULL;

    // create the list
    pHead = create_list();

    if (is_empty(pHead)) {
        printf("the list is empty!");
    } else {
        // traverse the list
        traverse_list(pHead);
    }


    // show the length of the list
    length = length_list(pHead);
    printf("The length of the list is %d. \n", length);

    // sor the list
    sort_list(pHead, length);

    // traverse the list
    traverse_list(pHead);

    // insert
    insert_list(pHead, 3, 22);

    // traverse the list
    traverse_list(pHead);

    // delete
    if (delete_list(pHead, 3, &delete_val)) {
        printf("delete seccess!\n");
    } else {
        printf("delete fails!\n");
    }

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



bool is_empty(pNODE pHead) {

    if(pHead->pNext == NULL) {
        return true;
    } else {
        return false;
    }
}

int length_list(pNODE pHead) {

    int cnt = 0;
    pNODE pNode = pHead->pNext; // pNode always equals to pNext

    // do the condition check at beginning
    while (NULL != pNode) {
        ++cnt;
        pNode = pNode->pNext; // assign the pNode to the next node
    }
    return cnt;
}

// before the pos
bool insert_list(pNODE pHead, int pos, int val) {

    int i = 0;
    pNODE p = pHead;

    // Below two condition validation is counter each other
    while (NULL!=p && i<pos-1) {

        p = p->pNext; // point to
        ++i;
    }

    if (i>pos-1 || NULL == p) {

        return false;
    }

    pNODE  pNew = (pNODE) malloc(sizeof(NODE));

    if(NULL == pNew) {

        printf("malloc fails!");
        exit(-1);
    }

    pNew->data = val;
    pNODE q = p->pNext; // temp storage
    p->pNext = pNew;
    pNew->pNext = q;

    return true;

}


void sort_list(pNODE pHead, int length) {

    int i,j,t;
    pNODE p,q;


    for (i=0,p=pHead->pNext; i<length-1; ++i, p=p->pNext) {


        for (j=i+1,q=p->pNext;j<length;++j,q=q->pNext) {
             if (p->data >q->data) {


                 t = p->data;
                 p->data = q->data;
                 q->data = t;
             }
        }
    }

    return;
}

bool delete_list(pNODE pHead, int pos, int * pVal) {


    int i = 0;
    pNODE p = pHead;

    // Below two condition validation is counter each other
    while (NULL!=p->pNext && i<pos-1) {

        p = p->pNext; // point to
        ++i;
    }

    if (i>pos-1 || NULL == p) {

        return false;
    }

    // store the original data and pointer
    pNODE q = p->pNext;
    * pVal = q->data;

    p->pNext = p->pNext->pNext;
    free(q);
    q = NULL;

    return true;

}