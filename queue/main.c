#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Queue {

    int * pBase;
    int front;
    int rear;

} QUEUE;


void init(QUEUE *pQueue);

bool en_queue(QUEUE *pQueue, int val);

void traverse_queue(QUEUE *pQueue);

bool isFull_queue(QUEUE *pQueue);

bool del_queue(QUEUE *pQueue, int * pVal);

bool isEmpty_queue(QUEUE *pQueue);

int main() {

    QUEUE Q; // here there is no instance of the Queue

    int del_val;

    init(&Q);

    en_queue(&Q, 1);
    en_queue(&Q, 2);
    en_queue(&Q, 3);
    en_queue(&Q, 4);
    en_queue(&Q, 5);
    en_queue(&Q, 6); // would not enter the queue

    traverse_queue(&Q);

    del_queue(&Q, &del_val);

    traverse_queue(&Q);

    printf("the deleted element is %d. \n", del_val);

    return 0;
}

void init(QUEUE *pQueue) {

    pQueue->pBase = (int*)malloc(sizeof(int) * 6);
    pQueue->front = 0;
    pQueue->rear = 0;

}

bool en_queue(QUEUE *pQueue, int val) {

  if (isFull_queue(pQueue)) {
      return false;
  } else {

      pQueue->pBase[pQueue->rear] = val;
      pQueue->rear = (pQueue->rear+1) % 6; // ++1 % length of the queue

      return true;
  }
}

void traverse_queue(QUEUE *pQueue) {

    int i = pQueue->front; // init the loop

    while (i != pQueue->rear) {
        printf("%d ", pQueue->pBase[i]);
        i = (i+1) % 6;
    }
    printf("\n");
    return;
}

bool isFull_queue(QUEUE *pQueue) {

    if ((pQueue->rear + 1) % 6 == pQueue->front) {
        return true;
    } else {
        return false;
    }
}

bool del_queue(QUEUE *pQueue, int * pVal) {

    if (isEmpty_queue(pQueue)) {
        return false;
    } else {

        *pVal = pQueue->pBase[pQueue->front];
        pQueue->front = (pQueue->front + 1) % 6;

        return true;
    }

}

bool isEmpty_queue(QUEUE *pQueue) {

    if (pQueue->front == pQueue->rear) {
        return true;
    } else {
        return false;
    }
}