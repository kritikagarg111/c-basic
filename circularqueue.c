#include <stdio.h>
#include <stdlib.h>

struct circularqueue {
    int f;      
    int r;      
    int size;   
    int *arr;   
} q;


void enqueue(struct circularqueue *q, int val);
int dequeue(struct circularqueue *q);

int main() {
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*)malloc(q.size * sizeof(int));  

    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1); 
    
    printf("Dequeuing element %d\n", dequeue(&q));  
    printf("Dequeuing element %d\n", dequeue(&q));  
    printf("Dequeuing element %d\n", dequeue(&q));  

    enqueue(&q, 45);
    enqueue(&q, 45);
    enqueue(&q, 45);  

    return 0;
}

void enqueue(struct circularqueue *q, int val) {
    
    if ((q->r + 1) % q->size == q->f) {
        printf("Queue is full\n");
    } else {
        q->r = (q->r + 1) % q->size;  
        q->arr[q->r] = val;  
        printf("Enqueued element is %d\n", val);  
    }
}

int dequeue(struct circularqueue *q) {
    int a = -1;
    if (q->f == q->r) {
        printf("Queue is empty\n");
    } else {
        q->f = (q->f + 1) % q->size;  
        a = q->arr[q->f]; 
         }

    return a;  

}

