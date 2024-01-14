#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data_t
{
    long long int i1,i2;
} data_t;

typedef struct node
{
    data_t data;
    struct node* next;
} node;

typedef struct queue
{
    struct node* front;
    struct node* back;
    int size;
} queue;


void enqueue(queue*,data_t);
void dequeue(queue*);
queue* initqueue();
node* initnode(data_t);
int main(void)
{
    int S = -1;
    long long int A,B;
    scanf("%lld %lld", &A, &B);
    data_t d1 = {A, 0};
    queue* q1 = initqueue();
    enqueue(q1, d1);
    while(q1->front != NULL)
    {
        data_t d2 = q1->front->data;
        dequeue(q1);
        if(d2.i1 == B)
            S = (S == -1 ? d2.i2+1 : min(S,d2.i2+1));
        if(d2.i1*2 <= B)
        {
            data_t d3 = {d2.i1*2, d2.i2+1};
            enqueue(q1,d3);
        }
        if(d2.i1*10+1 <= B)
        {
            data_t d3 = {d2.i1*10+1, d2.i2+1};
            enqueue(q1,d3);
        }
    }
    printf("%d", S);
    return 0;
}

queue* initqueue()
{
    queue* tmp = malloc(sizeof(queue));
    if (tmp == NULL)
    {
        return NULL;
    }
    tmp->size = 0;
    tmp->front = NULL;
    tmp->back = NULL;
    return tmp;
}

node* initnode(data_t i1)
{
    node* tmp = malloc(sizeof(node));
    if (tmp == NULL)
    {
        return NULL;
    }
    tmp->next = NULL;
    tmp->data = i1;
    return tmp;
}

void enqueue(queue* q1, data_t i1)
{
    node* tmp = initnode(i1);
    if(q1->size == 0)
    {
        q1->back = tmp;
        q1->front = tmp;
        q1->size += 1;
    }
    else
    {
        q1->back->next = tmp;
        q1->back = tmp;
        q1->size += 1;
    }
}

void dequeue(queue* q1)
{
    // empty queue not run dequeue
    if(q1->size == 0) return;
    node* tmp = q1->front;
    q1->front = q1->front->next;
    if(tmp->next == NULL)
        q1->back = NULL;
    q1->size -= 1;
    free(tmp);
    tmp = NULL;
}

