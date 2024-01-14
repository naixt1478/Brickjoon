#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int i64_t;
typedef unsigned long long int ui64_t;

typedef int data_t;

typedef struct node
{
    char key[50];
    data_t data;
    struct node* next;
} node;

typedef struct h_table
{
    node *root;
    int length;
} h_table;

typedef struct fnode
{
    struct fnode* next;
    struct node* free;
} fnode;

typedef struct f_table
{
    fnode *root;
} f_table;

node* init_h_node(char* key, data_t value);
h_table** init_h_table(int BSIZE);
void free_h_table(h_table** nt2, int BSIZE, f_table* ft1);

int match_key(void* a, void* b);
void insert_h_table(h_table** nt2, char* key, data_t value, f_table*,int);
void remove_h_table(h_table** nt2,char* key,int BSIZE);
int search_h_table(h_table** nt2, char* key,int BSIZE);
node* index_h_table(h_table** nt2,char* key,int BSIZE);

ui64_t make_key_djb2(char* key,int BSIZE);

int N,b,M;
char a[30];
const int BUCKET_SIZE = 500000;
int main(void)
{
    scanf("%d", &N);
    h_table** ht1 = init_h_table(N);
    f_table ft1 = {NULL};
    for(int i = 0; i < N; i++)
    {
        scanf("%s", a);
        insert_h_table(ht1,a,1,&ft1,N);
    }
    scanf("%d", &M);
    for(int j = 0; j < M; j++)
    {
        scanf("%s", a);
        printf("%d ",search_h_table(ht1, a, N));
    }
    free_h_table(ht1,N,&ft1);
}

node* init_h_node(char* key, data_t value)
{
    node* tmp = malloc(sizeof(node));
    if(tmp == NULL) return NULL;
    tmp->next = NULL;
    tmp->data = value;
    strcpy(tmp->key, key);
    return tmp;
}
h_table** init_h_table(int BSIZE)
{
    h_table** nt2;
    nt2 = (h_table**)calloc(BSIZE, sizeof(h_table*));
    for(int i = 0; i < BSIZE; i++)
    {
        nt2[i] = (h_table*)calloc(1,sizeof(h_table));
        nt2[i]->root = NULL;
    }
    return nt2;
}
void free_h_table(h_table** nt2, int BSIZE,f_table* ft1)
{
    fnode* tmp = ft1->root;
    while(tmp != NULL)
    {
        free(tmp->free);
        fnode* tmp2 = tmp;
        tmp = tmp->next;
        free(tmp2);
    }
    for(int i = 0; i < BSIZE; i++) free(nt2[i]);
    free(nt2);
}

node* index_h_table(h_table** nt2, char* key,int BSIZE)
{
    h_table* nt1 = nt2[make_key_djb2(key,BSIZE)];
    node* tmp = nt1->root;
    if(nt1->length >= 1)
    {
        while(1)
        {
            if(match_key(tmp->key, key))
                return tmp;
            else if(tmp->next != NULL)
            {
                tmp = tmp->next;
                continue;
            }
            return NULL;
        }
    }
    return NULL;
}
void insert_h_table(h_table** nt2, char* key, data_t value,f_table* ft1,int BSIZE)
{
    h_table* nt1 = nt2[make_key_djb2(key,BSIZE)];
    if(nt1->length > 0)
    {
        // detect hash collision
        node* tmp = nt1->root;
        nt1->root = init_h_node(key, value);
        nt1->root->next = tmp;
    }
    else
    {
        nt1->root = init_h_node(key, value);
    }
    if(ft1->root == NULL)
    {
        ft1->root = (fnode*)malloc(sizeof(fnode));
        ft1->root->free = nt1->root;
        ft1->root->next = NULL;
    }
    else
    {
        ft1->root->next = (fnode*)malloc(sizeof(fnode));
        ft1->root->next->free = nt1->root;
        ft1->root->next->next = NULL;
    }
    nt1->length++;
}
void remove_h_table(h_table** nt2, char* key, int BSIZE)
{
    h_table* nt1 = nt2[make_key_djb2(key,BSIZE)];
    if(nt1->length >= 1)
    {
        node* bf = NULL;
        node* tmp = nt1->root;
        while(1)
        {
            if(match_key(tmp->key,key))
            {
                nt1->length--;
                node* tmp2 = tmp->next;
                free(tmp);
                if(bf != NULL) bf->next = tmp2;
                else nt1->root = tmp2;
            }
            else if(tmp->next != NULL)
            {
                bf = tmp;
                tmp = tmp->next;
                continue;
            }
            break;
        }
    }
}
int search_h_table(h_table** nt2, char* key,int BSIZE)
{
    h_table* nt1 = nt2[make_key_djb2(key,BSIZE)];
    node* tmp = nt1->root;
    if(nt1->length >= 1)
    {
        while(1)
        {
            if(match_key(tmp->key,key))
                return 1;
            else if(tmp->next != NULL)
            {
                tmp = tmp->next;
                continue;
            }
            return 0;
        }
    }
    else return 0;
}

int match_key(void* a, void* b)
{
    return ((strcmp(a,b) == 0) ? 1 : 0);
}

ui64_t make_key_djb2(char* key, int BSIZE)
{
    ui64_t h = 5381;
    int c;
    while ((c = *key++))
        h = ((h << 5) + h) + c; /* hash * 33 + c */
    return h % BSIZE;
}