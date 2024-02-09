#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char data_t;
typedef struct tree_node
{
    data_t value;
    struct tree_node *left;
    struct tree_node *right;
} tree_node;

tree_node* init_node(data_t value);
void post_ftree(tree_node* rt1);

void pre_solve1(tree_node* rt1, data_t sval, data_t lval, data_t rval);
void preorder(tree_node* rt1);
void inorder(tree_node* rt1);
void postorder(tree_node* rt1);


int main(void)
{
    tree_node* rt1 = init_node('A');
    int n;
    char c1[10];
    data_t a,b,c;
    fgets(c1, 10, stdin);
    c1[strlen(c1)-1] = '\0';
    sscanf(c1, "%d", &n);
    for(int i = 0; i < n; i++)
    {
        fgets(c1, 10, stdin);
        c1[5] = '\0';
        sscanf(c1, "%c %c %c", &a, &b, &c);
        pre_solve1(rt1, a,b,c);
    }
    preorder(rt1);
    printf("\n");
    inorder(rt1);
    printf("\n");
    postorder(rt1);
    post_ftree(rt1);
}

void pre_solve1(tree_node* rt1, data_t sval, data_t lval, data_t rval)
{
    if(rt1 == NULL)
        return;
    else if(rt1->value == sval)
    {
        if(lval != '.') rt1->left = init_node(lval);
        if(rval != '.') rt1->right = init_node(rval);
        return;
    }
    pre_solve1(rt1->left, sval, lval, rval);
    pre_solve1(rt1->right, sval, lval, rval);
}

tree_node* init_node(data_t value)
{
    tree_node* tn1 = malloc(sizeof(tree_node));
    tn1->value = value;
    tn1->left = NULL;
    tn1->right = NULL;
    return tn1;
}

void preorder(tree_node* rt1)
{
    if (rt1 != NULL)
    {
        printf("%c",rt1->value);
        preorder(rt1->left);
        preorder(rt1->right);
    }
}
void inorder(tree_node* rt1)
{
    if (rt1 != NULL)
    {
        inorder(rt1->left);
        printf("%c",rt1->value);
        inorder(rt1->right);
    }
}
void postorder(tree_node* rt1)
{
    if (rt1 != NULL)
    {
        postorder(rt1->left);
        postorder(rt1->right);
        printf("%c",rt1->value);
    }
}

void post_ftree(tree_node* rt1)
{
    if(rt1 != NULL)
    {
        post_ftree(rt1->left);
        post_ftree(rt1->right);
        free(rt1);
    }
}