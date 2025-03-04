#define min(x, y) (((x) < (y)) ? (x) : (y))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
// Linked List
typedef struct data_t
{
    int x,L;
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
    int N,M,a,b,i1 = INT_MAX;
    scanf("%d %d", &N, &M);
    int* arr1 = (int*)calloc(101,sizeof(int));
    int* arr2 = (int*)malloc(101*sizeof(int));
    memset(arr2, -1, sizeof(int) * 101);
    for(int i = 0; i < N+M; i++)
    {
        scanf("%d %d", &a, &b);
        arr1[a] = b;
    }
    data_t root = {1,0};
    queue* q1 = initqueue();
    enqueue(q1, root);
    while(q1->front != NULL)
    {
        data_t d1 = q1->front->data;
        dequeue(q1);
        while(arr1[d1.x] != 0)
        {
            arr2[d1.x] = (arr2[d1.x] == -1 ? d1.L : min(arr2[d1.x], d1.L));
            d1.x = arr1[d1.x];
        }
        if(d1.x == 100)
        {
            i1 = min(d1.L, i1);
            continue;
        }
        for(int i = 1; i <= 6; i++)
        {
            if(i+d1.x <= 100 && (arr2[i+d1.x] == -1 || 1 + d1.L < arr2[i+d1.x]))
            {
                arr2[i+d1.x] = d1.L + 1;
                data_t d2 = {i+d1.x,d1.L + 1};
                enqueue(q1,d2);
            }
        }
    }
    printf("%d", i1);
    free(arr1);
    free(arr2);
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