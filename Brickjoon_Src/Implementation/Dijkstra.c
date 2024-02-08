#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stddef.h>
#define INF INT_MAX
#define NIL 0

typedef struct gnode
{
    int v,w;
    struct gnode *next;
} gnode;

typedef struct graph
{
    gnode *root;
} graph;

typedef struct heap_data
{
    int priority;
    int data;
} heap_data;

typedef enum heap_t
{
    MIN_HEAP,
    MAX_HEAP
} heap_t;

typedef struct vector
{
    heap_data* idx;
    size_t arr_len;
    size_t mem_len;
} vector;

typedef struct heap
{
    vector heap_vector;
    heap_t type;
    int heap_length;
} heap;

gnode* init_node(int v, int w);
void linked_list_add(graph* pg, int u, int v, int w);

void rpush(vector* pv, heap_data hd);
void rpop(vector* pv);
void rfree(vector* pv);
void iswap(heap_data* a, heap_data* b);

void init_heap(heap* _heap, heap_t h_t);
void heap_insert(heap* _heap, heap_data hd);
void heap_pop(heap* _heap);
void heap_free(heap* _heap);

heap_data heap_extract_root(heap _heap);

int n;
int V,E,K;
void dijkstra(graph* pg, int* pi, int n, int l2, int s);

int main(void)
{
    int u,v,w;
    scanf("%d %d", &V, &E);
    scanf("%d", &K);
    graph* pg1 = (graph*)malloc((V+1) * sizeof(graph));
    int* pi1 = (int*)calloc((V + 1), sizeof(int));
    for(int i = 1; i <= V; i++)
        pg1[i].root = NULL;
    for(int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        linked_list_add(pg1, u, v, w);
    }
    dijkstra(pg1, pi1, V, E, K);
    for(int i = 1; i <= V; i++)
    {
        if(pi1[i] == INF) printf("INF\n");
        else printf("%d\n", pi1[i]);
    }
    return 0;
}

gnode* init_node(int v, int w)
{
    gnode* tmp = malloc(sizeof(gnode));
    tmp->v = v;
    tmp->w = w;
    tmp->next = NULL;
    return tmp;
}
void linked_list_add(graph* pg, int u, int v, int w)
{
    gnode* tmp = init_node(v, w);
    tmp->next = (pg[u].root);
    pg[u].root = tmp;
}

void dijkstra(graph* pg, int* pi, int n, int l2, int s)
{
    for(int i = 0; i <= n; i++)
    {
        if(i != s) pi[i] = INF;
        else pi[i] = NIL;
    }
    heap h1;
    init_heap(&h1, MIN_HEAP);
    heap_insert(&h1, (heap_data){pi[s], s});
    while(h1.heap_length != 0)
    {
        heap_data hd1 = heap_extract_root(h1);
        heap_pop(&h1);
        if(pi[hd1.data] < hd1.priority)
            continue;
        gnode* tmp = pg[hd1.data].root;
        while(tmp != NULL)
        {
            int dt_i1 = hd1.priority + tmp->w;
            if(dt_i1 < pi[tmp->v])
            {
                pi[tmp->v] = dt_i1;
                heap_insert(&h1, (heap_data){dt_i1, tmp->v});
            }
            tmp = tmp->next;
        }
    }
    heap_free(&h1);
}

void rfree(vector* pv)
{
    free(pv->idx);
    pv->arr_len = NIL;
    pv->mem_len = NIL;
}

void heap_free(heap* _heap)
{
    rfree(&(_heap->heap_vector));
    _heap->heap_length = NIL;
}

heap_data heap_extract_root(heap _heap)
{
    if(_heap.heap_length == 0) return (heap_data){0, 0};
    else return _heap.heap_vector.idx[0];
}

void init_heap(heap* _heap, heap_t h_t)
{
    _heap->heap_length = 0;
    _heap->type = h_t;
    _heap->heap_vector.arr_len = 0;
    _heap->heap_vector.mem_len = 0;
    _heap->heap_vector.idx = NULL;
}

