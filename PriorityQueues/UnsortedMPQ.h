#ifndef UNSORTEDMPQ_H
#define UNSORTEDMPQ_H

#include <stdexcept>
#include <vector>
#include "MPQ.h"

/*
 * Minimum Priority Queue based on a vector
 */
template <typename T>
class UnsortedMPQ: MPQ<T> {
    private:
        std::vector<T> vect;

    public:

        void insert(const T& val) {
            vect.push_back(val);
        }


        bool is_empty()
        {
            if (vect.size() == 0)
            {
                return true;
            }
            else 
            {
                return false;
            }
        }

        T remove_min()
        {
            if(vect.size() == 0)
            {
                throw std::invalid_argument("Empty List");
            }

            int minIndex = 0;

            T min = vect.front();

            for(int i = 0; i < vect.size(); i++)
            {
                if(vect.at(i) < min)
                {
                    min = vect.at(i);
                    minIndex = i;
                }
            }

            vect.erase(vect.begin() + minIndex); // removing specific index

            return min;
    }

    T min()
    {
        if (vect.size() == 0)
        {
            throw std::invalid_argument("Empty List");
        }

        T min = vect.front();

        for (int i = 0; i < vect.size(); ++i)
        {
            if (vect.at(i) < min) {
                min = vect.at(i);
            }
        }

        return min;
    }


   
};

#endif