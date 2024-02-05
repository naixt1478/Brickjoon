#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// keep up
// flood fill, BFS
// doubly Linked List
typedef struct data_t
{
    int x,y;
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
    struct node* rear;
    int size;
} queue;

node* initnode(data_t data);
void enqueue(queue* qp1, data_t data);
void dequeue(queue* qp1);

void btsolve1(int** arr, int** arr2, int i);
void floodfill(int** arr, int** src, int** arr2);
int a[3];

queue q1;
int N, M, a, L;
int main(void)
{
    scanf("%d %d", &N, &M);
    int** ppi1 = (int**)malloc(sizeof(int*) * N);
    int** arr2 = (int**)malloc(sizeof(int*) * N);
    int** arr3 = (int**)malloc(sizeof(int*) * N);
    int** ppi2 = (int**)calloc(0, sizeof(int*));
    for(int i = 0; i < N; i++) 
    {
        ppi1[i] = (int*)calloc(M, sizeof(int));
        arr2[i] = (int*)calloc(M, sizeof(int));
        arr3[i] = (int*)
        for(int j = 0; j < M; j++)
        {
            scanf("%d", &ppi1[i][j]);
            if(ppi1[i][j] == 2)
            {
                ppi2 = (int**)realloc(ppi2, sizeof(int*) * (L + 1));
                ppi2[L] = (int*)calloc(2, sizeof(int));
                ppi2[L][0] = i;
                ppi2[L][0] = j;
                L += 1;
            }
        }
    }
    btsolve1(ppi1, arr2, 0);
    printf("%d", M);
    return 0;
}

void floodfill(int** arr, int** src, int** arr2)
{
    queue q1; 
    for(int i = 0; i < L; i++)
    {
        enqueue(&q1, )
    }
}

void btsolve1(int** arr, int** arr2, int i)
{
    if(i == 3)
    {
        int si1 = 0;
        for(int j = 0; j < N; j++) 
            memcpy(arr2[j], arr[j], sizeof(int) * M);
        floodfill(arr2);
        for(int j = 0; j < N; j++)
            for(int k = 0; k < M; k++)
                if(arr2[j][k] == 0) si1 += 1;
        if(si1 > M) M = si1;
    }
    else
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < M; k++)
            {
                if(arr[j][k] == 0)
                {
                    arr[j][k] = 1;
                    btsolve1(arr, i + 1);
                    arr[j][k] = 0;
                }
            }
        }
    }
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