void heap_insert(heap* _heap, heap_data hd)
{
    vector* _pv = &_heap->heap_vector;
    rpush(_pv, hd);
    _heap->heap_length += 1;
    int now_idx = _heap->heap_length - 1;
    if(_heap->type == MAX_HEAP)
    {
        while(1)
        {
            int parent_idx = (now_idx - 1) / 2;
            if(parent_idx < 0) break;
            if(_pv->idx[parent_idx].priority < _pv->idx[now_idx].priority)
            {
                iswap(&(_pv->idx[parent_idx]), &(_pv->idx[now_idx]));
                now_idx = parent_idx;
            }
            else break;
        }
    }
    else if(_heap->type == MIN_HEAP)
    {
        while(1)
        {
            int parent_idx = (now_idx - 1) / 2;
            if(parent_idx < 0) break;
            if(_pv->idx[parent_idx].priority > _pv->idx[now_idx].priority)
            {
                iswap(&(_pv->idx[parent_idx]), &(_pv->idx[now_idx]));
                now_idx = parent_idx;
            }
            else break;
        }
    }
    else printf("type error\n");
}

void heap_pop(heap* _heap)
{
    if(_heap->heap_length == 0) return;
    vector* _pv = &_heap->heap_vector;
    iswap(&(_pv->idx[0]), &(_pv->idx[_heap->heap_length - 1]));
    rpop(_pv);
    _heap->heap_length -= 1;
    int now_idx = 0;
    if(_heap->type == MAX_HEAP)
    {
        while(1)
        {
            int largest = 0;
            int child_idx = (now_idx * 2) + 1;
            if(child_idx < _pv->arr_len && _pv->idx[child_idx].priority > _pv->idx[now_idx].priority)
            {
                largest = child_idx;
            }
            else
            {
                largest = now_idx;
            }
            if((child_idx + 1) < _pv->arr_len && _pv->idx[child_idx + 1].priority > _pv->idx[largest].priority)
                largest = child_idx + 1;
            if(largest != now_idx)
            {
                iswap(&(_pv->idx[now_idx]), &(_pv->idx[largest]));
                now_idx = largest;
            }
            else
                break;
        }
    }
    else if(_heap->type == MIN_HEAP)
    {
        while(1)
        {
            int shortest = 0;
            int child_idx = (now_idx * 2) + 1;
            if(child_idx < _pv->arr_len && _pv->idx[child_idx].priority < _pv->idx[now_idx].priority)
            {
                shortest = child_idx;
            }
            else
            {
                shortest = now_idx;
            }
            if((child_idx + 1) < _pv->arr_len && _pv->idx[child_idx + 1].priority < _pv->idx[shortest].priority)
                shortest = child_idx + 1;
            if(shortest != now_idx)
            {
                iswap(&(_pv->idx[now_idx]), &(_pv->idx[shortest]));
                now_idx = shortest;
            }
            else
                break;
        }
    }
}

void iswap(heap_data* a, heap_data* b)
{
    heap_data tmp = *b;
    *b = *a;
    *a = tmp;
}

void rpush(vector* pv, heap_data hd)
{
    if(pv->idx == NULL)
    {
        pv->mem_len = 1;
        pv->idx = calloc(1, sizeof(heap_data));
    }
    pv->arr_len += 1;
    if(pv->arr_len > pv->mem_len)
    {
        while(pv->mem_len <= pv->arr_len)
            pv->mem_len <<= 1;
        pv->idx = realloc(pv->idx, sizeof(heap_data) * pv->mem_len);
    }
    pv->idx[pv->arr_len - 1].priority = hd.priority;
    pv->idx[pv->arr_len - 1].data = hd.data;
}

void rpop(vector* pv)
{
    if(pv->arr_len == 0) return;
    pv->arr_len -= 1;
}