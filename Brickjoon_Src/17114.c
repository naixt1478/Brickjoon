#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// doubly Linked List
typedef struct data_t
{
    int w, v, u, t, s, r, q, p, o, n, m;
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

int i1_max,tri1;
int delta_hyper_arr1[11][22] =
{
        {1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1}
};
int m, n, o, p, q, r, s, t, u, v, w;
void hyper_bfs(int*********** hyper_arr);
queue qp1;

int main(void)
{
    scanf("%d %d %d %d %d %d %d %d %d %d %d", &m, &n, &o, &p, &q, &r, &s, &t, &u, &v, &w);
    int*********** hyper_arr1 = (int***********)malloc(sizeof(int**********)*w);
    for(int w1 = 0; w1 < w; w1++)
    {
        hyper_arr1[w1] = (int**********)malloc(sizeof(int*********)*v);
        for(int v1 = 0; v1 < v; v1++)
        {
            hyper_arr1[w1][v1] = (int*********)malloc(sizeof(int********)*u);
            for(int u1 = 0; u1 < u; u1++)
            {
                hyper_arr1[w1][v1][u1] = (int********)malloc(sizeof(int*******)*t);
                for(int t1 = 0; t1 < t; t1++)
                {
                    hyper_arr1[w1][v1][u1][t1] = (int*******)malloc(sizeof(int******)*s);
                    for(int s1 = 0; s1 < s; s1++)
                    {
                        hyper_arr1[w1][v1][u1][t1][s1] = (int******)malloc(sizeof(int*****)*r);
                        for(int r1 = 0; r1 < r; r1++)
                        {
                            hyper_arr1[w1][v1][u1][t1][s1][r1] = (int*****)malloc(sizeof(int****)*q);
                            for(int q1 = 0; q1 < q; q1++)
                            {
                                hyper_arr1[w1][v1][u1][t1][s1][r1][q1] = (int****)malloc(sizeof(int***)*p);
                                for(int p1 = 0; p1 < p; p1++)
                                {
                                    hyper_arr1[w1][v1][u1][t1][s1][r1][q1][p1] = (int***)malloc(sizeof(int**)*o);
                                    for(int o1 = 0; o1 < o; o1++)
                                    {
                                        hyper_arr1[w1][v1][u1][t1][s1][r1][q1][p1][o1] = (int**)malloc(sizeof(int*)*n);
                                        for(int n1 = 0; n1 < n; n1++)
                                        {
                                            hyper_arr1[w1][v1][u1][t1][s1][r1][q1][p1][o1][n1] = (int*)calloc(m,sizeof(int));
                                            for(int m1 = 0; m1 < m; m1++)
                                            {
                                                scanf("%d", &hyper_arr1[w1][v1][u1][t1][s1][r1][q1][p1][o1][n1][m1]);
                                                if(hyper_arr1[w1][v1][u1][t1][s1][r1][q1][p1][o1][n1][m1] == 1)
                                                {
                                                    enqueue(&qp1, (data_t){w1, v1, u1, t1, s1, r1, q1, p1, o1, n1, m1});
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    hyper_bfs(hyper_arr1);
    for(int w1 = 0; w1 < w; w1++)
    {
        for(int v1 = 0; v1 < v; v1++)
        {
            for(int u1 = 0; u1 < u; u1++)
            {
                for(int t1 = 0; t1 < t; t1++)
                {
                    for(int s1 = 0; s1 < s; s1++)
                    {
                        for(int r1 = 0; r1 < r; r1++)
                        {
                            for(int q1 = 0; q1 < q; q1++)
                            {
                                for(int p1 = 0; p1 < p; p1++)
                                {
                                    for(int o1 = 0; o1 < o; o1++)
                                    {
                                        for(int n1 = 0; n1 < n; n1++)
                                        {
                                            for(int m1 = 0; m1 < m; m1++)
                                            {
                                                if(hyper_arr1[w1][v1][u1][t1][s1][r1][q1][p1][o1][n1][m1] == 0)
                                                    tri1 = 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } 
    }
    if(tri1 == 1) printf("-1");
    else printf("%d", max(i1_max - 1, 0));
    return 0;
}
// [w1][v1][u1][t1][s1][r1][q1][p1][o1][n1][m1]
void hyper_bfs(int*********** hyper_arr)
{
    while(qp1.size != 0)
    {
        data_t d1 = qp1.front->data;
        dequeue(&qp1);
        for(int i = 0; i < 22; i++)
        {
            if(0 <= d1.w + delta_hyper_arr1[0][i] && d1.w + delta_hyper_arr1[0][i] < w
            && 0 <= d1.v + delta_hyper_arr1[1][i] && d1.v + delta_hyper_arr1[1][i] < v
            && 0 <= d1.u + delta_hyper_arr1[2][i] && d1.u + delta_hyper_arr1[2][i] < u
            && 0 <= d1.t + delta_hyper_arr1[3][i] && d1.t + delta_hyper_arr1[3][i] < t
            && 0 <= d1.s + delta_hyper_arr1[4][i] && d1.s + delta_hyper_arr1[4][i] < s
            && 0 <= d1.r + delta_hyper_arr1[5][i] && d1.r + delta_hyper_arr1[5][i] < r
            && 0 <= d1.q + delta_hyper_arr1[6][i] && d1.q + delta_hyper_arr1[6][i] < q
            && 0 <= d1.p + delta_hyper_arr1[7][i] && d1.p + delta_hyper_arr1[7][i] < p
            && 0 <= d1.o + delta_hyper_arr1[8][i] && d1.o + delta_hyper_arr1[8][i] < o
            && 0 <= d1.n + delta_hyper_arr1[9][i] && d1.n + delta_hyper_arr1[9][i] < n
            && 0 <= d1.m + delta_hyper_arr1[10][i] && d1.m + delta_hyper_arr1[10][i] < m)
            {
                if(hyper_arr[d1.w + delta_hyper_arr1[0][i]][d1.v + delta_hyper_arr1[1][i]][d1.u + delta_hyper_arr1[2][i]][d1.t + delta_hyper_arr1[3][i]][d1.s + delta_hyper_arr1[4][i]][d1.r + delta_hyper_arr1[5][i]][d1.q + delta_hyper_arr1[6][i]][d1.p + delta_hyper_arr1[7][i]][d1.o + delta_hyper_arr1[8][i]][d1.n + delta_hyper_arr1[9][i]][d1.m + delta_hyper_arr1[10][i]] == 0)
                {
                    hyper_arr[d1.w + delta_hyper_arr1[0][i]][d1.v + delta_hyper_arr1[1][i]][d1.u + delta_hyper_arr1[2][i]][d1.t + delta_hyper_arr1[3][i]][d1.s + delta_hyper_arr1[4][i]][d1.r + delta_hyper_arr1[5][i]][d1.q + delta_hyper_arr1[6][i]][d1.p + delta_hyper_arr1[7][i]][d1.o + delta_hyper_arr1[8][i]][d1.n + delta_hyper_arr1[9][i]][d1.m + delta_hyper_arr1[10][i]] = hyper_arr[d1.w][d1.v][d1.u][d1.t][d1.s][d1.r][d1.q][d1.p][d1.o][d1.n][d1.m] + 1;
                    enqueue(&qp1, (data_t){d1.w + delta_hyper_arr1[0][i], d1.v + delta_hyper_arr1[1][i], d1.u + delta_hyper_arr1[2][i], d1.t + delta_hyper_arr1[3][i], d1.s + delta_hyper_arr1[4][i], d1.r + delta_hyper_arr1[5][i], d1.q + delta_hyper_arr1[6][i], d1.p + delta_hyper_arr1[7][i], d1.o + delta_hyper_arr1[8][i], d1.n + delta_hyper_arr1[9][i], d1.m + delta_hyper_arr1[10][i]});
                    if(hyper_arr[d1.w + delta_hyper_arr1[0][i]][d1.v + delta_hyper_arr1[1][i]][d1.u + delta_hyper_arr1[2][i]][d1.t + delta_hyper_arr1[3][i]][d1.s + delta_hyper_arr1[4][i]][d1.r + delta_hyper_arr1[5][i]][d1.q + delta_hyper_arr1[6][i]][d1.p + delta_hyper_arr1[7][i]][d1.o + delta_hyper_arr1[8][i]][d1.n + delta_hyper_arr1[9][i]][d1.m + delta_hyper_arr1[10][i]] > i1_max) i1_max = hyper_arr[d1.w + delta_hyper_arr1[0][i]][d1.v + delta_hyper_arr1[1][i]][d1.u + delta_hyper_arr1[2][i]][d1.t + delta_hyper_arr1[3][i]][d1.s + delta_hyper_arr1[4][i]][d1.r + delta_hyper_arr1[5][i]][d1.q + delta_hyper_arr1[6][i]][d1.p + delta_hyper_arr1[7][i]][d1.o + delta_hyper_arr1[8][i]][d1.n + delta_hyper_arr1[9][i]][d1.m + delta_hyper_arr1[10][i]];
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