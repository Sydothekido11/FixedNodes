/*
 * CTECList.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: snem8901
 */

#include "CTECList.h"
#include "assert.h"

template<class Type>
CTECList<Type>::CTECList()
{
	this->size = 0;
	this->head = nullptr;
	this->end = nullptr;
}

template<class Type>
CTECList<Type>::~CTECList()
{

	ArrayNode<Type> * current = head;
	for(int deleteCount = 0; deleteCount < size; deleteCount++)
	{
		ArrayNode<Type> * temp = current;

		current = current->getNext();
		head = current;
		delete temp;

	}

	while(current->getNext() != nullptr)
	{
		ArrayNode<Type> * temp = current;

		current = current->getNext();
		head = current;
		delete temp;

	}

	delete head;
	head = nullptr;
	end = nullptr;
	size = 0;
}

template<class Type>
void CTECList<Type>::addAtIndex(int index, const Type& value)
{
	assert(size > 0);
	assert(index > 0);
	assert(index < size);

	ArrayNode<Type> * currentSpot = head;
	ArrayNode<Type> * nextSpot;
	ArrayNode<Type> * newNext;
	ArrayNode<Type> * newNode = new ArrayNode<Type>(value);

	for(int spot = 0; spot < index + 1; index++)
	{
        if(spot == index-1)
        {
            nextSpot = currentSpot;
        }
        
		if(spot == index)
		{
			newNext = currentSpot;
            nextSpot->setNext(newNode);
			
			newNode->setNext(newNext);
		}

		

		currentSpot = currentSpot->getNext();
	}
}

template<class Type>
void CTECList<Type>::addToEnd(const Type& value)
{
	assert(size > 0);

	ArrayNode<Type> * newEnd = new ArrayNode<Type>(value);
	ArrayNode<Type> * currentSpot = end;
	ArrayNode<Type> * newNext = newEnd;

	currentSpot->setNext(newNext);
	newNext->setNext(nullptr);



}

template<class Type>
void CTECList<Type>::addToFront(const Type& value)
{

	ArrayNode<Type> * current = head;
	ArrayNode<Type> * newFirst = new ArrayNode<Type>(value);

	newFirst->setNext(current);
	head = newFirst;
}

template<class Type>
Type CTECList<Type>::removeFromIndex(int index)
{
	Type returnValue;

	assert(size > 0);
	assert(index >= 0);
	assert(index < size);
	assert(size > 0 && index >= 0 && index < size);
}

template<class Type>
Type CTECList<Type>::removeFromFront()
{
	//Check that not removing from any empty list
	assert(size > 0);
	//Declare an variable of the type to return.
	Type thingToRemove;
	//Find the next spot.
	ArrayNode<Type> * newHead = new ArrayNode<Type>();
	newHead = head->getNext();
	//Get what head is holding.
	thingToRemove = this->head->getValue();
	//Remove what head is pointing to.
	delete head;
	//Move head to next spot.
	head = newHead;


	return thingToRemove;
}

template<class Type>
Type CTECList<Type>::removeFromBack()
{
	assert(size > 0);
	Type returnValue;

	if(size == 1)
	{
		ArrayNode<Type> * toRemove = end;
		returnValue = removeFromFront();
		end = nullptr;
		head = nullptr;
		delete toRemove;

	}
	else
	{
		ArrayNode<Type> * current = head;
		for(int index = 0; index < size - 1; index++)
		{
			current = current->getNext();
		}

		returnValue = end->getValue();
		delete end;
		current = end;
		current->setNext(nullptr);
	}

	calculateSize();

	return returnValue;


}

template<class Type>
Type CTECList<Type>::removeFromPosition(int index)
{

	assert(index >= 0);
	assert(index < size);
	assert(this->size>0);
	Type storedValue;
	ArrayNode<Type> * current = head;
	ArrayNode<Type> * previousSpot;
	ArrayNode<Type> * newNext;

	for(int spot = 0; spot < index +1; spot++)
	{
		if(spot == index-1)
		{
			previousSpot = current;
		}
		if(spot == index)
		{
			storedValue = current->getValue();
			newNext = current->getNext();
			delete current;
		}

		current = current->getNext();
	}

	previousSpot->setNext(newNext);
	return storedValue;


}

template<class Type>
void CTECList<Type>::calculateSize()
{
	assert(size >= 0);

	int count = 0;
	if(head == nullptr)
	{
		size = 0;
	}
	else
	{
		count++;
		ArrayNode<Type> * current = head;
		while(current->getNext() != nullptr)
		{
			count++;
			current = current->getNext();
		}
		size = count;
	}


}

template <class Type>
int CTECList<Type> :: indexOf(Type searchValue)
{
    assert(this->size > 0);
    
    int index = 0;
    
    ArrayNode<Type> * searchPointer;
    
    for(searchPointer = head; searchPointer != nullptr; searchPointer = searchPointer ->getNext())
    {
        if(searchValue == searchPointer->getValue())
        {
            return index;
        }
    }
    
    index = -1;
    return index;
}

template<class Type>
void CTECList<Type>::swap(int indexOne, int indexTwo)
{
    assert(indexOne < size && indexTwo < size);
    Type temp = getFromIndex(indexOne);
    set(indexOne, getFromIndex(indexTwo));
    set(indexTwo, temp);
}

template<class Type>
void CTECList<Type> :: selectionSort()
{
    for(int outerLoop = 0; outerLoop < size-1; outerLoop++)
    {
        int selectedMinimum = outerLoop;
        
        for(int innerLoop = outerLoop+1; innerLoop < size; innerLoop++)
        {
         
            if(getFromIndex(innerLoop) < getFromIndex(selectedMinimum))
            {
                selectedMinimum = innerLoop;
            }
        }
        
        if(selectedMinimum != outerLoop)
        {
            swap(selectedMinimum, outerLoop);
        }
    }
}


