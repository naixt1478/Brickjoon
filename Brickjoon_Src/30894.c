#define idx(a) ((a) - '0')
#define min(x, y) (((x) < (y)) ? (x) : (y))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
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

node* initnode(data_t data);
void enqueue(queue* qp1, data_t data);
void dequeue(queue* qp1);

queue qp1;
int N,M,ix1,iy1,ix2,iy2;
int i1_min = INT_MAX - 10;
int delta_arr1[2][5] = 
{
    {0,-1,1,0,0},
    {0,0,0,-1,1}
}; // 0 : x+ , 1: y+, 2: x-, 3: y-
int delta_arr2[2][4] =
{
    {1,0,-1,0},
    {0,1,0,-1}
};

void solve_bfs1(char** ppc, int*** pppi);

// point:
// 5 way 0,0 1,0 0,1 -1,0 0,-1
const int margin = 2;
int main(void)
{
    #ifndef ONLINE_JUDGE
        freopen("TestInput.txt", "r" , stdin);
        //freopen("TestOutput.txt", "w" , stdout);
    #endif
    scanf("%d %d", &N, &M);
    scanf("%d %d %d %d", &iy1, &ix1, &iy2, &ix2);
    char** ppc1 = (char**)calloc(N, sizeof(char*));
    int*** pppi1 = (int***)calloc(4, sizeof(int**));
    for(int i = 0; i < 4; i++)
    {
        pppi1[i] = (int**)calloc(N, sizeof(int*));
        for(int j = 0; j < N; j++)
            pppi1[i][j] = (int*)calloc(M, sizeof(int));
    }
    for(int i = 0; i < N; i++)
    {
        ppc1[i] = (char*)malloc((M+2) * sizeof(char));
        scanf("%s", ppc1[i]);
        for(int j = 0; j < M; j++)
            if(ppc1[i][j] != '.')
                for(int k = 0; k < 4; k++)
                    pppi1[k][i][j] = 1;
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if('0' <= ppc1[i][j] && ppc1[i][j] <= '9')
            {
                for(int k = 0; k < 4; k++)
                {
                    int kx = j + delta_arr2[0][(k + idx(ppc1[i][j]))%4], ky = i + delta_arr2[1][(k + idx(ppc1[i][j]))%4];
                    while(0 <= kx && kx < M && 0 <= ky && ky < N)
                    {
                        if(ppc1[ky][kx] != '.')
                        {
                            pppi1[k][ky][kx] = 1;
                            break;
                        }
                        else
                            pppi1[k][ky][kx] = 1;
                        kx += delta_arr2[0][(k + idx(ppc1[i][j]))%4];
                        ky += delta_arr2[1][(k + idx(ppc1[i][j]))%4];
                    }
                }
            }
        }
    }
    enqueue(&qp1, (data_t){ix1 - 1,iy1 - 1,0});
    solve_bfs1(ppc1, pppi1);
    for(int i = 0; i < 4; i++)
    {
        if(pppi1[i][iy2 - 1][ix2 - 1] >= 2)
            i1_min = min(i1_min, pppi1[i][iy2 - 1][ix2 - 1] - margin);
    }
    if(i1_min == INT_MAX - 10) printf("GG");
    else printf("%d", i1_min);
    return 0;
}

void solve_bfs1(char** ppc, int*** pppi)
{
    pppi[qp1.front->data.cnt][qp1.front->data.y][qp1.front->data.x] = margin; 
    while(qp1.size != 0)
    {
        data_t d2 = qp1.front->data;
        dequeue(&qp1);
        for(int i = 0; i < 5; i++)
        {
            int nx1 = d2.x + delta_arr1[0][i];
            int ny1 = d2.y + delta_arr1[1][i];
            if(0 <= nx1 && nx1 < M && 0 <= ny1 && ny1 < N)
            {
                if(pppi[(d2.cnt + 1) % 4][ny1][nx1] == 0)
                {
                    pppi[(d2.cnt + 1) % 4][ny1][nx1] = d2.cnt + 1 + margin;
                    enqueue(&qp1, (data_t){nx1, ny1, d2.cnt + 1});
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