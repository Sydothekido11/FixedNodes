//
//  CTECHashTable.hpp
//  FixedNodes
//
//  Created by Nemelka, Sydney on 5/5/16.
//  Copyright © 2016 Nemelka, Sydney. All rights reserved.
//

#include "HashNode.cpp"
#include "CTECList.h"

#ifndef CTECHashTable_hpp
#define CTECHashTable_hpp

#include <iostream>



    template <class Type>
    class CTECHashTable
    {
    private:
        int size;
        int capacity;
        int chainedCapacity;
        int chainedSize;
        CTECList<HashNode<Type>> * chainedStorage;
        HashNode<Type> ** internalStorage;
        void updateChainCapacity();
        double efficiencyPercentage;
        
        int findPosition(HashNode<Type> currentNode);
        int handleCollision(HashNode<Type> currenNode);
        void updateCapacity();
    
        int getNextPrime();
        bool isPrime(int candidateNumber);
        
    public:
        CTECHashTable();
        ~CTECHashTable();
        void add(HashNode<Type> currentNode);
        void addChained(HashNode<Type> currentNode);
        
       
        bool remove(HashNode<Type> currentNode);
        bool contains(HashNode<Type> currentNode);
        int getSize();
    };


#endif /* CTECHashTable_hpp */
