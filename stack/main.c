#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node * pNext;
} NODE, * PNODE;

typedef struct Stack {
    PNODE pTop;
    PNODE pBottom;
} STACK, *PSTACK;

void initStack(PSTACK pStack);

void pushStack(PSTACK pStack, int val);

void traverseStack(PSTACK pStack);

bool pop(PSTACK pStack, int *pInt);

bool is_empty(PSTACK pStack);

void clear (PSTACK pSTACK);

int main() {

    STACK S; // create a peice of RAM for STACK

    int val;

    initStack(&S); // the goal of this function is, top & bottom both point to a null pointer
    pushStack(&S, 1);
    pushStack(&S, 2);
    pushStack(&S, 3);
    pushStack(&S, 4);
    pushStack(&S, 5);
    pushStack(&S, 6);

    if (pop(&S, &val)) {
        printf("pop success!\n");
        printf("poped element is %d .\n", val);
    } else {
        printf("pop fails!\n");
    } // it is possible that there is no element in the stack so we need a bool return

    traverseStack(&S);

    clear(&S);

    traverseStack(&S);

    return 0;
}

bool is_empty (STACK * pStack) {

    if (pStack->pTop == pStack->pBottom) {
        return true;
    } else {
        return false;
    }
}

// output, return the outputed results and bool
bool pop(PSTACK pStack, int *pInt) {

    if (is_empty(pStack)) {
        return false;
    } else {

        // have to store the previous info first because you need them afterwards
        PNODE r = pStack->pTop;
        *pInt = r->data;
        pStack->pTop = r->pNext;
        free(r);
        r = NULL;

        return true;
    }

}

void traverseStack(PSTACK pStack) {

    PNODE p = pStack->pTop;

    printf("the elements in the stack are: \n");

    while (p != pStack->pBottom) {
        printf("%d ", p->data);
        p = p->pNext;
    }

    printf("\n");
    return;
}

void pushStack(PSTACK pStack, int val) {

    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = val;

    pNew->pNext = pStack->pTop; // Must be the top; Link the new Node to the previous node

    pStack->pTop = pNew; // Link the top to the new node
}

void initStack(PSTACK pStack) {

    pStack->pTop = (PNODE)malloc(sizeof(PNODE));

    if (NULL == pStack->pTop) {
        exit(-1);
        printf("fails!");
    } else {
        pStack->pBottom = pStack->pTop;
        pStack->pTop->pNext = NULL; // remember to set the pNext to NULL
    }
}


void clear (PSTACK pStack) {

    if (is_empty(pStack)) {
        return;
    } else {

        PNODE p = pStack->pTop;
        PNODE q = NULL;

        while (p != pStack->pBottom) {

            // store first, free second
            q = p->pNext;
            free(p);
            p = q;
        }
        pStack->pTop = pStack->pBottom;
    }
}