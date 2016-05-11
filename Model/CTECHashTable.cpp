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
template <class Type>
int CTECHashTable<Type> :: findPosition(HashNode<Type> currentNode)
{
    int position = 0;
    position = currentNode.getKey() % capacity;
    return position;
}

template < class Type>
int CTECHashTable<Type> :: getNextPrime()
{
    int nextPrime = capacity;
    
    nextPrime *= 2;
    nextPrime++;
    
    while(!isPrime(nextPrime))
    {
        nextPrime+=2;
    }
    
    return nextPrime;
}



possibleLocation = (possibleLocation + 1) % capacity;

}



return isInTable;

}


template<class Type>

bool CTECHashTable<Type> :: remove(HashNode<Type> currentNode)

{
    
    bool hasBeenRemoved = false;
    
    if(contains(currentNode))
        
    {
        
        int possibleLocation = findPos(currentNode);
        
        
        
        while(internalStorage[possibleLocation] && !hasBeenRemoved)
            
        {
            
            if(internalStorage[possibleLocation].getValue() == currentNode.getValue())
                
            {
                
                hasBeenRemoved = true;
                
                internalStorage[possibleLocation] = nullptr;
                
            }
            
            possibleLocation = (possibleLocation + 1) % capacity;
            
        }
        
        
    }
    
}





template<class Type>

int CTECHashTable<Type> :: handleCollision(HashNode<Type> currentNode)

{
    
    int updatedPos = findPos(currentNode);
    
    
    
    
    
    updatedPos = ( 47 + (updatedPos * updatedPos)) % capacity;
    
    
    
    
    
    
    
    return updatedPos;
    
}




template<class Type>

void CTECHashTable<Type> :: addChained(HashNode<Type> currentNode)

{
    
    if((chainedSize/chainedCapacity) >= efficiencyPercentage())
        
    {
        
        updateChainCapacity();
        
    }
    
    int insertionIndex = findPos(currentNode);
    
    if(chainedStorage[insertionIndex] != nullptr)
        
    {
        
        CTECList<HashNode<Type>> temp = chainedStorage[insertionIndex];
        
        temp.addEnd(currentNode);
        
    }
    
    else
        
    {
        
        CTECList<HashNode<Type>> tempList;
        
        tempList.addEnd(currentNode);
        
        chainedStorage[insertionIndex] = tempList;
        
    }
    
    chainedSize++;
    
}



template <class Type>
void CTECHashTable<Type> :: updateChainedCapacity()
{
    int updatedChainedCapacity = getNextPrime();
    int oldChainedCapacity = chainedCapacity;
    chainedCapacity = updatedChainedCapacity;
    
    CTECList<HashNode<Type>> * largerChainedStorage = new CTECList<HashNode<Type>>[updatedChainedCapacity];
    
    for(int index = 0; index < oldChainedCapacity; index++)
    {
        if(chainedStorage[index] != nullptr)
        {
            CTECList<HashNode<Type>> temp = chainedStorage[index];
            for(int innderIndex = 0; innerIndex< temp.getSize(); innerIndex++)
            {
                int updatedChainedPosition = findPositiont(temp.getFromIndex(innerIndex));
                if(largerChainedStorage[updatedChainedPosition] == nullptr)
                {
                    CTECList<HashNode<Type>> insertList;
                    insertList.addEnd(temp.getFromIndex(innerIndex));
                    largerChainedStorage[updatedChainedPosition] = innerList;
                }
                else
                {
                    largerChainedStorage[updatedChainedPosition].addEnd(temp.getFromIndex(innerIndex));
                }
            }
        }
    }
}


















