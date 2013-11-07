#pragma once

#include <cstdio>
#include <cmath>

class Node
{
public:
	Node(int value)
	{
		this->value = value;
		left = 0;
		right = 0;
	}
	Node* left;
	Node* right;
	int value;

};

int findNearestValue(Node* n, double value, Node* nearest)
{
	if(n == 0)
	{
		if(nearest != 0)
			return nearest->value;
		else
			return -1;
	}
	
	if(nearest == 0)
	{
		nearest = n;
	}
	else
	{
		double diff = abs(value - n->value);
		double currDiff = abs(value - nearest->value);
		if(diff < currDiff)
			nearest = n;
	}

	if(n->value == value)
		return n->value;
	else if(n->value > value)
		findNearestValue(n->left, value, nearest);
	else
		findNearestValue(n->right, value, nearest);
}


void main()
{
	Node* a = new Node(10);
	Node* b = new Node(5);
	Node* c = new Node(8);
	Node* d = new Node(1);
	Node* e = new Node(15);
	Node* f = new Node(12);

	a->left = b; a->right = e;
	b->left = d; b->right = c;
	e->left = f;

	int res = findNearestValue(a, 10, 0);


	delete a,b,c,d,e,f;
	int aff = 5;
}