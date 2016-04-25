//
//  CTECBinaryTree.hpp
//  NodeStuff
//
//  Created by Nemelka, Sydney on 4/11/16.
//  Copyright © 2016 Nemelka, Sydney. All rights reserved.
//

#ifndef CTECBinaryTree_hpp
#define CTECBinaryTree_hpp

#include "TreeNode.cpp"
namespace CTECData
{
template <class Type>
class CTECBinaryTree
{
private:
    int size;
    TreeNode<Type> * root;
    int height;
    bool balanced;
    bool contains(Type value, CTECBinaryTree<Type> * currentTree);
    void calculateSize(TreeNode<Type> * currentNode);
    TreeNode<Type>  * getRightMostChild(CTECBinaryTree<Type> leftSubTree);
    TreeNode<Type>  * getLeftMostChild(CTECBinaryTree<Type> rightSubTree);
    void remove(TreeNode<Type> * nodeToBeDeleted);
public:
    CTECBinaryTree();
    ~CTECBinaryTree();
    bool insert(const Type& value);
    void remove(const Type& value);
    bool contains(Type value);
    int getSize();
    int getHeight();
    bool isBalanced();
    TreeNode<Type> * getRoot();
    void preorderTraversal(TreeNode<Type> * currentNode);
    void inorderTraversal(TreeNode<Type> * currentNode);
    void postorderTraversal(TreeNode<Type> * currentNode);
        
    };
}

#endif /* CTECBinaryTree_hpp */
