#define min(x, y) (((x) < (y)) ? (x) : (y))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
// Linked List
typedef int data_t;
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

char c1[4] = {'D', 'S', 'L', 'R'};
int ci1[4] = {0,};

int main(void)
{
    int T,a,b;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &a, &b);
        solve(a,b);
    }
    return 0;
}

void solve(int a, int b)
{
    int arr1[10000] = {0,};
    int arr3[10000] = {0,};
    char arr2[10000];
    arr1[a] = 1;
    arr3[a] = a;
    arr2[a] = '\0';
    queue* q1 = initqueue();
    enqueue(q1, a);
    while(q1->front != NULL)
    {
        data_t n1 = q1->front->data;
        dequeue(q1);
        if(n1 == b)
        {
            while(q1->front != NULL) dequeue(q1);
            continue;
        }
        ci1[0] = (n1 * 2) % 10000;
        ci1[1] = (n1 == 0 ? 9999 : n1 - 1);
        ci1[2] = (n1 % 1000)*10 + n1 / 1000;
        ci1[3] = n1/10 + (n1%10)*1000;
        for(int i = 0; i < 4; i++)
        {
            if(arr1[ci1[i]] == 0)
            {
                arr1[ci1[i]] = 1;
                arr3[ci1[i]] = n1;
                arr2[ci1[i]] = c1[i];
                enqueue(q1, ci1[i]);
            }
        }
    }
    int i = 0;
    char c2[10005] = "";
    int now = b;
    while(1)
    {
        if(arr2[now] != '\0') 
        {
            c2[i] = arr2[now];
            c2[i+1] = '\0';
            i += 1;
        }        
        if(arr3[now] == a)
            break;
        else now = arr3[now];
    }
    for(int j = i-1; j >= 0; j--)
        printf("%c",c2[j]);
    printf("\n");
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