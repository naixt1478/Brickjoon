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
    node *next;
    node *iter_next;
    node *iter_prev;
} node;

typedef struct hlist
{
    node* root;
    int hlist_len;
} hlist;

typedef struct htable
{
    hlist* hlist;
    node* iter_front;
    node* iter_back;
    int iter_len;
} htable;

node* init_node(char* key, data_t value);
htable init_htable(int bsize);
void free_htable(htable ht1, int bsize);

int match_key(void* a, void* b);
void insert_htable(htable ht1, char* key, data_t value, int bsize);
void remove_htable(htable ht1, char* key, int bsize);
int search_htable(htable ht1, char* key, int bsize);
node* index_htable(htable ht1, char* key, int bsize);

ui64_t make_key_djb2(char* key,int bsize);

int main(void)
{
    
}

node* init_node(char* key, data_t value)
{
    node* tmp = malloc(sizeof(node));
    if(tmp == NULL) return NULL;
    tmp->next = NULL;
    tmp->iter_next = NULL;
    tmp->iter_prev = NULL;
    strcpy(tmp->data, value);
    strcpy(tmp->key, key);
    return tmp;
}

htable init_htable(int bsize)
{
    htable ht1 = {NULL, NULL, NULL, 0};
    ht1.hlist = (hlist*)calloc(bsize, sizeof(hlist));
    for(int i = 0; i < bsize; i++)
        ht1.hlist[i].root = NULL;
    return ht1;
}

void free_htable(htable ht1, int bsize)
{
    node* iter_node1 = ht1.iter_front;
    node* iter_node2 = NULL;
    while(iter_node1 != NULL)
    {
        iter_node2 = iter_node1;
        free(iter_node2);
        iter_node2 = NULL;
        iter_node1 = iter_node1->iter_next;
    }
    free(ht1.hlist);
}

node* index_htable(htable ht1, char* key, int bsize)
{
    if(!search_htable(ht1, key, bsize)) insert_htable(ht1, key, 0, bsize);
    hlist hl1 = ht1.hlist[make_key_djb2(key, bsize)];
    node* iter_node = hl1.root;
    while(iter_node != NULL)
    {
        if(match_key(iter_node->key, key))
            return iter_node;
        iter_node = iter_node->next;
    }
    return NULL;
}

void insert_htable(htable ht1, char* key, data_t value, int bsize)
{
    hlist hl1 = ht1.hlist[make_key_djb2(key, bsize)];
    node* inode1 = init_node(key, value);
    if(hl1.hlist_len > 0)
        inode1->next = hl1.root;
    hl1.root = inode1;
    if(ht1.iter_len > 0)
    {
        ht1.iter_back->iter_next = inode1;
        inode1->iter_prev = ht1.iter_back;
    }
    else
        ht1.iter_front = inode1;
    ht1.iter_back = inode1;
    hl1.hlist_len += 1;
    ht1.iter_len += 1;
}
void remove_htable(htable ht1, char* key, int bsize)
{
    hlist hl1 = ht1.hlist[make_key_djb2(key, bsize)];
    node* iter_pnode = NULL;
    node* iter_node = hl1.root;
    while(hl1.hlist_len != 0 && iter_node != NULL)
    {
        if(match_key(iter_node->key,key))
        {
            hl1.hlist_len -= 1;
            ht1.iter_len -= 1;
            node* t1 = iter_node->next;
            if(iter_node->iter_prev != NULL) iter_node->iter_prev->iter_next = iter_node->iter_next;
            if(iter_node->iter_next != NULL) iter_node->iter_next->iter_prev = iter_node->iter_prev;
            if(iter_pnode != NULL) iter_pnode->next = t1;
            else hl1.root = t1;
            free(iter_node);
        }
        iter_pnode = iter_node;
        iter_node = iter_node->next;
    }
}
int search_htable(htable ht1, char* key, int bsize)
{
    hlist hl1 = ht1.hlist[make_key_djb2(key, bsize)];
    node* iter_node = hl1.root;
    while(hl1.hlist_len != 0 && iter_node != NULL)
    {
        if(match_key(iter_node->key, key))
            return 1;
        iter_node = iter_node->next;
    }
    return 0;
}

int match_key(void* a, void* b)
{
    return ((strcmp(a,b) == 0) ? 1 : 0);
}

ui64_t make_key_djb2(char* key, int bsize)
{
    ui64_t h = 5381;
    int c;
    while ((c = *key++))
        h = ((h << 5) + h) + c; /* hash * 33 + c */
    return h % bsize;
}