//
//  CTECBinaryTree.cpp
//  NodeStuff
//
//  Created by Nemelka, Sydney on 4/11/16.
//  Copyright © 2016 Nemelka, Sydney. All rights reserved.
//

#include "CTECBinaryTree.hpp"
#include <iostream>
using namespace std;

template<class Type>
CTECBinaryTree<Type> :: CTECBinaryTree()
{
    this->root = nullptr;
    this->size = 0;
    this->height = 0;
    this->balanced = true;
}

template<class Type>
int CTECBinaryTree<Type>::getSize()
{
    size = 0;
    size = calculatedSize(root);
    return size;
}

template<class Type>
void CTECBinaryTree<Type>::calculateSize(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        calculateSize(currentNode->getLeftChild);
        calculateSize(currentNode->getRightChild);
        size++;
    }
}

template<class Type>
TreeNode<Type> * CTECBinaryTree<Type>::getRoot()
{
    return root;
}

template<class Type>
void CTECBinaryTree<Type>::preorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        cout << currentNode->getValue() << "";
        preorderTraversal(currentNode->getLeftChild());
        preorderTraversal(currentNode->getRightChild());
    }
}

template<class Type>
void CTECBinaryTree<Type>::inorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        inorderTraversal(currentNode->getLeftChild());
        cout << currentNode->getValue() << "";
        inorderTraversal(currentNode->getRightChild());
        
    }
}

template<class Type>
void CTECBinaryTree<Type>::postorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        postorderTraversal(currentNode->getLeftChild());
        postorderTraversal(currentNode->getRightChild());
        cout << currentNode->getValue() << "";
        
    }
}


template<class Type>
bool CTECBinaryTree<Type>::contains(Type value)
{
    bool isInTree = false;
    
    if(root != nullptr)
    {
        if(root->getValu() == value)
        {
            isInTree = true;

        }
        else
        {
            if(value < root->getValue())
            {
                isInTree = contains(value, root->geLeftChild());
            }
            else
            {
                isInTree = contains(value, root->etRightChild);
            }
        }
    }
    return isInTree;
}




template<class Type>
bool CTECBinaryTree<Type> :: insert(const Type& value)
{
    if(contains(value))
    {
        return false;
    }
    else
    {
    
        TreeNode<Type> * currentNode = root;
        TreeNode<Type> * trailNode;
        
        if(root == nullptr)
        {
            root = new TreeNode<Type>(value);
        }
        else
        {
            while(currentNode != nullptr)
            {
                trailNode = currentNode;
                
                if(currentNode->getValue() < value)
                   {
                       currentNode = currentNode->getRightChild();
                   }
                else
                   {
                       currentNode = currentNode->getLeftChild();
                   }
            }
            if(trailNode->getValue() > value)
            {
                TreeNode<Type> * insertedNode = new TreeNode<Type>(value, trailNode);
                trailNode->setLeftChild(insertedNode);
            }
            else
            {
                TreeNode<Type> * insertedNode = new TreeNode<Type>(value, trailNode);
                trailNode->setRightChild(insertedNode);
            }
        }
    }
    return true;
}

template<class Type>
TreeNode<Type> * CTECBinaryTree<Type> :: getRightMostChild(CTECBinaryTree<Type> leftSubTree)
{
    TreeNode<Type> * rightNode = leftSubTree->getRoot();
    while(rightNode->getLeftChild() != nullptr)
    {
        rightNode = rightNode->getRightChild();
    }
    
    return rightNode;
}

template<class Type>
TreeNode<Type> * CTECBinaryTree<Type> :: getLeftMostChild(CTECBinaryTree<Type> rightSubTree)
{
    TreeNode<Type> * leftNode = rightSubTree->getRoot();
    while(leftNode->getRightChild() != nullptr)
    {
        leftNode = leftNode->getLeftChild();
    }
    
    return leftNode;
}



template <class Type>
void CTECBinaryTree<Type> :: remove(TreeNode<Type> * nodeToBeRemoved)
{
    TreeNode<Type> * current;
    TreeNode<Type> * trailing;
    TreeNode<Type> * temp;
    
    if(nodeToBeRemoved == nullptr)
    {
        
    }
    else if (nodeToBeRemoved->getLeftChild() == nullptr && nodeToBeRemoved->getRightChild() == nullptr)
    {
        temp = nodeToBeRemoved;
        nodeToBeRemoved = nullptr;
        delete temp;
    }
    else if (nodeToBeRemoved->getLeftChild() == nullptr)
    {
        temp = nodeToBeRemoved;
        nodeToBeRemoved = temp->getRightChild();
        delete temp;
    }
    else if (nodeToBeRemoved->getRightChild() == nullptr)
    {
        temp = nodeToBeRemoved;
        nodeToBeRemoved = temp->getLeftChild();
        delete temp;
    }
    else
    {
        current = nodeToBeRemoved->getLeftChild();
        trailing = nullptr;
        
        while(current->getRightChild() != nullptr)
        {
            trailing = current;
            current = current->getRightChild();
        }
        
        nodeToBeRemoved->setValue(current->getValue());
        
        if(trailing == nullptr)
        {
            nodeToBeRemoved->setLeftChild(current->getLeftChild());
        }
        else
        {
            trailing->setRightChild(current->getLeftChild());
        }
        
        delete current;
    }

    
    
}





