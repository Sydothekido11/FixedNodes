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
//CTECList<Type>::CTECList()
//{
//    this->size = 0;
//    this->head = nullptr;
//    this->end = nullptr;
//    
//}
template<class Type>
CTECList<Type>::~CTECList()
{
    
    
    
    
}
template<class Type>
void CTECList<Type>::addAtIndex(int index, const Type& value)
{
    assert(size > 0);
    assert(index > 0);
    assert(index < size);
    
    ArrayNode<Type> * currentSpot = head;
    ArrayNode<Type> * nextSpot = nullptr;
    ArrayNode<Type> * newNext;
    ArrayNode<Type> * newNode = new ArrayNode<Type>(value);
    
    for (int spot = 0; spot < index + 1; index++)
    {
        
        if (spot == index - 1)
        {
            newNext = newNode;
            currentSpot->setNext(newNext);
            newNext->setNext(nextSpot);
            
        }
        
        if (spot == index + 1)
        {
            nextSpot = currentSpot->getNext();
        }
        
        currentSpot = currentSpot->getNext();
    }
    
    calculateSize();
    
}
template<class Type>
void CTECList<Type>::addToEnd(const Type& value)
{
    assert(size >= 0);
    
    
    ArrayNode<Type> * newEnd = new ArrayNode<Type>(value);
    
    ArrayNode<Type> * currentSpot = end;
    std::cout<<"print this" << std::endl;
    currentSpot->setNext(newEnd);
    
    end = newEnd;
    
    
    calculateSize();
}
template<class Type>
void CTECList<Type>::addToFront(const Type& value)
{
    
    ArrayNode<Type> * current = head;
    ArrayNode<Type> * newFirst = new ArrayNode<Type>(value);
    
    newFirst->setNext(current);
    head = newFirst;
    if(end == nullptr)
    {
        end = head;
    }
    
    calculateSize();
}




template<class Type>
void CTECList<Type> :: swap(int indexOne, int indexTwo)
{
    assert(indexOne < size && indexTwo < size);
    Type temp = getFromIndex(indexOne);
    set(indexOne, getFromIndex(indexTwo));
    set(indexTwo, temp);
}

template<class Type>
void CTECList<Type>::selectionSort()
{
    for(int outerLoop = 0; outerLoop < size - 1; outerLoop++)
    {
        int selectedMin = outerLoop;
        
        for(int innerLoop = outerLoop + 1; innerLoop < size; innerLoop++)
        {
            if(getFromIndex(innerLoop) < getFromIndex(selectedMin))
            {
                selectedMin = innerLoop;
            }
        }
        if(selectedMin != outerLoop)
        {
            swap(selectedMin, outerLoop);
        }
        
        
    }
}



template<class Type>
Type CTECList<Type>::removeFromFront()
{
    
    assert(this->size > 0);
    
    Type thingToRemove;
    ArrayNode<Type> * newHead = new ArrayNode<Type>();
    newHead = head->getNext();
    thingToRemove = this->head->getValue();
    delete this->head;
    
    this->head = newHead;
    
    return thingToRemove;
    
    calculateSize();
}
template<class Type>
Type CTECList<Type>::removeFromIndex(int index)
{
    assert(index >= 0);
    assert(index < size);
    assert(this->size > 0);
    Type storedValue = 0;
    ArrayNode<Type> * current = head;
    ArrayNode<Type> * previousSpot = nullptr;
    ArrayNode<Type> * newNext = nullptr;
    
    for (int spot = 0; spot < index + 1; spot++)
    {
        if (spot == index - 1)
        {
            previousSpot = current;
        }
        if (spot == index)
        {
            storedValue = current->getValue();
            newNext = current->getNext();
            delete current;
        }
        
        current = current->getNext();
    }
    
    previousSpot->setNext(newNext);
    
    return storedValue;
    
    calculateSize();
}
template<class Type>
Type CTECList<Type>::removeFromEnd()
{
    assert(size > 0);
    
    Type returnValue;
    
    if (size == 1)
    {
        ArrayNode<Type> * toRemove = end;
        returnValue = removeFromFront();
        end = nullptr;
        delete toRemove;
    }
    else
    {
        ArrayNode<Type> * current = head;
        
        for (int spot = 0; spot < size - 1; spot++)
        {
            current = current->getNext();
        }
        
        returnValue = end->getValue();
        delete end;
        current = end;
        current->setNext(nullptr);
    }
    
    return returnValue;
    
    calculateSize();
    
}



