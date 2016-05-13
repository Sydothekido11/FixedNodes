//
//  HashNode.hpp
//  FixedNodes
//
//  Created by Nemelka, Sydney on 5/13/16.
//  Copyright © 2016 Nemelka, Sydney. All rights reserved.
//

#ifndef HashNode_hpp
#define HashNode_hpp

#include <stdio.h>
#include <iostream>

template <class Type>
class HashNode
{
private:
    int key;
    Type value;
    
public:
    HashNode(int key, const Type& value);
    int getKey();
    Type getValue();
};

#endif /* HashNode_hpp */
