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

void btsolve1(int** arr, int** arr2, data_t* qarr1, int i);
void floodfill(int** ppi);
int opti[4][2] = 
{   
    {-1,-1},
    {-1,-1},
    {-1,-1},
    {0,0}
};
int delta_arr[2][4] = 
{
    {1,-1,0,0},
    {0,0,1,-1}
};

queue qp1;
int N, M, L, i1_max, i2_max, i3_max;
int main(void)
{
    scanf("%d %d", &N, &M);
    int** ppi1 = (int**)malloc(sizeof(int*) * N);
    int** ppi2 = (int**)malloc(sizeof(int*) * N);
    data_t* rpdt1 = NULL;
    for(int i = 0; i < N; i++) 
    {
        ppi1[i] = (int*)malloc(M * sizeof(int));
        ppi2[i] = (int*)malloc(M * sizeof(int));
        for(int j = 0; j < M; j++)
        {
            scanf("%d", &ppi1[i][j]);
            if(ppi1[i][j] == 0) i3_max += 1;
            else if(ppi1[i][j] == 2)
            {
                rpdt1 = (data_t*)realloc(rpdt1, sizeof(data_t) * (L + 1));
                rpdt1[L].y = i;
                rpdt1[L].x = j;
                L += 1;
            }
        }
    }
    btsolve1(ppi1, ppi2, rpdt1, 0);
    printf("%d", i1_max);
    for(int i = 0; i < N; i++)
    {
        free(ppi1[i]);
        free(ppi2[i]);
    }
    free(rpdt1);
    free(ppi1);
    free(ppi2);
    return 0;
}

void floodfill(int** ppi)
{
    i2_max = 0;
    while(qp1.size != 0)
    {
        data_t d1 = qp1.front->data;
        dequeue(&qp1);
        for(int i = 0; i < 4; i++)
        {
            int nx = d1.x + delta_arr[0][i];
            int ny = d1.y + delta_arr[1][i];
            if(0 <= nx && nx < M && 0 <= ny && ny < N)
            {
                if(ppi[ny][nx] == 0)
                {
                    ppi[ny][nx] = 1;
                    i2_max += 1;
                    enqueue(&qp1, (data_t){nx, ny});
                }
            }
        }
    }
}

void btsolve1(int** arr, int** arr2, data_t* qarr1, int i)
{
    if(i == 3)
    {
        for(int j = 0; j < N; j++) 
            memcpy(arr2[j], arr[j], sizeof(int) * M);
        for(int j = 0; j < L; j++)
            enqueue(&qp1, (data_t){qarr1[j].x, qarr1[j].y});
        floodfill(arr2);
        if(i3_max - 3 - i2_max > i1_max) i1_max = i3_max - 3 - i2_max;
    }
    else
    {
        for(int j = 0; j < N; j++)
        {
            if(opti[i][0] > j) continue;
            for(int k = 0; k < M; k++)
            {
                if(opti[i][0] > j && opti[i][1] > k) continue;
                if(arr[j][k] == 0)
                {
                    arr[j][k] = 1;
                    opti[i+1][0] = j;
                    opti[i+1][1] = k;
                    btsolve1(arr, arr2, qarr1, i + 1);
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
    {
        printf("Segfault error");
        return NULL;
    }
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