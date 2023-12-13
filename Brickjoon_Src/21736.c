#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    struct node* back;
    int size;
} queue;

int N,M,a,x,y;
data_t D1[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

void enqueue(queue*,data_t);
void dequeue(queue*);
queue* initqueue();
node* initnode(data_t);

void bfs_s1(char**,int**);
int main(void)
{
    scanf("%d %d", &N, &M);
    char** arr1 = (char**)malloc(sizeof(char*) * N);
    int** arr2 = (int**)malloc(sizeof(int*)*N);
    for(int i = 0; i < N; i++)
    {
        arr1[i] = malloc(sizeof(char) * M);
        arr2[i] = calloc(M, sizeof(int));
        scanf("%s", arr1[i]);
        for(int j = 0; j < M; j++)
        {
            if(arr1[i][j] == 'I')
            {
                y = i;
                x = j;
            }
        }
    }
    bfs_s1(arr1,arr2);
    for(int i = 0; i < M; i++)
    {
        free(arr1[i]);
        free(arr2[i]);
    }
    free(arr1);
    free(arr2);
    if(a==0) printf("TT");
    else printf("%d", a);
    return 0;
}

void bfs_s1(char** arr1,int** arr2)
{
    printf("checking in, %d | %d",x,y);
    data_t root = {x,y};
    arr2[y][x] = 1;
    queue* q1 = initqueue();
    enqueue(q1, root);
    while(q1->front != NULL)
    {
        printf("%d | %d\n", q1->front->data.x, q1->front->data.y);
        data_t d2 = q1->front->data;
        dequeue(q1);
        for(int i = 0; i < 4; i++)
        {
            int nx = d2.x+D1[i].x, ny = d2.y+D1[i].y;
            if(0 <= nx && nx < M && 0 <= ny && ny < N)
            {
                if(arr2[ny][nx] == 0 && arr1[ny][nx] == 'X')
                {
                    arr2[ny][nx] = 1;
                    data_t d3 = {nx,ny};
                    enqueue(q1,d3);
                    if(arr1[ny][nx] == 'P') a++;
                }
            }
        }
    }
}

queue* initqueue()
{
    queue* tmp = malloc(sizeof(queue));
    if (tmp == NULL)
    {
        return NULL;
    }
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
    tmp->prev = NULL;
    return tmp;
}

void enqueue(queue* q1, data_t i1)
{
    node* tmp = initnode(i1);
    if(q1->size == 0)
    {
        q1->back = tmp;
        q1->front = tmp;
        q1->size = 1;
        return;
    }
    else
    {
        q1->back->next = tmp;
        tmp->prev = q1->back;
        q1->back = tmp;
        q1->size += 1;
    }
}

void dequeue(queue* q1)
{
    if(q1->size == 0) return;
    node* tmp = q1->front;
    q1->front = q1->front->next;
    q1->front->prev = NULL;
    q1->size -= 1;
    if(q1->size == 0) q1->back = NULL;
    free(tmp);
}