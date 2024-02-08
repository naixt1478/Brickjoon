#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stddef.h>

typedef struct vector
{
    int* arr;
    int arr_len;
    int mem_len;
} vector;

enum heap_t
{
    MIN_HEAP,
    MAX_HEAP
};

typedef struct heap
{
    vector heap;
    enum heap_t type;
} heap;

heap h1;

void rpush(vector* pv, int key);
void rpop(vector* pv);
void iswap(int* a, int* b);

void heap_insert(heap* _heap, int key);
void heap_pop(heap* _heap);
void heap_balance(heap* _heap, int p_idx, int c_idx);

int main(void)
{
    h1.type = MAX_HEAP;
    return 0;
}

void iswap(int* a, int* b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void heap_balance(heap* _heap, int p_idx, int c_idx)
{
    while(p_idx >= 0 && _heap->heap.arr[p_idx] != _heap->heap.arr[c_idx] 
    && (_heap->heap.arr[p_idx] < _heap->heap.arr[c_idx]) == _heap->type)
    {
        iswap(&_heap->heap.arr[p_idx], &_heap->heap.arr[c_idx]);
        c_idx = p_idx;
        p_idx = (c_idx - 1) / 2;
    }
}

void heap_insert(heap* _heap, int key)
{
    rpush(&_heap->heap, key);
    heap_balance(_heap, (_heap->heap.arr_len - 1) / 2, _heap->heap.arr_len - 1);
}

void heap_pop(heap* _heap)
{
    iswap(&_heap->heap.arr[0], &_heap->heap.arr[_heap->heap.arr_len - 1]);
    rpop(&_heap->heap);
    int c_idx = 0;
    int l_idx = c_idx*2 + 1;
    int r_idx = c_idx*2 + 2;
    int h_len = _heap->heap.arr_len;
    while(c_idx + 1 < h_len)
    {
        int i1 = c_idx;
        if(l_idx + 1 < h_len)
        {
            if((_heap->heap.arr[l_idx] > _heap->heap.arr[i1]) == _heap->type) i1 = l_idx;
        }
        if(r_idx + 1 < h_len)
        {
            if((_heap->heap.arr[r_idx] > _heap->heap.arr[i1]) == _heap->type) i1 = r_idx;
        }
        iswap(&_heap->heap.arr[i1], &_heap->heap.arr[c_idx]);
    }
}

void rpush(vector* pv, int key)
{
    pv->arr_len += 1;
    if(pv->arr_len > pv->mem_len)
    {
        while(pv->mem_len > pv->arr_len)
        {
            if(pv->mem_len == 0) pv->mem_len += 1;
            else pv->mem_len <<= 1;
        }
        pv->arr = realloc(pv->arr, sizeof(int) * pv->mem_len);
    }
    pv->arr[pv->arr_len - 1] = key;
}
void rpop(vector* pv)
{
    pv->arr_len -= 1;
}