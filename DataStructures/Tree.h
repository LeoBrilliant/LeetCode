/*
 * Tree.h
 *
 *  Created on: 2016年11月14日
 *      Author: user
 */

#ifndef TREE_H_
#define TREE_H_

#include "BasicHeaders.h"

struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

TreeNode * GenBinaryTreeFromMap(map<int, int> & nodes);

void InOrderTraversal(TreeNode * root);
void PreOrderTraversal(TreeNode * root);
void PostOrderTraversal(TreeNode * root);
void BreadthTraversal(TreeNode * root);
#endif /* TREE_H_ */