template<class Type>
Type CTECList<Type>::getEnd()
{
    return end->getValue();
    
}
template<class Type>
Type CTECList<Type>::getFront()
{
    return head->getValue();
}
template<class Type>
Type CTECList<Type>::set(int pos, const Type& value)
{
    
    assert(pos < size && pos >= 0);
    ArrayNode<Type> * current = head;
    Type returnValue;
    
    for (int spot = 0; spot <= pos; spot++)
    {
        if (spot != pos)
        {
            current = current->getNext();
        }
        else
        {
            returnValue = current->getValue();
            current->setValue(value);
        }
        
    }
    
    return returnValue;
    
}

template<class Type>
Type CTECList<Type>::getFromIndex(int index)
{
    ArrayNode<Type> * current = head;
    Type valueHolder = 0;
    
    assert(index >= 0);
    assert(index < size);
    assert(this->size > 0);
    
    for (int spot = 0; spot <= index; spot++)
    {
        if (spot != index)
        {
            current->getNext();
        }
        else
        {
            valueHolder = current->getValue();
        }
    }
    
    return valueHolder;
    
}

template<class Type>
void CTECList<Type>::calculateSize()
{
    assert(size >= 0);
    int count = 0;
    if (head == nullptr)
    {
        size = count;
    }
    else
    {
        count++;
        ArrayNode<Type> * current = head;
        while(current->getNext() != nullptr)
        {
            current = current->getNext();
        }
    }
    size = count;
}


template <class Type>
int CTECList<Type> :: indexOf(Type searchValue)
{
    assert(this->size > 0);
    int index;
    
    ArrayNode<Type> * searchPointer;
    
    for(searchPointer = head; searchPointer != nullptr; searchPointer->getNext())
    {
        if(searchValue == searchPointer->getValue())
        {
            return index;
        }
        
        
        
        index++;
    }
    
    
    return index;
}


