#include <stdio.h>
#include <stdlib.h>
// Doubly Linked List
typedef struct data_t
{
    int d1,d2;
} data_t;

typedef struct node
{
    data_t data;
    struct node* next;
    struct node* prev;
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
    queue* q1 = initqueue();
    data_t a = {10,20};
    enqueue(q1,a);
    return 0;
}

queue* initqueue()
{
    queue* tmp = malloc(sizeof(queue));
    if (tmp == NULL)
    {
        return NULL;
    }
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
    tmp->prev = NULL;
    return tmp;
}

void enqueue(queue* q1, data_t i1)
{
    node* tmp = initnode(i1);
    if(q1->size == 0)
    {
        q1->back = tmp;
        q1->front = tmp;
        q1->size = 1;
        return;
    }
    q1->back->next = tmp;
    tmp->prev = q1->back;
    q1->back = tmp;
    q1->size += 1;
}

void dequeue(queue* q1)
{
    if(q1->size == 0) return;
    node* tmp = q1->front;
    q1->front = q1->front->next;
    q1->front->prev = NULL;
    q1->size -= 1;
    if(q1->size == 0) q1->back = NULL;
    free(tmp);
}