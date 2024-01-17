#include <stdio.h>
#include <stdlib.h>
// Linked List
typedef struct data_t
{
    int x,y;
} data_t;

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
    data_t a = {10,20};
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