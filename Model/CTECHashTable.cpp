//
//  CTECHashTable.cpp
//  FixedNodes
//
//  Created by Nemelka, Sydney on 5/5/16.
//  Copyright © 2016 Nemelka, Sydney. All rights reserved.
//

#include "CTECHashTable.hpp"
#include <iostream>
#include <cmath>
using namespace std;


template <class Type>
CTECHashTable<Type> :: CTECHashTable()
{
    this->size = 0;
    this->capacity = 101;
    this->efficiencyPercentage = .667;
    this->internalStorage = new HashNode<Type>*[capacity];
    
    this->chainedSize = 0;
    this->chainedCapacity = 101;
    this->chainedStorage = new CTECList<HashNode <Type>>[chainedCapacity];



}

template <class Type>
bool CTECHashTable<Type> :: isPrime(int candidateNumber)
{
    bool isPrime = true;
    
    if(candidateNumber <= 1)
    {
        isPrime = false;
    }
    else if(candidateNumber == 2 || candidateNumber == 3)
    {
        isPrime = true;
    }
    else if(candidateNumber % 2 == 0)
    {
        isPrime = false;
    }
    else
    {
        for(int spot = 3; spot < sqrt(candidateNumber) + 1; spot+=2)
        {
            if(spot)
            {
                isPrime = false;
                break;
            }
        }
    }
    return isPrime;
}

template <class Type>
CTECHashTable<Type> :: ~CTECHashTable()
{
    delete [] internalStorage;
    delete [] chainedStorage;
}

template <class Type>
int CTECHashTable<Type> :: getSize()
{
    return this->size;
}

template <class Type>
void CTECHashTable<Type> :: add(HashNode<Type> currentNode)
{
    if(!contains(currentNode))
    {
        if(size/capacity >= this->efficiencyPercentage)
        {
            updateCapacity();
        }
        int insertionIndex = findPosition(currentNode);
        
        if(internalStorage[insertionIndex] != nullptr)
        {
            insertionIndex = handleCollision(currentNode);
            
            while(internalStorage[insertionIndex] != nullptr)
            {
                insertionIndex = (insertionIndex + 1) % capacity;
            }
        }
     internalStorage[insertionIndex] = &currentNode;
    size++;
    }
}

template <class Type>
bool CTECHashTable<Type> :: contains(HashNode<Type> currentNode)
{
    bool isInTable = false;
    int possibleLocation = findPosition(currentNode);
    
    while(internalStorage[possibleLocation] != nullptr && !isInTable)
    {
        if(internalStorage[possibleLocation]->getValue() == currentNode.getValue())
        {
            isInTable = true;
        }
        possibleLocation = (possibleLocation + 1) % capacity;
    }
    
    return isInTable;
}

template <class Type>
void CTECHashTable<Type> :: updateCapacity()
{
    int updatedCapacity = getNextPrime();
    int oldCapacity = capacity;
    capacity = updatedCapacity;
    
    HashNode<Type> ** largerStorage = new HashNode<Type>*[capacity];
    
    for(int index = 0; index < oldCapacity; index++)
    {
        if(internalStorage[index] != nullptr)
        {
            int updatedIndex = findPosition(*internalStorage[index]);
            largerStorage[updatedIndex] = internalStorage[index];
        }
    }
    
    internalStorage = largerStorage;
}

template <class Type>
bool CTECHashTable<Type> :: remove(HashNode<Type> currentNode)
{
    bool hasBeenRemoved = false;
    
    if(contains(currentNode))
    {
        int possibleLocation = findPosition(currentNode);
        
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

template <class Type>
int CTECHashTable<Type> :: handleCollision(HashNode<Type> currentNode)
{
    int updatedPosition = findPosition(currentNode);
    
    updatedPosition = (47 + (updatedPosition * updatedPosition)) % capacity;
    
    return updatedPosition;
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
void CTECHashTable<Type> :: updateChainCapacity()
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
            for(int innerIndex = 0; innerIndex < temp.getSize(); innerIndex++)
            {
                int updatedChainedPosition = findPositiont(temp.getFromIndex(innerIndex));
                if(largerChainedStorage[updatedChainedPosition] == nullptr)
                {
                    CTECList<HashNode<Type>> insertList;
                    insertList.addEnd(temp.getFromIndex(innerIndex));
                    largerChainedStorage[updatedChainedPosition] = insertList;
                }
                else
                {
                    largerChainedStorage[updatedChainedPosition].addEnd(temp.getFromIndex(innerIndex));
                }
            }
        }
    }
}


















