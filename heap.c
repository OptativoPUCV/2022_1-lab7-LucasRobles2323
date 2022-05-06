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
      pq->capac = 2 * pq->capac;
      pq->capac += 1;
      pq->heapArray = (heapElem*) realloc (pq->heapArray, pq->capac * sizeof(heapElem));
      for (size_t i = pq->size; i < pq->capac; i++)
      {
         pq->heapArray[i].priority = 0;
      }
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
      index = dadIndex;
      dadIndex = (int) (index - 1)/2;
   }
   pq->size += 1;
}


void heap_pop(Heap* pq){
   if(pq->size == 0){return;}
   pq->heapArray[0].priority = 0;
   
   heapElem aux;
   aux = pq->heapArray[0];
   pq->heapArray[0] = pq->heapArray[pq->size - 1];
   pq->heapArray[pq->size - 1] = aux;
   pq->size--;

   int actual = 0;
   int sonDer;
   int sonIzq;
   int sonCambiar;

   while (actual < pq->size)
   {
      sonDer = (2 * actual) + 2;
      sonIzq = (2 * actual) + 1;

      if(sonDer >= pq->size && sonIzq >= pq->size){return;}
      else if(sonDer >= pq->size || sonIzq >= pq->size){
         if (sonDer >= pq->size)
         {
            sonCambiar = sonIzq;
         }
         else{ sonCambiar = sonDer;}
      }
      else{
         if (pq->heapArray[sonDer].priority < pq->heapArray[sonIzq].priority)
         {sonCambiar = sonIzq;}
         else{sonCambiar = sonDer;}
      }
      
      if(pq->heapArray[sonCambiar].priority == 0 || 
         pq->heapArray[sonCambiar].priority < pq->heapArray[actual].priority)
      {return;}
      aux = pq->heapArray[actual];
      pq->heapArray[actual] = pq->heapArray[sonCambiar];
      pq->heapArray[sonCambiar] = aux;
      actual = sonCambiar;
   }
}


Heap* createHeap(){
   Heap *dinamic = (Heap*) malloc (sizeof(Heap));
   assert(dinamic);
   dinamic->heapArray = (heapElem*) calloc (3, sizeof(heapElem));
   dinamic->capac = 3;
   dinamic->size = 0;
   return dinamic;
}
