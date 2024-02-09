#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data_t
{
    int bef,cur;
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

void pre_solve2(int** ppi1, int sval, int bef, int cur);

int n;
int main(void)
{
    int a,b;
    scanf("%d", &n);
    int** ppi1 = (int**)malloc(sizeof(int) * (n+1));
    for(int i = 0; i <= n; i++) ppi1[i] = (int*)calloc(n+1, sizeof(int));
    for(int i = 0; i < n-1; i++)
    {
        scanf("%d %d", &a, &b);
        ppi1[a][b] = 1;
        ppi1[b][a] = 1;
    }
    for(int i = 2; i <= n; i++)
    {
        pre_solve2(ppi1, i, 0, 1);
    }
}

void pre_solve2(int** ppi1, int sval, int bef, int cur)
{
    queue* q1 = initqueue();
    enqueue(q1, (data_t){bef, cur});
    while(q1->size != 0)
    {
        data_t d1 = q1->front->data;
        dequeue(q1);
        if(d1.cur == sval)
        {
            printf("%d\n", d1.bef);
            while(q1->size != 0) dequeue(q1);
            break;
        }
        for(int i = n; i >= 1; i--)
        {
            if(ppi1[d1.cur][i] == 1 && i != d1.bef && i != d1.cur)
                enqueue(q1, (data_t){d1.cur, i});
        }
    }
}

queue* initqueue()
{
    queue* tmp = malloc(sizeof(queue));
    if (tmp == NULL)
        return NULL;
    tmp->size = 0;
    tmp->front = NULL;
    tmp->back = NULL;
    return tmp;
}

node* initnode(data_t i1)
{
    node* tmp = malloc(sizeof(node));
    if (tmp == NULL)
        return NULL;
    tmp->next = NULL;
    tmp->data = i1;
    return tmp;
}

void enqueue(queue* q1, data_t i1)
{
    node* tmp = initnode(i1);
    if(q1->size == 0)
        q1->front = tmp;
    else
        q1->back->next = tmp;
    q1->size += 1;
    q1->back = tmp;
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