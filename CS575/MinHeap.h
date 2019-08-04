#ifndef HEAP
#define HEAP

#include "Pair.h"

class Heap
{
     private:
          vector<Pair> head;                 // Pointer to dynamically allocated array
          int size;                   // Number of elements in the heap              // Size of the array

     public:
          Heap();                     // Parameterized constructor
          ~Heap();                                 // Destructor
          void heapDown(int root, int last);   // Heapify after removing item
          void heapUp(int root, int last);     // Heapify after adding item
          bool push(Pair newNode);            // Add an item to the heap
          bool push(int data, int costs);      // Add an item to the heap
          Pair pop();                     // Get min-item
          bool isEmpty();                    // Print all the elements in the heap
};

#endif
