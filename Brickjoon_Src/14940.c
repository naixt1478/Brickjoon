#include <stdio.h>
#include <stdlib.h>
#define min(x, y) (((x) < (y)) ? (x) : (y))
typedef struct data_t
{
    int x,y,val;
} data_t;

struct i2
{
    int ax,ay;
};

typedef struct node
{
    data_t data;
    struct node* next;
} node;

typedef struct queue
{
    struct node* front;
    struct node* back;
} queue;

int n,m,a,b;
struct i2 arr3[4] = {{1,0}, {-1, 0}, {0,1}, {0,-1}};

void enqueue(queue*,data_t);
void dequeue(queue*);
void s1_bfs(int arr1[][m], int arr2[][m]);

int main(void)
{
    scanf("%d %d", &n, &m);
    int arr1[n][m];
    int arr2[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &arr1[i][j]);
            if(arr1[i][j] == 2)
            {
                a = i;
                b = j;
            }
            arr2[i][j] = -1;
        }
    }
    s1_bfs(arr1,arr2);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            printf("%d ",arr1[i][j] == 0 ? 0 : arr2[i][j]);
        printf("\n");
    }
    return 0;
}

void s1_bfs(int p1[][m], int p2[][m])
{
    data_t root = {a,b,0};
    queue* q1 = malloc(sizeof(queue));
    // init phase
    q1->front = NULL;
    q1->back = NULL;
    enqueue(q1,root);
    p2[a][b] = 0;
    while(q1->front != NULL)
    {
        data_t d1 = q1->front->data;
        dequeue(q1);
        for(int i = 0; i < 4; i++)
        {
            int nx = d1.x + arr3[i].ax;
            int ny = d1.y + arr3[i].ay; 
            if(0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if(p1[nx][ny] != 0 && p2[nx][ny] == -1 || d1.val + 1 < p2[nx][ny])
                {
                    p2[nx][ny] = (p2[nx][ny] == -1 ? d1.val + 1 : min(d1.val + 1,p2[nx][ny]));
                    data_t d2 = {nx,ny, p2[nx][ny]};
                    enqueue(q1, d2);
                }
            }
        }
    }
    free(q1);
}

void enqueue(queue* q1, data_t d1)
{
    node* tmp = malloc(sizeof(node));
    tmp->next = NULL;
    tmp->data = d1;
    if(q1->front == NULL)
    {
        q1->back = tmp;
        q1->front = tmp;
        return;
    }
    q1->back->next = tmp;
    q1->back = tmp;
}

void dequeue(queue* q1)
{
    if(q1->front == NULL) return;
    node* tmp = q1->front;
    q1->front = q1->front->next;
    if(q1->front == NULL) q1->back = NULL;
    free(tmp);
}