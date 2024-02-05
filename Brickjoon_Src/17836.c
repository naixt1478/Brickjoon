#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Linked List
typedef struct data_t
{
    int x,y,cnt;
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

int N,M,T,tri1;
int delta_arr1[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
queue q1;
int main(void)
{
    scanf("%d %d %d", &N, &M, &T);
    int** arr1 = (int**)malloc(sizeof(int*) * N);
    int** check1 = (int**)malloc(sizeof(int*) * N);
    int** check2 = (int**)malloc(sizeof(int*) * N);
    for(int i = 0; i < N; i++)
    {
        arr1[i] = (int*)calloc(M, sizeof(int));
        check1[i] = (int*)calloc(M, sizeof(int));
        check2[i] = (int*)calloc(M, sizeof(int));
        for(int j = 0; j < M; j++)
            scanf("%d", &arr1[i][j]);
    }
    check1[0][0] = 1; // set margin + 1
    data_t d3;
    // BFS
    enqueue(&q1, (data_t){0,0,1});
    while(q1.size != 0)
    {
        data_t now_data = q1.front->data;
        dequeue(&q1);
        for(int i = 0; i < 4; i++)
        {
            int nx = now_data.x + delta_arr1[i][0];
            int ny = now_data.y + delta_arr1[i][1];
            if(0 <= nx && nx < M && 0 <= ny && ny < N)
            {
                if(check1[ny][nx] == 0 && arr1[ny][nx] != 1)
                {
                    check1[ny][nx] = now_data.cnt + 1;
                    data_t d2 = {nx,ny,now_data.cnt+1};
                    if(arr1[ny][nx] == 2) 
                    {
                        d3 = (data_t){nx, ny, now_data.cnt + 1};
                        check2[ny][nx] = now_data.cnt + 1;
                        tri1 = 1;
                    }
                    enqueue(&q1,d2);
                }
            }
        }
    }
    if(tri1 == 1)
    {
        enqueue(&q1, d3);
        while(q1.size != 0)
        {
            data_t now_data = q1.front->data;
            dequeue(&q1);
            for(int i = 0; i < 4; i++)
            {
                int nx = now_data.x + delta_arr1[i][0];
                int ny = now_data.y + delta_arr1[i][1];
                if(0 <= nx && nx < M && 0 <= ny && ny < N)
                {
                    if(check2[ny][nx] == 0)
                    {
                        check2[ny][nx] = now_data.cnt + 1;
                        data_t d2 = {nx,ny,now_data.cnt+1};
                        enqueue(&q1,d2);                        
                    }
                }
            }
        }
    }
    int i4 = -1;
    if(check1[N - 1][M - 1] == 0)
    {
        if(tri1 == 1)
            i4 = check2[N - 1][M - 1] - 1;
        else
            printf("Fail");
    }
    else
    {
        if(tri1 == 1)
            i4 = min(check2[N - 1][M - 1],check1[N - 1][M - 1]) - 1;
        else
            i4 = check1[N - 1][M - 1] - 1;
    }
    if(i4 != -1)
    {
        if(i4 <= T) printf("%d", i4);
        else printf("Fail");
    }
    for(int i = 0; i < N; i++)
    {
        free(arr1[i]);
        free(check1[i]);
        free(check2[i]);
    }
    free(arr1);
    free(check1);
    free(check2);
    return 0;
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