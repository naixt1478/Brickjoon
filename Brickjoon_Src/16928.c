#include <stdio.h>
#include <stdlib.h>
// Linked List
typedef struct data_t
{
    int x,y;
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

void enqueue(queue* q1, data_t i1);
void dequeue(queue* q1);
queue* initqueue();
node* initnode(data_t i1);

int main(void)
{
    int N,M;
    scanf("%d %d", &N, &M);
    int** arr1 = (int**)malloc(sizeof(int*)*10);
    int** arr1 = (int**)malloc(sizeof(int*)*10);
    for(int i = 0; i < 10; i++)
    {
        arr1[i] = (int*)calloc(10, sizeof(int));
    }

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