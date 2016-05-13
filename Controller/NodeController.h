/*
 * NodeController.h
 *
 *  Created on: Jan 27, 2016
 *      Author: snem8901
 */

#ifndef CONTROLLER_NODECONTROLLER_H_
#define CONTROLLER_NODECONTROLLER_H_

#include "../Model/Node.h"
#include "../Model/Node.cpp"
#include "../Model/ArrayNode.cpp"
#include "../Model/Timer.h"
#include <string>
#include <iostream>
#include "../Model/CTECArray.cpp"
#include "../Model/CTECList.cpp"
#include"../Model/CTECGraph.cpp"
#include "../Model/CTECBinaryTree.cpp"

using namespace std;

class NodeController
{
private:
	CTECArray<int> * notHipsterInts;
	CTECList<int> * numbers;
	Timer arrayTimer;
    void sortData();
    void testList();
    void searchTest();
    
    void swap(int first, int second);
    void quicksort(int first, int last);
    int partition(int first, int last);
    void doQuick();
    
    int * mergeData;
    void doMergesort();
    void mergesort(int data [], int size);
    void merge(int data [], int sizeOne, int sizeTwo);
    
    void tryGraphs();
    
    void tryTree();
    
    void testHashTable();
    
    
public:
	NodeController();
	virtual ~NodeController();
	void start();
    
};



#endif /* CONTROLLER_NODECONTROLLER_H_ */
