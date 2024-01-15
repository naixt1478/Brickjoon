#define min(x, y) (((x) < (y)) ? (x) : (y))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
// Linked List
typedef struct data_t
{
    int x;
    char* s1;
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
void solve(int a, int b);

int main(void)
{
    
    char c1[4] = {'D', 'S', 'L', 'R'};
    int ci1[4] = {0};
    int T,a,b;
    scanf("%d", &T);
    while (T--)
    {
        int* arr1 = (int*)calloc(10000, sizeof(int));
        char** arr2 = (char**)malloc(sizeof(char*)*10000);
        for(int i = 0; i < 10000; i++) arr2[i] = NULL;
        scanf("%d %d", &a, &b);
        arr1[a] = 1;
        arr2[a] = calloc(1,sizeof(char));
        arr2[a][0] = '\0';
        data_t root = {a, arr2[a]};
        queue* q1 = initqueue();
        enqueue(q1, root);
        while(q1->front != NULL)
        {
            data_t n1 = q1->front->data;
            size_t st1 = strlen(n1.s1);   
            dequeue(q1);
            if(n1.x == b)
            {
                while(q1->front != NULL) dequeue(q1);
                continue;
            }
            ci1[0] = (n1.x * 2) % 10000;
            ci1[1] = (n1.x == 0 ? 9999 : n1.x - 1);
            ci1[2] = (n1.x % 1000)*10 + n1.x / 1000;
            ci1[3] = n1.x/10 + (n1.x%10)*1000;
            for(int i = 0; i < 4; i++)
            {
                if(arr1[ci1[i]] == 0)
                {
                    arr1[ci1[i]] = 1;
                    arr2[ci1[i]] = (char*)calloc(st1 + 2, sizeof(char));
                    strcpy(arr2[ci1[i]], n1.s1);
                    arr2[ci1[i]][st1] = c1[i];
                    arr2[ci1[i]][st1 + 1] = '\0';
                    data_t d2 = {ci1[i], arr2[ci1[i]]};
                    enqueue(q1,d2);
                }
            }
        }
        printf("%s\n", arr2[b]);
        for(int i = 0; i < 10000; i++)
            if(arr2[i] != NULL) free(arr2[i]);
        free(arr1);
        free(arr2);
    }
    return 0;
}

void solve(int a, int b)
{
    
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