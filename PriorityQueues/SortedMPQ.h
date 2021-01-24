#ifndef SORTEDMPQ_H
#define SORTEDMPQ_H

#include <stdexcept>
#include <list>
#include <iostream>
#include "MPQ.h"

/* Sameer Hussain - CSCE 221 - PA 4*/

/*
 * Minimum Priority Queue based on a linked list, can use STL
 * Should sort as you insert
 * Least at first index
 */
template <typename T>
class SortedMPQ: MPQ<T> {
private: 
    std::list<T> valsList;
public: 
    T remove_min() {
        if (is_empty())
        {
            throw std::invalid_argument("Empty List");
        }
        
        T val = valsList.front();

        valsList.pop_front();

        return val;
    };

    T min() {
        if (is_empty())
        {
            throw std::invalid_argument("Empty List");
        }
        
        return valsList.front();
    };
    
    bool is_empty() 
    {
        return valsList.empty();
    };

    void insert(const T& data);
};

template <typename T>
void SortedMPQ<T>::insert(const T& data) 
{
 bool inList = false; // if value is inserted

    if(valsList.size() == 0) 
    {
        valsList.push_back(data);
        bool inList = true;
    }

    /* typename list<T>::iterator it, it1;*/

    for (auto i = valsList.begin(); i != valsList.end(); i++) // go through list
    {
        if (data < *i) {

        valsList.insert(i, data);

        inList = true;

        break;

        }
    }

    if(!inList) 
    {
        valsList.push_back(data);
    }
}

#endif

