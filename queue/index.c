#include "queue.h"
#include <stdio.h>

int main() {
    int first = 1;
    int second = 2;
    int third = 3;
    int fourth = 4;
    int fiveth = 5;

    QUEUE *queueInstance = queue.createQueue();
    (*queueInstance).enqueue(queueInstance, &first);
    (*queueInstance).enqueue(queueInstance, &second);
    (*queueInstance).enqueue(queueInstance, &third);
    (*queueInstance).enqueue(queueInstance, &fourth);
    (*queueInstance).enqueue(queueInstance, &fiveth);

    queue.debugQueue(queueInstance);

    (*queueInstance).dequeue(queueInstance);

    queue.debugQueue(queueInstance);

    return 0;
}