template<class Type>
int CTECList<Type>::getSize()
{
    return size;
}//template<class Type>
//CTECList<Type>::CTECList()
//{
//	this->size = 0;
//	this->head = nullptr;
//	this->end = nullptr;
//}
//
//template<class Type>
//CTECList<Type>::~CTECList()
//{
//
////	ArrayNode<Type> * current = head;
////	for(int deleteCount = 0; deleteCount < size; deleteCount++)
////	{
////		ArrayNode<Type> * temp = current;
////
////		current = current->getNext();
////		head = current;
////		delete temp;
////
////	}
////
////	while(current->getNext() != nullptr)
////	{
////		ArrayNode<Type> * temp = current;
////
////		current = current->getNext();
////		head = current;
////		delete temp;
////
////	}
////
////	delete head;
////	head = nullptr;
////	end = nullptr;
////	size = 0;
//}
//
//template<class Type>
//void CTECList<Type>::addAtIndex(int index, const Type& value)
//{
//	assert(size > 0);
//	assert(index > 0);
//	assert(index < size);
//
//	ArrayNode<Type> * currentSpot = head;
//	ArrayNode<Type> * nextSpot;
//	ArrayNode<Type> * newNext;
//	ArrayNode<Type> * newNode = new ArrayNode<Type>(value);
//
//	for(int spot = 0; spot < index + 1; index++)
//	{
//        if(spot == index-1)
//        {
//            nextSpot = currentSpot;
//        }
//        
//		if(spot == index)
//		{
//			newNext = currentSpot;
//            nextSpot->setNext(newNode);
//			
//			newNode->setNext(newNext);
//		}
//
//		
//
//		currentSpot = currentSpot->getNext();
//	}
//}
//
//template<class Type>
//void CTECList<Type>::addToEnd(const Type& value)
//{
//	assert(size >= 0);
//
//	ArrayNode<Type> * newEnd = new ArrayNode<Type>(value);
//	ArrayNode<Type> * currentSpot = end;
//    std::cout << "." << std::endl;
//	currentSpot->setNext(newNext);
//
//    end = newEnd;
//    
//    calculateSize();
//
//
//
//}
//
//template<class Type>
//void CTECList<Type>::addToFront(const Type& value)
//{
//
//	ArrayNode<Type> * current = head;
//	ArrayNode<Type> * newFirst = new ArrayNode<Type>(value);
//
//	newFirst->setNext(current);
//	head = newFirst;
//    if(end == nullptr)
//    {
//        end = head;
//    }
//    
//    calculateSize();
//}
//
//template<class Type>
//Type CTECList<Type>::removeFromIndex(int index)
//{
//	Type returnValue;
//
//	assert(size > 0);
//	assert(index >= 0);
//	assert(index < size);
//	assert(size > 0 && index >= 0 && index < size);
//}
//
//template<class Type>
//Type CTECList<Type>::removeFromFront()
//{
//
//	assert(size > 0);
//	
//	Type thingToRemove;
//	
//	ArrayNode<Type> * newHead = new ArrayNode<Type>();
//	newHead = head->getNext();
//	
//	thingToRemove = this->head->getValue();
//	
//	delete this->head;
//
//	this->head = newHead;
//
//
//	return thingToRemove;
//    
//    calculateSize();
//}
//
//template<class Type>
//Type CTECList<Type>::removeFromEnd()
//{
//	assert(size > 0);
//	Type returnValue;
//
//	if(size == 1)
//	{
//		ArrayNode<Type> * toRemove = end;
//		returnValue = removeFromFront();
//		end = nullptr;
//		
//		delete toRemove;
//
//	}
//	else
//	{
//		ArrayNode<Type> * current = head;
//		for(int spot = 0; spot < size - 1; spot++)
//		{
//			current = current->getNext();
//		}
//
//		returnValue = end->getValue();
//		delete end;
//		current = end;
//		current->setNext(nullptr);
//	}
//
//	calculateSize();
//
//	return returnValue;
//
//
//}
//
//template<class Type>
//Type CTECList<Type>::removeFromPosition(int index)
//{
//
//	assert(index >= 0);
//	assert(index < size);
//	assert(this->size>0);
//	Type storedValue;
//	ArrayNode<Type> * current = head;
//	ArrayNode<Type> * previousSpot;
//	ArrayNode<Type> * newNext;
//
//	for(int spot = 0; spot < index +1; spot++)
//	{
//		if(spot == index-1)
//		{
//			previousSpot = current;
//		}
//		if(spot == index)
//		{
//			storedValue = current->getValue();
//			newNext = current->getNext();
//			delete current;
//		}
//
//		current = current->getNext();
//	}
//
//	previousSpot->setNext(newNext);
//	return storedValue;
//
//
//}
//
//template<class Type>
//void CTECList<Type>::calculateSize()
//{
//	assert(size >= 0);
//
//	int count = 0;
//	if(head == nullptr)
//	{
//		size = 0;
//	}
//	else
//	{
//		count++;
//		ArrayNode<Type> * current = head;
//		while(current->getNext() != nullptr)
//		{
//			count++;
//			current = current->getNext();
//		}
//		size = count;
//	}
//
//
//}
//
//template <class Type>
//int CTECList<Type> :: indexOf(Type searchValue)
//{
//    assert(this->size > 0);
//    
//    int index = 0;
//    
//    ArrayNode<Type> * searchPointer;
//    
//    for(searchPointer = head; searchPointer != nullptr; searchPointer = searchPointer ->getNext())
//    {
//        if(searchValue == searchPointer->getValue())
//        {
//            return index;
//        }
//    }
//    
//    index = -1;
//    return index;
//}
//
//template<class Type>
//void CTECList<Type>::swap(int indexOne, int indexTwo)
//{
//    assert(indexOne < size && indexTwo < size);
//    Type temp = getFromIndex(indexOne);
//    set(indexOne, getFromIndex(indexTwo));
//    set(indexTwo, temp);
//}
//
//template<class Type>
//void CTECList<Type> :: selectionSort()
//{
//    for(int outerLoop = 0; outerLoop < size-1; outerLoop++)
//    {
//        int selectedMinimum = outerLoop;
//        
//        for(int innerLoop = outerLoop+1; innerLoop < size; innerLoop++)
//        {
//         
//            if(getFromIndex(innerLoop) < getFromIndex(selectedMinimum))
//            {
//                selectedMinimum = innerLoop;
//            }
//        }
//        
//        if(selectedMinimum != outerLoop)
//        {
//            swap(selectedMinimum, outerLoop);
//        }
//    }
//}


