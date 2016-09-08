#pragma once

#include <stdio.h>
#include <assert.h>
#include "types.h"

#define INIT_HEAP_SIZE (1 << 20)
#define ALLIGN_BY_16(x) (((((x) + 15) >> 4) << 4))

typedef struct heap_t { 
  storage_t storage; 
  memory_size_t free_index; 
  memory_size_t size; 
} heap_t; 

storage_t try_allocate(memory_size_t size) {
  storage_t storage = malloc(size);
  if(storage == NULL) {
  	fprintf(stderr, "Cannot allocate buffer of size %llu\n", size);
  	exit(1);
  }
  return storage;
}

heap_t initHeap(memory_size_t size) {
  heap_t heap;
  heap.storage = try_allocate(size);
  heap.free_index = 0;
  heap.size = size;
  return heap;
}

heap_t heapObject;

storage_t bulk_alloc(memory_size_t size) {
  memory_size_t aligned_size = ALLIGN_BY_16(size);
  memory_size_t new_free_index = heapObject.free_index + aligned_size;
  if (new_free_index >= heapObject.size) {
    heap_t oldHeapObject = heapObject;
    memory_size_t new_size = heapObject.size < INIT_HEAP_SIZE ? INIT_HEAP_SIZE : heapObject.size * 2;
    new_size = new_size < new_free_index ? heapObject.size + new_free_index : new_size;
    heapObject = initHeap(new_size);
    heapObject.free_index = oldHeapObject.free_index;
    // memcpy(heapObject.storage, oldHeapObject.storage, heapObject.free_index);
    // free(oldHeapObject.storage);
    fprintf(stderr, "Increased the size of heap into %llu, old size: %llu, neededSize: %llu!\n", heapObject.size, oldHeapObject.size, size); 
  } 
  storage_t allocatedStorage = (void *)((memory_size_t)heapObject.storage + heapObject.free_index);
  heapObject.free_index = new_free_index;
  return allocatedStorage;
}

void bulk_free(storage_t storage, memory_size_t size) {
  memory_size_t aligned_size = ALLIGN_BY_16(size);
  heapObject.free_index -= aligned_size;
  assert(heapObject.free_index >= 0);
}
