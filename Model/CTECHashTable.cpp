//
//  CTECHashTable.cpp
//  FixedNodes
//
//  Created by Nemelka, Sydney on 5/5/16.
//  Copyright © 2016 Nemelka, Sydney. All rights reserved.
//

#include "CTECHashTable.hpp"
#include <iostream>

using namespace std;
using namespace CTECData;

template <class Type>
CTECHashTable<Type> :: CTECHashTable()
{
    this->size = 0;
    this->capacity = 101;
    this->efficiencyPercentage = .667;
    this->internalStorage = new Type[capacity];
}

template <class Type>
CTECHashTable<Type> :: ~CTECHashTable()
{
    delete [] internalStorage;
}

template <class Type>
int CTECHashTable<Type> :: getSize()
{
    return this->size;
}

template <class Type>
void CTECHashTable<Type> :: add(const Type& value)
{
    if(!contains(value))
    {
        if(size/capacity >= this->efficiencyPercentage)
        {
            updateSize();
        }
        int insertionIndex = findPosition(value);
        
        if(internalStorage[insertionIndex] != nullptr)
        {
            while(internalStorage[insertionIndex] != nullptr)
            {
                insertionIndex = (insertionIndex + 1) % capacity;
            }
        }
     internalStorage[insertionIndex] = value;
    size++;
    }
}