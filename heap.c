#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
   if(pq->heapArray[0].priority == 0 || pq->heapArray->data == NULL){return NULL};
   return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
   Heap *dinamic = (Heap*) malloc (sizeof(Heap));
   assert(dinamic);
   dinamic->heapArray = (heapElem*) calloc (3, sizeof(heapElem));
   dinamic->capac = 3;
   dinamic->size = 0;
   return dinamic;
}
