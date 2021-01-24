#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <stdexcept>
#include <iostream>
#include <vector>
#include <math.h>

/*
 * Binary Heap class
 */
template <typename T>
class BinaryHeap {
    public:
        void insert(const T& data)
        {
            if(elements.size() == 0)
            {
                elements.push_back(data);
                size = size + 1;
            }
            else
            {
                elements.push_back(data);

                up_heap(elements.size() - 1);

                size = size + 1;
            }
            
        }

        bool is_empty()
        {
            if(elements.size() == 0)
            {
                return  true;
                //throw std::invalid_argument("Empty List");
            }
            else
            {
                return false;
            }
                
        }

        T min()
        {
            if (elements.size() == 0)
            {
                throw std::invalid_argument("Empty List");
            }

            T min = elements.front();

            for(int i = 0; i < elements.size(); ++i) // iterate through the vector to find the minimum
            {
                if(elements.at(i) < min)
                {
                    min = elements.at(i);
                }
            }

            return min;
        }


        T remove_min()
        {
            if (elements.size() == 0)
            {
                throw std::invalid_argument("Empty List");
            }

            T n = elements.front();
        
            if (elements.size() == 1) // if it is the first element, then remove it
            {
                elements.erase(elements.begin());

                size = size - 1;

                return n;

            }
            else
            {
                swap(0, elements.size() - 1);

                elements.pop_back();

                size = size - 1;

                down_heap(0);

                return n;
            
            }
        }
    
    private:
        std::vector<T> elements{};
        int size = 0;
        void down_heap(int i);
        void up_heap(int i);

        //Pre-implemented helper functions
        void swap(int a, int b) { T c(elements[a]); elements[a] = elements[b]; elements[b] = c;}
        int right_child(int i) {return 2*i + 2;}
        int left_child(int i) {return 2*i + 1;}
        int parent(int i) {return floor((i-1)/2);}
        bool is_internal(int i) {return left_child(i) < size || right_child(i) < size;}
        bool is_leaf(int i) {return left_child(i) >= size && right_child(i) >= size;}
};

/*
 * Restores the binary heap property starting from a node that is smaller than its parent
 * O(log n)
 */
template <typename T>
void BinaryHeap<T>::up_heap(int i){
    int parent_index = parent(i);

    // recursive

    if (parent_index == 0)
    {
        if (elements.at(i) < elements.at(parent_index))
        {
            swap(i, parent_index);
        }
    }
    else
    {
        if (elements.at(i) < elements.at(parent_index))
        {
            swap(i, parent_index);
        }

        up_heap(parent_index); // restores from starting 
    }

}

/*
 * Restores the binary heap property starting from an node that is larger than its children
 * O(log n)
 */
template <typename T>
void BinaryHeap<T>::down_heap(int i){
    int right_index = right_child(i);
    int left_index = left_child(i);

    int parent_index = parent(i);

    int dex = i;

    if (elements[left_index] < elements[i] && left_index < size) // when left index less than vect
    {
        dex = left_index;
    }

    if(elements[right_index] < elements[dex] && right_index < size) // when right index greater than vect
    {
        dex = right_index;
    }

    if(dex != i)
    {
        swap(i, dex);

        down_heap(dex);
    }

}


#endif
