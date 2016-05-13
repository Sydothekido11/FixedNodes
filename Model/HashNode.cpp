//
//  HashNode.cpp
//  FixedNodes
//
//  Created by Nemelka, Sydney on 5/13/16.
//  Copyright © 2016 Nemelka, Sydney. All rights reserved.
//

#include "HashNode.hpp"
template <class Type>
HashNode<Type> :: HashNode(int key, const Type& value)
{
    this->key = key;
    this->value = value;
}

template <class Type>
int HashNode<Type> :: getKey()
{
    return key;
}

template <class Type>
Type HashNode<Type> :: getValue()
{
    return value;
}
