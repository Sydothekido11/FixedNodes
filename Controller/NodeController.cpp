/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: snem8901
 */

#include "NodeController.h"
#include "../Model/Timer.h"
#include <stdlib.h> //Allows access to rand() function for random #'s and gives a random #.



NodeController::NodeController()
{
	notHipsterInts = new CTECArray<int>(5);
	numbers = new CTECList<int>();

}

NodeController::~NodeController()
{

}

void NodeController :: testList()
{
    numbers->addToFront(3);
	numbers->addToEnd(8);
    numbers->addAtIndex(1,188);

	cout << "End should be 8 and is: " << numbers->getEnd() << endl;
    cout << "Front should be 3 and is: " << numbers->getFront() << endl;
    cout << "The middle should be 188 and is" << numbers->getFromIndex(2);
    
    numbers->addToEnd(19);
    numbers->addToEnd(20);
    
    numbers->removeFromEnd();
    cout << "the end should be 19 and is " << numbers->getEnd() << endl;
    numbers->removeFromIndex(2);
    cout << "the index 1 should be 188 and is " << numbers->getFromIndex(1) << endl;
    numbers->removeFromFront();
    cout << "the beginning should be 188 and is " << numbers->getFront() << endl;
    
    cout << "the size of the list should be 2 and is " << numbers->getSize();
    cout << "the index of 19 should be 1 and is " << numbers->indexOf(2);
    
}
void NodeController :: start()
{
    doMergesort();
    
//	arrayTimer.startTimer();
//	for(int index = 0; index < notHipsterInts->getSize(); index++)
//	{
//		notHipsterInts->set(index, (23 * index));
//	}
//
//	for(int index = notHipsterInts -> getSize() - 1; index >=0; index--)
//	{
//		cout << "notHipsterInts at index " << index << " contains " << notHipsterInts->get(index) << endl;
//	}
//
//	arrayTimer.stopTimer();
//	arrayTimer.displayTimerInformation();

}

void NodeController :: sortData()
{
 
    /*
     Creat a CTECList, CTECArray
     Fill them with random stuff(random)
     Start a timer, sort, stop timer, display info for a List.
     Start a timer, sort, stop timer, display info for Array.
     */
    CTECArray<int> randomNumberArray(5000);
    CTECList<int> randomNumberList;
    int myCPlusPlusArray[5000];
    
    for(int spot = 0; spot < 5000; spot++)
    {
        int myRandom = rand();
        randomNumberArray.set(spot, myRandom);
        randomNumberList.addToEnd(myRandom);
        myCPlusPlusArray[spot] = myRandom;
        
    }
    
    Timer sortTimer;
    sortTimer.startTimer();
    randomNumberArray.selectionSort();
    sortTimer.stopTimer();
    sortTimer.displayTimerInfo();
    
    sortTimer.resetTimer();
    
    sortTimer.startTimer();
    std::sort(std::begin(myCPlusPlusArray), std::end(myCPlusPlusArray));
    sortTimer.stopTimer();
    sortTimer.displayTimerInfo();
    
    sortTimer.resetTimer();
    
}

void NodeController::doMergesort()
{
    mergeData = new int[500000];
    
    for(int spot = 0; spot < 500000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
        
    }
    for(int spot = 0; spot < 5000; spot++)
    {
        cout << mergeData[spot] << ", ";
    }
    Timer mergeTimer;
    mergeTimer.startTimer();
    mergesort(mergeData,500000);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInfo();
    
    for(int spot = 0; spot < 500000; spot++)
    {
        cout << mergeData[spot] << ", ";
    }
    delete [] mergeData;
}

void NodeController::mergesort(int data[], int size)
{
    int sizeOne;
    int sizeTwo;
    
    if(size > 1)
    {
        sizeOne = size/2;
        sizeTwo = size-sizeOne;
        
        mergesort(data, sizeOne);
        mergesort((data+sizeOne), sizeTwo);
        
        merge(data, sizeOne, sizeTwo);
    }
}

void NodeController::merge(int data[], int sizeOne, int sizeTwo)
{
    int * temp;
    int copied = 0;
    int copied1 = 0;
    int copied2 = 0;
    int index;
    
    temp = new int [sizeOne + sizeTwo];
    
    while((copied1 < sizeOne) && (copied < sizeTwo))
    {
        if(data[copied1] < (data + sizeOne)[copied2])
        {
            temp[copied++] = data[copied1++];
        }
        else
        {
            temp[copied++] = (data + sizeOne)[copied2++];
        }
    }
    
    while(copied < sizeOne)
    {
        temp[copied++] = data[copied1++];
    }
    while(copied2 < sizeTwo)
    {
        temp[copied++] = (data+ sizeOne)[copied2++];
    }
    
    for(index = 0; index < sizeOne + sizeTwo; index++)
    {
        data[index] = temp[index];
    }
    delete [] temp;
}

void NodeController::quicksort(int first, int last)
{
    int pivotIndex;
    
    if(first < last)
    {
        pivotIndex = partition(first, last);
        quicksort(first, pivotIndex-1);
        quicksort(pivotIndex+1, last);
    }
}

int NodeController::partition(int first, int last)
{
    int pivot;
    
    int index, smallIndex;
    swap(first, (first + last)/2);
    
    pivot = mergeData[first];
    smallIndex = first;
    
    for(index = first + 1; index <= last; index++)
    {
        if(mergeData[index] < pivot)
        {
            smallIndex++;
            swap(smallIndex, index);
        }
    }
    swap(first, smallIndex);
    return smallIndex;
}
    
void NodeController::swap(int first, int last)
{
    int temp = mergeData[first];
    mergeData[first] = mergeData[last];
    mergeData[last] = temp;
}

void NodeController::doQuick()
{
    mergeData = new int[1000000000];
    
    for(int spot = 0; spot < 1000000000; spot++)
    {
        int myandom = rand();
        mergeData[spot] = myandom;
    }
    Timer mergeTimer;
    mergeTimer.startTimer();
    quicksort(0, 1000000000-1);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInfo();
    
    delete [] mergeData;
}











