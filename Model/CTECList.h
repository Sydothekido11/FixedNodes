/*
 * CTECList.h
 *
 *  Created on: Feb 22, 2016
 *      Author: snem8901
 */

#ifndef MODEL_CTECLIST_H_
#define MODEL_CTECLIST_H_

#include "ArrayNode.h"
template <class Type>
class CTECList
{
private:
	int size;
	ArrayNode<Type> * head;
	ArrayNode<Type> * end;
    void swap(int indexOne, int indexTwo);
	void calculateSize();
public:
	CTECList();
	virtual ~CTECList();
    int getSize();
	void addAtIndex(int index, const Type& value);
	void addToFront(const Type& value);
	void addToEnd(const Type& value);
	Type removeFromPosition(int index);
	Type removeFromFront();
	Type removeFromBack();
	Type removeFromIndex(int index);
	Type getEnd();
	Type getFront();
	Type getFromIndex(int index);
	Type set(int index, const Type& value);
    int indexOf(Type searchValue);
    void selectionSort();
};



#endif /* MODEL_CTECLIST_H_ */
