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
   if(pq->size == 0){return NULL;}
   return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
   if(pq->size == pq->capac){
      pq->size = 2 * pq->size;
      pq->size += 1;
      pq->heapArray = (heapElem*) realloc (pq->heapArray, sizeof(heapElem) * pq->size);
   }

   for (size_t i = 0; i < pq->capac; i++)
   {
      if(pq->heapArray[i].priority == priority){
         return;
      }
   }
   int index;
   for (size_t i = 0; i < pq->capac; i++)
   {
      if(pq->heapArray[i].priority == 0){
         pq->heapArray[i].data = data;
         pq->heapArray[i].priority = priority;
         index = i;
         break;
      }
   }

   int dadIndex = (int) (index - 1)/2;
   heapElem aux;
   while (pq->heapArray[dadIndex].priority < pq->heapArray[index].priority)
   {
      aux = pq->heapArray[dadIndex];
      pq->heapArray[dadIndex] = pq->heapArray[index];
      pq->heapArray[index] = aux;
   }
   pq->size += 1;
   printf("\n");
   for (size_t i = 0; i < pq->capac; i++)
   {
      printf("%5d", pq->heapArray[i].priority);
   }
   printf("\n");

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
