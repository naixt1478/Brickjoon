#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int i64_t;
typedef unsigned long long int ui64_t;

typedef char* data_t;

typedef struct node
{
    char key[21];
    char data[21];
    struct node* next;
} node;

typedef struct fnode
{
    struct fnode* next;
    struct node* free;
} fnode;

typedef struct h_table
{
    node *root;
    int length;
} h_table;

typedef struct f_table
{
    fnode *root;
} f_table;

node* init_h_node(char*, data_t);

int match_key(void*, void*);
void insert_h_table(h_table*,char*,data_t,f_table*);
void remove_h_table(h_table*,char*);
int search_h_table(h_table*, char*);
data_t read_h_table(h_table*,char*);

ui64_t make_key_djb2(char*,int);

int N,M;
const int BUCKET_SIZE = 100000;
int main(void)
{
    char c1[21], c2[21];
    h_table* ht1[BUCKET_SIZE];
    f_table ft1 = {NULL};
    for(int i = 0; i < BUCKET_SIZE; i++)
    {
        ht1[i] = (h_table*)malloc(sizeof(h_table));
        ht1[i]->length = 0;
    }
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        scanf("%s %s", c1, c2);
        insert_h_table(ht1[make_key_djb2(c1,BUCKET_SIZE)], c1, c2, &ft1);
    }
    for(int j = 0; j < M; j++)
    {
        scanf("%s", c1);
        printf("%s\n", read_h_table(ht1[make_key_djb2(c1,BUCKET_SIZE)],c1));
    }
    
    // free phase what is this..
    fnode* tmp = ft1.root;
    while(tmp != NULL)
    {
        free(tmp->free);
        fnode* tmp2 = tmp;
        tmp = tmp->next;
        free(tmp2);
    }
    for(int i = 0; i < BUCKET_SIZE; i++) free(ht1[i]);
}

data_t read_h_table(h_table* nt1, char* key)
{
    node* tmp = nt1->root;
    if(nt1->length >= 1)
    {
        while(1)
        {
            if(match_key(tmp->key, key))
                return tmp->data;
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

node* init_h_node(char* key, data_t value)
{
    node* tmp = malloc(sizeof(node));
    if(tmp == NULL) return NULL;
    tmp->next = NULL;
    strcpy(tmp->data, value);
    strcpy(tmp->key, key);
    return tmp;
}

void insert_h_table(h_table* nt1, char* key, data_t value,f_table* ft1)
{
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
    // free_table
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
void remove_h_table(h_table* nt1, char* key)
{
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
int search_h_table(h_table* nt1, char* key)
{
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