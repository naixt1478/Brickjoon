// BST implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef int key_t;
typedef struct node
{
    key_t key;
    struct node *left, *right, *parent;
} node;
typedef struct bst
{
    node* root;
    int size;
} bst;

node* init_node(key_t key);

void in_bst(bst* T, key_t key);
node* search_bst(bst* T, key_t key);
node* recur_sbst(node* x, key_t key);
void shift_nodes(bst* T, node* u, node* v);
void del_bst(bst* T, key_t key);

// traversal
void inorder_bst(bst T);
void preorder_bst(bst T);
void postorder_bst(bst T);
void inorder_tbst(node* x);
void preorder_tbst(node* x);
void postorder_tbst(node* x);

node* successor_bst(node* x);
node* predecessor_bst(node* x);

node* minimum_bst(node* x);
node* maximum_bst(node* x);
// from implementation folder Tree-BST.c

int c;
bst bst1;
void solve_in_bst(bst* T, key_t key);
int main(void)
{
    //freopen("TestInput.txt", "r", stdin);
    int n,a;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        solve_in_bst(&bst1, a);
    }
}

void solve_in_bst(bst* T, key_t key)
{
    node* px = NULL;
    node* x = T->root;
    node* z = init_node(key);
    while(x != NULL)
    {
        c += 1;
        px = x;
        if(z->key < x->key)
            x = x->left;
        else 
            x = x->right;
    }
    z->parent = px;
    if(px == NULL)
        T->root = z;
    else if(z->key < px->key)
        px->left = z;
    else
        px->right = z;
    T->size += 1;
    printf("%d\n", c);
}

node* init_node(key_t key)
{
    node* x = (node*)malloc(sizeof(node));
    x->key = key;
    x->left = NULL;
    x->right = NULL;
    x->parent = NULL;
    return x;
}

node* minimum_bst(node* x)
{
    while(x->left != NULL)
        x = x->left;
    return x;
}

node* maximum_bst(node* x)
{
    while(x->right != NULL)
         x = x->right;
    return x;
}

node* successor_bst(node* x)
{
    if(x->right != NULL)
        return minimum_bst(x->right);
    node* y = x->parent;
    while(y != NULL && x == y->right)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

node* predecessor_bst(node* x)
{
    if(x->left != NULL)
        return maximum_bst(x->left);
    node* y = x->parent;
    while(y != NULL && x == y->left)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

node* recur_sbst(node* x, key_t key)
{
    if(x == NULL || x->key == key)
        return x;
    if(key < x->key)
        return recur_sbst(x->left, key);
    else 
        return recur_sbst(x->right, key);
}

node* search_bst(bst* T, key_t key)
{
    return recur_sbst(T->root, key);
}

void in_bst(bst* T, key_t key)
{
    node* px = NULL;
    node* x = T->root;
    node* z = init_node(key);
    while(x != NULL)
    {
        px = x;
        if(z->key < x->key)
            x = x->left;
        else 
            x = x->right;
    }
    z->parent = px;
    if(px == NULL)
        T->root = z;
    else if(z->key < px->key)
        px->left = z;
    else
        px->right = z;
    T->size += 1;
}

void shift_nodes(bst* T, node* u, node* v)
{
    if(u->parent == NULL)
        T->root = v;
    else if(u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if(v != NULL)
        v->parent = u->parent;
}

void del_bst(bst* T, key_t key)
{
    node* D = search_bst(T, key);
    if(D == NULL) return;
    if(D->left == NULL)
        shift_nodes(T, D, D->right);
    else if(D->right == NULL)
        shift_nodes(T, D, D->left);
    else
    {
        node* E = successor_bst(D);
        if(E->parent != D)
        {
            shift_nodes(T, E, E->right);
            E->right = D->right;
            E->right->parent = E;
        }
        shift_nodes(T, D, E);
        E->left = D->left;
        E->left->parent = E;
    }
    free(D);
    T->size -= 1;
}

void inorder_tbst(node* x)
{
    if(x != NULL)
    {
        inorder_tbst(x->left);
        printf("%d ", x->key);
        inorder_tbst(x->right);
    }
}
void preorder_tbst(node* x)
{
    if(x != NULL)
    {
        printf("%d ", x->key);
        preorder_tbst(x->left);
        preorder_tbst(x->right);
    }
}
void postorder_tbst(node* x)
{
    if(x != NULL)
    {
        postorder_tbst(x->left);
        postorder_tbst(x->right);
        printf("%d ", x->key);
    }
}

void inorder_bst(bst T)
{
    printf("inorder tbst : ");
    inorder_tbst(T.root);
    printf("|\n");
}
void preorder_bst(bst T)
{
    printf("preorder tbst : ");
    preorder_tbst(T.root);
    printf("|\n");
}
void postorder_bst(bst T)
{
    printf("postorder tbst : ");
    postorder_tbst(T.root);
    printf("|\n");
}
