/*
 * BinaryTreeInorderTraversal.cpp
 *
 *  Created on: 2016年11月14日
 *      Author: user
 */

#include "P51~100.h"

struct TravelHelper{
	TreeNode * node;
	int mode; // 0 - leaf, 1 - RightChild, 2 - LeftChild, 3 - Both Child
	bool visited;
	TravelHelper() : node(NULL), mode(0), visited(0){}
	TravelHelper(TreeNode * node, int mode, bool visited) : node(node), mode(mode), visited(visited) {}
};

enum NextMove{
	Waiting, TravelsalLeft, TravelsalRoot, TravelsalRight, TravelsalUpperRoot
};

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> ret;

	if(!root)
		return ret;

	deque<TravelHelper*> buffer;
	TreeNode * curr = NULL;
	TravelHelper * tmp;
	NextMove inst;
	tmp = new TravelHelper(root, 0, false);
	if(root->left) tmp->mode |= 2;
	if(root->right) tmp->mode |= 1;
	//tmp->visited = false;
	buffer.push_back(tmp);


	inst = Waiting;
	while(!buffer.empty())
	{
		switch(inst)
		{
		case Waiting:
			tmp = buffer.front();
			break;
		case TravelsalLeft:
			tmp = buffer.front();
			break;
		case TravelsalRight:
			tmp = buffer.back();
			break;
		case TravelsalRoot:
			tmp = buffer.front();
			break;
		case TravelsalUpperRoot:
			tmp = buffer.front();
			break;
		}

		curr = tmp->node;

		if(!tmp->visited) {
			if(curr->left && curr->right){
				tmp->mode |= 3;
				TravelHelper * left = new TravelHelper(curr->left, 0, false);
				buffer.push_front(left);
				TravelHelper * right = new TravelHelper(curr->right, 0, false);
				buffer.push_back(right);
				tmp->visited = true;
				inst = TravelsalLeft;
			}
			else if(curr->left && !curr->right){
				tmp->mode |= 2;
				TravelHelper * left = new TravelHelper(curr->left, 0, false);
				buffer.push_back(left);
				tmp->visited = true;
				inst = TravelsalLeft;
			}
			else if(!curr->left && curr->right){
				tmp->mode |= 1;
				TravelHelper * right = new TravelHelper(curr->right, 0, false);
				buffer.push_back(right);
				inst = TravelsalRight;
				ret.push_back(curr->val);
				buffer.pop_front();
			}
			else if(curr->left == NULL || curr->right == NULL)
			{
				ret.push_back(curr->val);
				buffer.pop_front();
				inst = TravelsalUpperRoot;
			}
		}
		else
		{
			ret.push_back(curr->val);

		}
	}

	return ret;
}


void BinaryTreeTest()
{
	TreeNode * root = NULL;
	map<int, int> nodes;

	cout << "test case 1" << endl;
	InOrderTraversal(root);
	PreOrderTraversal(root);
	PostOrderTraversal(root);
	BreadthTraversal(root);

	cout << "test case 2" << endl;
	nodes = {};
	root = GenBinaryTreeFromMap(nodes);
	assert(root == NULL);
	InOrderTraversal(root);
	PreOrderTraversal(root);
	PostOrderTraversal(root);
	BreadthTraversal(root);

	cout << "test case 3" << endl;
	nodes = {{5, 5}, {1, 1}, {3, 3}, {4, 4}, {2, 2}, {6, 6}, {7, 7}};
	root = GenBinaryTreeFromMap(nodes);
	assert(root != NULL);
	InOrderTraversal(root);
	PreOrderTraversal(root);
	PostOrderTraversal(root);
	BreadthTraversal(root);

	cout << "test case 4" << endl;
	nodes = {{1, 1}};
	root = GenBinaryTreeFromMap(nodes);
	assert(root != NULL);
	InOrderTraversal(root);
	PreOrderTraversal(root);
	PostOrderTraversal(root);
	BreadthTraversal(root);

	cout << "test case 5" << endl;
	nodes = {{1, 1}, {2, 2}, {4, 4}, {8, 8}, {16, 16}};
	root = GenBinaryTreeFromMap(nodes);
	assert(root != NULL);
	InOrderTraversal(root);
	PreOrderTraversal(root);
	PostOrderTraversal(root);
	BreadthTraversal(root);

	cout << "test case 6" << endl;
	nodes = {{1, 1}, {3, 3}, {7, 7}, {15, 15}, {31, 31}};
	root = GenBinaryTreeFromMap(nodes);
	assert(root != NULL);
	InOrderTraversal(root);
	PreOrderTraversal(root);
	PostOrderTraversal(root);
	BreadthTraversal(root);
}
