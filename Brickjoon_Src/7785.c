#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int i64_t;
typedef unsigned long long int ui64_t;

typedef int data_t;

typedef struct node
{
    char key[21];
    data_t data;
    struct node *next;
    struct node *iter_next;
    struct node *iter_prev;
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

int compare(const void* a, const void* b);
node* init_node(char* key, data_t value);
htable init_htable(int bsize);
void free_htable(htable ht1);

int match_key(void* a, void* b);
void insert_htable(htable ht1, char* key, data_t value, int bsize);
void remove_htable(htable ht1, char* key, int bsize);
int search_htable(htable ht1, char* key, int bsize);
node* index_htable(htable ht1, char* key, int bsize);

ui64_t make_key_djb2(char* key,int bsize);

int main(void)
{
    int n;
    char c1[20],c2[20];
    scanf("%d", &n);
    htable ht1 = init_htable(n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s %s", c1, c2);
        if(strcmp(c2, "enter") == 0) index_htable(ht1,c1,n)->data = 1;
        else remove_htable(ht1, c1, n);
    }
    char** arr1 = (char**)calloc(ht1.iter_len, sizeof(char*));
    for(int i = 0; i < ht1.iter_len; i++)
    {
        node* iter = ht1.iter_front;
        arr1[i] = (char*)calloc(10, sizeof(char));
        strcpy(arr1[i], iter->key);
        iter = iter->iter_next;
    }
    if(ht1.iter_len != 0) qsort(arr1, ht1.iter_len, sizeof(arr1[0]), compare);
    for(int i = 0; i < ht1.iter_len; i++)
        printf("%s\n", arr1[i]);
    free_htable(ht1);
}

int compare(const void* a, const void* b)
{
    return -strcmp(*(char**)a, *(char**)b); 
}

node* init_node(char* key, data_t value)
{
    node* tmp = malloc(sizeof(node));
    if(tmp == NULL) return NULL;
    tmp->next = NULL;
    tmp->iter_next = NULL;
    tmp->iter_prev = NULL;
    tmp->data = value;
    strcpy(tmp->key, key);
    return tmp;
}

htable init_htable(int bsize)
{
    htable ht1 = {NULL, NULL, NULL, 0};
    ht1.hlist = (hlist*)calloc(bsize, sizeof(hlist));
    for(int i = 0; i < bsize; i++)
    {
        ht1.hlist[i].root = NULL;
        ht1.hlist[i].hlist_len = 0;
    }
    return ht1;
}

void free_htable(htable ht1)
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
    printf("now here1\n");
    if(search_htable(ht1, key, bsize) == 0) insert_htable(ht1, key, 0, bsize);
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
    printf("now here2\n");
    hlist* hl1 = &ht1.hlist[make_key_djb2(key, bsize)];
    node* inode1 = init_node(key, value);
    if(hl1->hlist_len != 0)
    {
        inode1->next = hl1->root;
    }
    else
    {
        hl1->root = inode1;
    }
    if(ht1.iter_len != 0)
    {
        ht1.iter_back->iter_next = inode1;
        inode1->iter_prev = ht1.iter_back;
    }
    else
        ht1.iter_front = inode1;
    ht1.iter_back = inode1;
    hl1->hlist_len += 1;
    ht1.iter_len += 1;
}
void remove_htable(htable ht1, char* key, int bsize)
{
    printf("now here4\n");
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
    printf("now here3\n");
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