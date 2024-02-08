#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// doubly Linked List
typedef struct data_t
{
    int x,y,cnt;
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

typedef struct vector
{
    void* idx;
    size_t arr_len;
    size_t mem_len;
    size_t ele_len;
} vector;

void rinit(vector* pv, size_t ele_len);
void rpush(vector* pv, const void* value);
void rpop(vector* pv);
void rfree(vector* pv);
void iswap(heap_data* a, heap_data* b);

node* initnode(data_t data);
void enqueue(queue* qp1, data_t data);
void dequeue(queue* qp1);
void bfs_s1(queue* qp, int** ppi1, int** ppi2);

int delta_arr1[2][4] =
{
    {1,-1,0,0},
    {0,0,1,-1}
};

int N,M;
const int margin = 2;
queue qp1;
int main(void)
{
    scanf("%d", &N, &M);
    int** ppi1 = (int**)malloc(N * sizeof(int*));
    int** ppi2 = (int**)malloc(N * sizeof(int*));
    for(int i = 0; i < N; i++)
    {
        ppi1[i] = (int*)calloc(N, sizeof(int));
        ppi2[i] = (int*)calloc(N, sizeof(int));
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &ppi1[i][j]);
            if(ppi1[i][j] == 2)
            {
                enqueue(&qp1,(data_t){j,i,0});
                ppi2[i][j] = margin;
            }
        }
    }
    bfs_s1(&qp1, ppi1, ppi2);
    return 0;
}

void bfs_s1(queue* qp, int** ppi1, int** ppi2)
{
    while(qp->size != 0)
    {
        data_t d1 = qp->front->data;
        dequeue(qp);
        for(int i = 0; i < 4; i++)
        {
            int nx = d1.x + delta_arr1[0][i];
            int ny = d1.y + delta_arr1[1][i];
            if(0 <= nx && nx < N && 0 <= ny && ny < N)
            {
                if(ppi2[ny][nx] == 0)
                {
                    ppi2[ny][nx] = d1.cnt + 1 + margin;
                    enqueue(&qp1, )
                }
            }
        }
    }
}

void rinit(vector* pv, size_t ele_len)
{
    pv->arr_len = 0;
    pv->ele_len = ele_len;
    pv->mem_len = 0;
    pv->idx = NULL;
}

void rpush(vector* pv, const void* value)
{
    if(pv->idx == NULL)
    {
        pv->mem_len = 1;
        pv->idx = calloc(1, pv->ele_len);
    }
    pv->arr_len += 1;
    if(pv->arr_len > pv->mem_len)
    {
        while(pv->mem_len <= pv->arr_len)
            pv->mem_len <<= 1;
        pv->idx = realloc(pv->idx, pv->ele_len * pv->mem_len);
    }
    memcpy((char*)(pv->idx) + (pv->ele_len)*(pv->arr_len - 1), value, pv->ele_len);
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