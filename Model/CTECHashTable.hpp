//
//  CTECHashTable.hpp
//  FixedNodes
//
//  Created by Nemelka, Sydney on 5/5/16.
//  Copyright © 2016 Nemelka, Sydney. All rights reserved.
//

#include "HashNode.cpp"

#ifndef CTECHashTable_hpp
#define CTECHashTable_hpp

#include <iostream>

namespace CTECData
{
    template <class Type>
    class CTECHashTable
    {
    private:
        int size;
        int capacity;
        int chainedCapacity;
        int chainedSize;
        CTECList<HashNode<Type>> * chainedStorage;
        HashNode<Type> * internalStorage;
        void updateChainCapacity();
        double efficiencyPercentage;
        
        int findPosition(const Type& value);
        int handleCollision(const Type& value);
        void updateSize();
    
        int getNextPrime();
        bool isPrime(int candidateNumber);
        
    public:
        CTECHashTable();
        ~CTECHashTable();
        void add(HashNode<Type> currentNode);
        void addChained(HashNode<Type> currentNode);
        
        void add(const Type & value);
        bool remove(const Type & value);
        bool contains(const Type & value);
        int getSize();
    };
}

#endif /* CTECHashTable_hpp */
