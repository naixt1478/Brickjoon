#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Linked List
typedef int data_t;

typedef struct node
{
    data_t data;
    struct node* next;
} node;

typedef struct stack
{
    struct node* front;
    struct node* back;
    int size;
} stack;

void in_stack(stack* st1, data_t i1);
void de_stack(stack* st1);
stack* initstack();
node* initnode(data_t i1);

int main(void)
{
    char c1[1000001],c2[37];
    scanf("%s %s", c1, c2);
    int a = strlen(c1),b = strlen(c2),j = 0,c = 0,f = 0;
    int* dp = (int*)calloc(a,sizeof(int));
    stack* st1 = initstack();
    for(int i = 0; i < a; i++)
    {
        in_stack(st1, c1[i]);
        if(c1[i] == c2[j])
        {
            if(j == b - 1)
            {
                f -= b;
                for(int k = 0; k < b; k++) 
                    de_stack(st1);
                if(f < 0)
                {
                    j = 0;
                    f = 0;
                    continue;
                }
                else j = dp[f];
            }
            else j++;
            dp[f] = j;
        }
        else 
        {
            j = 0;
            if(c1[i] == c2[j]) j++;
            dp[f] = j;
        }
        f++;
    }
    if(st1->size == 0) printf("FRULA");
    else
    {
        memset(c1,'\0',sizeof(char)*1000001);
        c = st1->size;
        c1[c] = '\0';
        while(st1->size != 0)
        {
            c -= 1;
            c1[c] = st1->front->data;
            de_stack(st1);
        }
        printf("%s", c1);
    }
    free(st1);
    return 0;
}

stack* initstack()
{
    stack* tmp = malloc(sizeof(stack));
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
    {
        return NULL;
    }
    tmp->next = NULL;
    tmp->data = i1;
    return tmp;
}

void in_stack(stack* st1, data_t i1)
{
    node* tmp = initnode(i1);
    if(st1->size == 0)
    {
        st1->back = tmp;
        st1->front = tmp;
        st1->size += 1;
    }
    else
    {
        tmp->next = st1->front;
        st1->front = tmp;
        st1->size += 1;
    }
}

void de_stack(stack* st1)
{
    // empty stack not run de_stack
    if(st1->size == 0) return;
    node* tmp = st1->front;
    st1->front = st1->front->next;
    if(tmp->next == NULL)
        st1->back = NULL;
    st1->size -= 1;
    free(tmp);
    tmp = NULL;
}