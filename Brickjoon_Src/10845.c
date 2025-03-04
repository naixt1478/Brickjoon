#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// doubly Linked List
typedef int data_t;
typedef struct node
{
    data_t data;
    struct node* next;
    struct node* prev;
} node;

typedef struct queue
{
    struct node* front;
    struct node* rear;
    int size;
} queue;

node* initnode(data_t data);
void enqueue(queue* qp1, data_t data);
void dequeue(queue* qp1);

queue q1;
int main(void)
{
    char c1[10];
    int N,a;
    scanf("%d", &N);
    while(N--)
    {
        scanf("%s", c1);
        if(strcmp(c1, "push") == 0)
        {
            scanf("%d", &a);
            enqueue(&q1, a);
        }
        else if(strcmp(c1, "front") == 0)
        {
            if(q1.size != 0) printf("%d\n", q1.front->data);
            else printf("-1\n");
        }
        else if(strcmp(c1, "back") == 0)
        {
            if(q1.size != 0) printf("%d\n", q1.rear->data);
            else printf("-1\n");
        }
        else if(strcmp(c1, "size") == 0)
            printf("%d\n", q1.size);
        else if(strcmp(c1, "empty") == 0)
        {
            if(q1.size == 0) printf("1\n");
            else printf("0\n");
        }
        else if(strcmp(c1, "pop") == 0)
        {
            if(q1.size == 0) printf("-1\n");
            else
            {
                printf("%d\n", q1.front->data);
                dequeue(&q1);
            }
        }
    }
    return 0;
}

node* initnode(data_t data)
{
    node* tmp = malloc(sizeof(node));
    if (tmp == NULL)
        return NULL;
    tmp->next = NULL;
    tmp->prev = NULL;
    tmp->data = data;
    return tmp;
}

void enqueue(queue* qp1, data_t data)
{
    node* tmp = initnode(data);
    tmp->prev = qp1->rear;
    if(qp1->size > 0) qp1->rear->next = tmp;
    else qp1->front = tmp;
    qp1->rear = tmp;
    qp1->size += 1;
}

void dequeue(queue* qp1)
{
    // empty queue not run dequeue
    if(qp1->size == 0) return;
    node* n1 = qp1->front;
    qp1->front = n1->next;
    if(qp1->size > 1) qp1->front->prev = NULL;
    else qp1->rear = NULL;
    free(n1);
    qp1->size -= 1;
}