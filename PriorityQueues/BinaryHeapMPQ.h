#ifndef BINARYHEAP_MPQ_H
#define BINARYHEAP_MPQ_H

#include "BinaryHeap.h"
#include <stdexcept>
#include "MPQ.h"

/*
 * Minimum Priority Queue based on a binary heap
 */
template <typename T>
class BinaryHeapMPQ: MPQ<T> {
    private:
        BinaryHeap<T> binary_heap;
    
    public:

        T remove_min() {
            return binary_heap.remove_min();
        }

        T min() {
            return binary_heap.min();
        }

        bool is_empty()
        {
            return binary_heap.is_empty();

        }

        void insert(const T& data)
        {
            binary_heap.insert(data);

        }

    
};

#endif