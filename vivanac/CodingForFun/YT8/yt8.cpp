#pragma once

#include <cstdio>

struct Node
{
	int value;
	Node* left;
	Node* right;
};

Node* root = 0;

int Add(Node* parent, int value)
{
	if(root == 0)
	{
		root = new Node();
		root->value = value;
		return 1;
	}

	if(parent->value > value)
	{
		if(parent->left == 0)
		{
			parent->left = new Node();
			parent->left->value = value;
			return 1;
		}
		else
		{
			Add(parent->left, value);
		}
	}
	else if(parent->value < value)
	{
		if(parent->right == 0)
		{
			parent->right = new Node();
			parent->right->value = value;
			return 1;
		}
		else
		{
			Add(parent->right, value);
		}
	}
	else
		return -1;

	return -1;
}

int Validate(Node* node)
{
	if(node == 0)
		return 1;

	if(node->left != 0 && node->left->value >= node->value)
		return -1;
	if(node->right != 0 && node->right->value <= node->value)
		return -1;

	int left = Validate(node->left);
	int right = Validate(node->right);

	int result = left+ right;
	if(result != 2)
		return -1;

	return 1;

}

int Validate2(Node* node, int min, int max)
{
	if(node == 0)
		return 1;

	if(node->value < min || node->value > max)
		return -1;

	int res = 0;
	res += Validate2(node->left, min, node->value-1);
	res += Validate2(node->right, node->value+1, max);

	if(res != 2)
		return -1;

	return 1;
}

int lastValue = 0x80000000;
bool Validate4(Node* node)
{
	if(node == NULL) 
		return true;
	if(!Validate4(node->left))
		return false;
	if(node->value <= lastValue)
		return false;
	lastValue = node->value;
	return Validate4(node->right);
}

int main()
{
	Add(root, 13);  Add(root, 8); Add(root, 17); Add(root, 1); Add(root, 9); Add(root, 20); Add(root, 18);  

	root->left->right->value = 14;
	
	int res = Validate(root);

	int res2 = Validate2(root, 0x80000000, 0xFFFFFFFF);

	Node* a = new Node; a->value = 13;
	Node* b = new Node; b->value = 8;
	Node* c = new Node; c->value = 17;
	Node* d = new Node; d->value = 1;
	Node* e = new Node; e->value = 9;
	Node* f = new Node; f->value = 20;
	Node* g = new Node; g->value = 5;
	
	a->left = b; a->right = c;
	b->left = d; b->right = e;
	c->right = f; c->left = 0;
	d->left = 0; d->right = 0;
	e->left = 0; e->right = 0;
	f->left = g; f->right = 0;
	g->left = 0; g->right = 0;

	bool res4 = Validate4(a);

	int vv = 5;
}
