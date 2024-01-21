#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int i64_t;
typedef unsigned long long int ui64_t;
typedef unsigned int ui32_t;

typedef int data_t;
typedef char* sort_t;
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

void merge_sort(sort_t* arr, int len, int (*comp)(void*,void*));
void merge(sort_t* arr, sort_t* warr, int l1, int r1, int e1, int (*comp)(void*,void*));
int comp(void* a, void* b);

node* init_node(char* key, data_t value);
htable init_htable(int bsize);
void free_htable(htable* ht1);

int match_key(void* a, void* b);
void insert_htable(htable* ht1, char* key, data_t value, int bsize);
void remove_htable(htable* ht1, char* key, int bsize);
node* search_htable(htable* ht1, char* key, int bsize);

ui32_t make_key(const char* key,int bsize);

int main(void)
{
    freopen("7785.in", "r", stdin);
    freopen("7785.out", "w", stdout);
    int n,j = 0;
    char c1[20],c2[20];
    scanf("%d", &n);
    htable ht1 = init_htable(n*2);
    for(int i = 0; i < n; i++)
    {
        scanf("%s %s", c1, c2);
        if(c2[0] == 'e') insert_htable(&ht1, c1, 1, n*2);
        else remove_htable(&ht1, c1, n*2);
    }
    char** arr1 = (char**)malloc(ht1.iter_len*sizeof(char*));
    for(int i = 0; i < n*2; i++)
    {
        node* tmp = ht1.hlist[i].root;
        if(ht1.hlist[i].hlist_len == 0) continue;
        while(tmp != NULL)
        {
            arr1[j] = tmp->key;
            tmp = tmp->next;
            j++;
        }
    }
    if(ht1.iter_len != 0) merge_sort(arr1,ht1.iter_len,comp);
    for(int i = 0; i < ht1.iter_len; i++)
        printf("%s\n", arr1[i]);
    free_htable(&ht1);
}

int comp(void* a, void* b)
{
    if(strcmp(*(sort_t*)a, *(sort_t*)b) <= 0) return 1;
    else return 0;
}

void merge_sort(sort_t* arr, int len, int (*comp)(void*,void*))
{  
    sort_t* warr = (sort_t*)malloc(len*sizeof(sort_t));
    memcpy(warr, arr, len*sizeof(sort_t));
    for(int i = 1; i < len; i*=2)
    {
        for(int j = 0; j < len; j += 2 * i)
        {
            merge(arr, warr, j, min(j+i, len), min(j+i*2,len), comp);
        }
        memcpy(arr, warr, len*sizeof(sort_t));
    }
    free(warr);
}

void merge(sort_t* arr, sort_t* warr, int l1, int r1, int e1, int (*comp)(void*,void*))
{
    int i = l1;
    int j = r1;
    for(int k = l1; k < e1; k++)
    {
        if(i < r1 && (j >= e1 || (*comp)((void*)&arr[i], (void*)&arr[j])))
        {
            warr[k] = arr[i];
            i++;
        }
        else
        {
            warr[k] = arr[j];
            j++;
        }
    }
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
    return ht1;
}

void free_htable(htable* ht1)
{
    node* iter_node1 = ht1->iter_front;
    node* iter_node2 = NULL;
    while(iter_node1 != NULL)
    {
        iter_node2 = iter_node1;
        free(iter_node2);
        iter_node2 = NULL;
        iter_node1 = iter_node1->iter_next;
    }
    free(ht1->hlist);
}

void insert_htable(htable* ht1, char* key, data_t value, int bsize)
{
    hlist* hl1 = &ht1->hlist[make_key(key, bsize)];
    node* inode1 = init_node(key, value);
    if(hl1->hlist_len != 0)
        inode1->next = hl1->root;
    hl1->root = inode1;
    if(ht1->iter_len > 0)
    {
        node* tmp1 = ht1->iter_back;
        ht1->iter_back = inode1;
        tmp1->iter_next = ht1->iter_back;
        ht1->iter_back->iter_prev = tmp1;
    }
    else
    {
        ht1->iter_front = inode1;
        ht1->iter_back = inode1;
    }
    hl1->hlist_len += 1;
    ht1->iter_len += 1;
    node* tmp2 = ht1->iter_front;
    while(tmp2 != NULL)
        tmp2 = tmp2->iter_next;
}
void remove_htable(htable* ht1, char* key, int bsize)
{
    hlist* hl1 = &ht1->hlist[make_key(key, bsize)];
    node* iter_pnode = NULL;
    node* iter_node = hl1->root;
    if(hl1->hlist_len == 0) return;
    while(iter_node != NULL)
    {
        if(match_key(iter_node->key,key))
        {
            hl1->hlist_len -= 1;
            ht1->iter_len -= 1;
            if(iter_node->iter_prev == NULL && iter_node->iter_next == NULL)
            { 
                ht1->iter_front = NULL;
                ht1->iter_back = NULL;
            }
            else if(iter_node->iter_next != NULL && iter_node->iter_prev == NULL) 
            {
                ht1->iter_front = iter_node->iter_next;
                iter_node->iter_next->iter_prev = NULL;
            }
            else if(iter_node->iter_next == NULL && iter_node->iter_prev != NULL)
            {
                ht1->iter_back = iter_node->iter_prev;
                iter_node->iter_prev->iter_next = NULL;
            }
            else
            {
                iter_node->iter_prev->iter_next = iter_node->iter_next;
                iter_node->iter_next->iter_prev = iter_node->iter_prev;
            }

            if(iter_pnode == NULL)
                hl1->root = iter_node->next;
            else
                iter_pnode->next = iter_node->next;
            free(iter_node);
        }
        iter_pnode = iter_node;
        iter_node = iter_node->next;
    }
}
node* search_htable(htable* ht1, char* key, int bsize)
{
    hlist* hl1 = &ht1->hlist[make_key(key, bsize)];
    node* iter_node = hl1->root;
    if(hl1->hlist_len == 0) return NULL;
    while(iter_node != NULL)
    {
        if(match_key(iter_node->key, key))
            return iter_node;
        iter_node = iter_node->next;
    }
    return NULL;
}

int match_key(void* a, void* b)
{
    return ((strcmp(a,b) == 0) ? 1 : 0);
}

ui32_t make_key(const char* key, int bsize)
{
    // one_at_a_time
    size_t i = 0;
    ui64_t length = strlen(key);
    ui32_t hash = 0;
    while (i != length) {
    hash += (unsigned char)key[i++];
    hash += hash << 10;
    hash ^= hash >> 6;
    }
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    return hash % bsize;
}