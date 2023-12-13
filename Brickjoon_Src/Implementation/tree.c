#include <stdio.h>

struct node
{
    int key;
    struct node *left, *right, *parent;
};

struct Tree
{
    node* root = NULL;
};

void bst_insert(Tree*, int);
node* create_node(int);

int main(void)
{
    
}

node* create_node(int i1)
{
    node* t1;
    t1->key = i1;
    t1->left = t1->right = NULL;
    t1->parent = NULL;
    return t1;
}

void bst_insert(Tree* t1, int key)
{
    node* z = create_node(key);
    node* iptr1 = NULL;
    node* iptr2 = t1->root;
    while(iptr2 != NULL)
    {
        iptr1 = iptr2;
        if(z.key < iptr2.key)
            iptr2 = iptr2.left;
        else
            iptr2 = iptr2.right;
    }
    z.parent = iptr1;
    if(iptr1 == NULL)
        t1->root = z;
    else if(z.key < iptr1.key)
        iptr1->left = z;
    else
        iptr1->right = z;
}