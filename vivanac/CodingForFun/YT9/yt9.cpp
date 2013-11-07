#pragma once

#include <cstdio>
#include <queue>

using namespace std;

class Node
{
public:
	Node(int value)
	{
		this->value = value;
		left = 0;
		right = 0;
	}
	int value;
	Node* left;
	Node* right;
};

void PrintAtLevel(Node* node, int level)
{
	if(node == 0) return;

	if(level == 0)
	{
		printf(" %d", node->value);
		return;
	}

	PrintAtLevel(node->left, level-1);
	PrintAtLevel(node->right, level-1);
}

void PrintAtLevelWithQueue(Node* node, int level)
{
	queue<Node*> ns;
	queue<int> ls;
	ls.push(0);
	ns.push(node);

	while(!ns.empty())
	{
		Node* n = ns.front(); 
		int l = ls.front();
		
		if(l == level)
			break;

		ls.pop(); ns.pop();

		if(n->left != NULL)
		{	
			ls.push(l+1);
			ns.push(n->left);
		}
		if(n->right != NULL)
		{	
			ls.push(l+1);
			ns.push(n->right);
		}
	
	}

	//print all in queue ns
	while(!ns.empty())
	{
		printf(" %d", ns.front()->value);
		ns.pop();
	}
}

int main()
{
	Node* a = new Node(13);
	Node* b = new Node(8);
	Node* c = new Node(17);
	Node* d = new Node(1);
	Node* e = new Node(9);
	Node* f = new Node(20);
	Node* g = new Node(18);
	
	a->left = b; a->right = c;
	b->left = d; b->right = e;
	c->right = f;
	f->left = g;
	

	PrintAtLevel(a, 2); 
	printf("\n");
	PrintAtLevelWithQueue(a,2);

	return 1;
}