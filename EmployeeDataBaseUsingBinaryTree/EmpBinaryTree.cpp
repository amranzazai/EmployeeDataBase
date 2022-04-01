/*
 * EmpBinaryTree.cpp
 *
 *  Created on: Apr 14, 2021
 *      Author: amranzazai
 */

#include <iostream>
#include "EmpBinaryTree.h"
#include "Employee.h"
using namespace std;

void EmpBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode){
	if(nodePtr == nullptr)
		nodePtr = newNode;
	else if (newNode->e.getName() <= nodePtr->e.getName())
		insert(nodePtr->left, newNode);
	else
		insert(nodePtr->right, newNode);
}
void EmpBinaryTree::insertEmployee(Employee x){
	TreeNode *newNode = nullptr;
	newNode = new TreeNode;
	newNode->e = x;
	newNode->left = newNode->right = nullptr;
	insert(root, newNode);
}
bool EmpBinaryTree::searchEmployee(Employee x){
	TreeNode *nodePtr = root;
	while(nodePtr)
	{
		if(nodePtr->e.getName() == x.getName())
			return true;
		else if (x.getName() < nodePtr->e.getName())
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}
Employee EmpBinaryTree::getEmployee(string y)
{
	TreeNode *nodePtr = root;
	while(nodePtr)
	{
		if(nodePtr->e.getName() == y){
			cout<< nodePtr->e.getName() << " was found.\n";
			return nodePtr->e;
		}
		else if(y < nodePtr->e.getName()){
			nodePtr = nodePtr->left;
			cout<< nodePtr->e.getName() << " was found.\n";
		}
		else if(y > nodePtr->e.getName()){
			nodePtr = nodePtr->right;
			cout<< nodePtr->e.getName() << " was found.\n";
		}
		else{
			cout<< y <<" was not found.";
		}

	}
}
void EmpBinaryTree::remove(Employee x){
	deleteNode(x, root);
}
void EmpBinaryTree::deleteNode(Employee x, TreeNode *&nodePtr)
{
	if(x.getName() < nodePtr->e.getName())
		deleteNode(x, nodePtr->left);
	else if(x.getName() > nodePtr->e.getName())
		deleteNode(x, nodePtr->right);
	else
		makeDeletion(nodePtr);
}
void EmpBinaryTree::makeDeletion(TreeNode *&nodePtr)
{
	TreeNode *tempNodePtr = nullptr;
	if(nodePtr == nullptr)
		cout<<"Cannot delete an empty node.\n";
	else if(nodePtr->left == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
	else
	{
		tempNodePtr = nodePtr->right;
		while(tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		nodePtr=nodePtr->right;
		delete tempNodePtr;
	}
}
void EmpBinaryTree::destroySubTree(TreeNode *nodePtr)
{
	if(nodePtr)
	{
		if(nodePtr->left)
			destroySubTree(nodePtr->left);
		if(nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}
void EmpBinaryTree::displayInOrder(TreeNode *nodePtr) const
{
	if(nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout<< nodePtr->e.getName() <<endl;
		displayInOrder(nodePtr->right);

	}
}
void EmpBinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
	if(nodePtr)
	{
		cout<<nodePtr->e.getName() <<endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}
void EmpBinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
	if(nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout<< nodePtr->e.getName() <<endl;
	}
}





