#include<stdio.h>
#include<stdlib.h>
#define max 10
struct queue{
    int f;
    int r;
    int size;
    int *arr;
};
void enqueue(struct queue *q,int val)
{
    if(q->r==q->size-1){
printf("queue is full");
    }
    else{
        q->r=q->r+1;
        q->arr[q->r]=val;
        printf("enter the val");
        scanf("%d",&val);
        printf("enqueued element is %d",val);

    }
}
int dequeue(struct queue *q)
{
    int a=-1;
    if(q->r=q->f)
    printf("queue is empty");
    else
    {
        q->f++;
        a=q->arr[q->f];


    }
    return a;
}

int main()
{
    struct queue q;
    q.size=5;
    q.f=q.r=-1;
    q.arr=(int*)malloc(q.size*(sizeof(int)));
     enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1); 
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q)); 
    enqueue(&q, 45);
    enqueue(&q, 45);
    enqueue(&q, 45);
}