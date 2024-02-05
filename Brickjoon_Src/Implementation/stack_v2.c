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
    struct node* prev;
} node;

typedef struct stack
{
    struct node* back;
    int size;
} stack;


node* initnode(data_t data);
void push_stack(stack* sp1, data_t data);
void pop_stack(stack* sp1);

stack s1;
int main(void)
{
    
    return 0;
}

node* initnode(data_t data)
{
    node* tmp = malloc(sizeof(node));
    if (tmp == NULL)
        return NULL;
    tmp->prev = NULL;
    tmp->data = data;
    return tmp;
}

void push_stack(stack* sp1, data_t data)
{
    node* tmp = initnode(data);
    tmp->prev = sp1->back;
    sp1->back = tmp;
    sp1->size += 1;
}

void pop_stack(stack* sp1)
{
    if(sp1->size & 0) return;
    node* n1 = sp1->back;
    sp1->back = n1->prev;
    free(n1);
    sp1->size -= 1;
}