
#include <vector>
#include <iostream>
#include <list>
#include <stack>

using namespace std;

/*struct Node;

typedef struct Node Node;

struct Node{
	Node * parent;
	Node * sibling;
	Node * son;
	int Volume;
	int VolumeLeft;
	bool visited;
};*/

struct Node{
	struct Node * parent;
	struct Node * sibling;
	struct Node * son;
	int Volume;
	int VolumeLeft;
	bool visited;
};

typedef struct Node Node;

int combinationSum4(vector<int>& nums, int target) {
	int count = 0;
	//生成根节点
	Node * root = new Node;
	root->parent = root->sibling = NULL;
	root->Volume = -1;
	root->VolumeLeft = target;

	//广度优先，使用队列缓存
	list<Node*> l;
	//保存所有节点地址，便于回收内存
	vector<Node*> vn;

	//将根节点放入缓存队列
	l.push_back(root);
	vn.push_back(root);

	root = l.front();

	//构造搜索树
	while(!l.empty())
	{
		//auto curr = l.front();
		//l.front();
		//取队列首元素
		Node* curr = l.front();
		l.pop_front();
		list<Node*> son;

		//生成子节点
		for(auto i = nums.begin(); i != nums.end(); ++i)
		{
			Node * n;
			if(*i <= curr->VolumeLeft)
			{
				n = new Node;
				vn.push_back(n);
				n->Volume = *i;
				n->VolumeLeft = curr->VolumeLeft - *i;
				n->parent = curr;
				n->son = NULL;
				n->sibling = NULL;
				n->visited = false;
				son.push_back(n);
			}
		}


		//连接兄弟节点
		Node * last = NULL;
		for(auto i = son.begin(); i != son.end(); ++i)
		{
			if(!last)
			{
				curr->son = *i;
				last = *i;
			}
			else
			{
				last->sibling = *i;
				last = *i;
			}
		}

		//添加新的遍历节点
		while(!son.empty())
		{
			last = son.front();
			son.pop_front();
			l.push_back(last);
		}
	}

	//深度优先遍历搜索树
	stack<Node*> s;
	s.push(root);

	Node * curr = s.top();
	while(!s.empty())
	{
		curr = s.top();
		if(!curr->visited)
		{
			//如果当前节点未被访问（弹出）过，且当前节点有子节点，则将子节点入栈，当前遍历节点改为栈首元素
			if(curr->son)
			{
				curr = curr->son;
				//curr->visited = true;
				if(!curr->visited)
					s.push(curr);
			}
			//如果当前节点没有子节点，则栈中所有元素，即一个组合方案
			//还要判断剩余量是否为0
			else
			{
				if(curr->VolumeLeft == 0){
					stack<Node*> tmp;
					Node * t;
					while(s.top() != root)
					{
						t = s.top();
						tmp.push(t);
						s.pop();
					}
					cout << "[";
					while(!tmp.empty())
					{
						t = tmp.top();
						cout << t->Volume << "," ;
						s.push(t);
						tmp.pop();
					}
					cout << " ]" << endl;

					count ++;
				}
				//t = s.top();
				//s.pop();
				curr->visited = true;
			}
		}
		else
		{
			s.pop();
			if(curr->sibling)
			{
				curr = curr->sibling;
				s.push(curr);
			}
			else if(curr->parent)
			{
				curr = s.top();
				curr->visited = true;
				//s.pop();
			}
		}
	}

	//回收内存
	for(auto i = vn.begin(); i != vn.end(); ++i)
	{
		delete *i;
		*i = NULL;
	}

	return count;
}

//这种方法会超时
int combinationSum4_2(vector<int>& nums, int target)
{
	if(target == 0)
		return 1;
	if(target < 0)
		return 0;

	int res = 0;
	for(auto n : nums)
	{
		//if(n <= target)
		res += combinationSum4_2(nums, target - n);
	}

	return res;
}

int combinationSum4_2p(vector<int>& nums, int target, list<int>& sol)
{
	if(target == 0)
	{
		cout << "[" ;
		for(auto i : sol)
			cout << i << ",";
		cout << "]" << endl;
		return 1;
	}
	if(target < 0)
		return 0;

	int res = 0;
	for(auto n : nums)
	{
		//if(n <= target)
		sol.push_back(n);
		res += combinationSum4_2p(nums, target - n, sol);
		sol.pop_back();
	}

	return res;
}

void CombinationTest()
{
	//vector<int> vi{1, 2, 3};
	//vector<int> vi{3, 1, 2, 4};
	//int target = 4;
	vector<int> vi {3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};

	int target = 10;
	int count;
	list<int> sol;

	count = combinationSum4_2p(vi, target, sol);

	cout << count << endl;
}


