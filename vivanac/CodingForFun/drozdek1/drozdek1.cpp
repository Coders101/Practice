#pragma once

#include <cstdio>
#include <vector>
#include <memory>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

void printVector(vector<int>* v)
{
	for(vector<int>::iterator it = v->begin(); it<v->end(); it++)
	{
		printf("%d\n",*it);
	}
	printf("-------------------\n");

}

class SListItem
{
public:
	SListItem(int value)
	{
		this->value = value;
		this->next = 0;
	}
	SListItem(int value, SListItem* next)
	{
		this->value = value;
		this->next = next;
	}

	SListItem* next;
	int value;

};
class SList
{
public:
	SList()
	{
		head = 0;
		tail = 0;
	}
	void AddToHead(int value)
	{
		SListItem* newItem = new SListItem(value);

		if(head == 0)
		{
			head = newItem;
			tail = newItem;
		}
		else
		{
			newItem->next = head;
			head = newItem;
		}
	}
	void AddToTail(int value)
	{
		SListItem* newItem = new SListItem(value);

		if(tail == 0)
		{
			head = newItem;
			tail = newItem;
		}
		else
		{
			tail->next = newItem;
			tail = newItem;
		}		
	}
	void DeleteFromHead()
	{
		if(head == 0)
			return;
		else if(head == tail)
		{
			delete head;
			head = 0;
			tail = 0;
		}
		else
		{
			SListItem* tmp = head;
			head = tmp->next;
			delete tmp;
			tmp = 0;
		}
	}
	void DeleteFromTail()
	{
		if(tail == 0)
			return;
		else if(head == tail)
		{
			delete head;
			head = 0;
			tail = 0;
		}
		else
		{
			SListItem* prev = 0;
			SListItem* curr = head;
			while(curr != tail)
			{
				prev = curr;
				curr = prev->next;
			}

			SListItem* tmp = tail;
			tail = prev;
			tail->next = 0;
			delete tmp;
		}

	}
	void DeleteNodes(int value)
	{
		if(head == 0)
			return;

		SListItem* prev = 0;
		SListItem* curr = head;

		while(true)
		{
			while(curr != 0 && curr->value != value)
			{
				prev = curr;
				curr = prev->next;
			}

			if(curr == 0)
				return;

			if(prev == 0)
			{
				DeleteFromHead();
				curr = head;
			}
			else if(curr->next == 0)
			{
				prev->next = 0;
				tail = prev;
				delete curr;
				curr = 0;
			}
			else
			{
				prev->next = curr->next;
				delete curr;
				curr = prev->next;
			}
		}
	}
	bool IsInList(int value)
	{
		if(head == 0)
			return false;

		SListItem* curr = head;
		while(curr != 0)
		{
			if(curr->value == value)
			{
				return true;
			}
			curr = curr->next;
		}
		return false;
	}


private:
	SListItem* head;
	SListItem* tail;

};
class CList
{
public:
	CList()
	{
		tail = 0;
	}
	void AddToFront(int value)
	{
		if(tail == 0)
		{
			SListItem* newItem = new SListItem(value);
			tail = newItem;
			tail->next = tail;
		}
		else
		{
			SListItem* newItem = new SListItem(value);
			newItem->next = tail->next;
			tail->next = newItem;
		}
	}
	void AddToBack(int value)
	{
		if(tail == 0)
		{
			SListItem* newItem = new SListItem(value);
			tail = newItem;
			tail->next = tail;
		}
		else
		{
			SListItem* newItem = new SListItem(value);
			newItem->next = tail->next;
			tail->next = newItem;
			tail = newItem;
		}
	}
private:
	SListItem* tail;
};
class SkipListItem
{
public:
	SkipListItem(int value, int level)
	{
		this->value = value;
		this->level = level;
		nexts = (SkipListItem**)malloc(sizeof(SkipListItem*)*level);
		for(int i = 0; i<level; i++)
			nexts[i] = 0;
	}
	~SkipListItem()
	{
		free(nexts);
	}
	int value;
	SkipListItem** nexts;
	int level;
};
class SkipList
{
public:
	SkipList(int maxLevel)
	{
		this->maxLevel = maxLevel;
		this->heads = (SkipListItem**)malloc(sizeof(SkipListItem*)*maxLevel);
		for(int i = 0; i<maxLevel; i++)
			heads[i] = 0;
	}
	void Insert(int value)
	{
		
	
	}
	SkipListItem* Search(int value)
	{
		
	}
	
private:

	int maxLevel;
	SkipListItem** heads;
};

#define SPARSE_TABLE_SIZE 100

class STableItem
{
public:
	STableItem(int value, int row, int column)
	{
		this->value = value;
		this->row = row;
		this->column = column;
		this->nextRow = 0;
		this->nextColumn = 0;
	}
	int value;
	int row;
	int column;
	STableItem* nextRow;
	STableItem* nextColumn;
};
class STable
{
public:
	STable()
	{
		memset(rows, 0, sizeof(STableItem*)*SPARSE_TABLE_SIZE);
		memset(columns, 0, sizeof(STableItem*)*SPARSE_TABLE_SIZE);
	}
	void Set(int value, int row, int column)
	{
		//find prev in row
		STableItem* currRow = rows[row];
		STableItem* prevRow = 0;
		while(true)
		{
			if(currRow == 0)
				break;
		
			if(currRow->column > column)
				break;

			if(currRow->row == row && currRow->column == column)
				break;

			prevRow = currRow;
			currRow = prevRow->nextRow;
		}

		//find prev in column
		STableItem* currColumn = columns[column];
		STableItem* prevColumn = 0;
		while(true)
		{
			if(currColumn == 0)
				break;
		
			if(currColumn->row > row)
				break;

			if(currColumn->column == column && currColumn->row == row)
				break;

			prevColumn = currColumn;
			currColumn = prevColumn->nextColumn;
		}

		if(currRow != 0 && currColumn != 0 && currRow->row == row && currColumn->column == column)
		{
			if(currRow == currColumn)
				currRow->value = value;
			else
			{
				int a44 = 5;
			}
		}
		else
		{
			STableItem* newItem = new STableItem(value, row, column);

			if(currRow == 0)
			{
					if(prevRow == 0)
					{
						rows[row] = newItem;
					}
					else
					{
						prevRow->nextRow = newItem;
					}
			}
			else if(currRow->column > column)
			{
				newItem->nextRow = currRow;
				prevRow->nextRow = newItem;
			}

			if(currColumn == 0)
			{
					if(prevColumn == 0)
					{
						columns[column] = newItem;
					}
					else
					{
						prevColumn->nextColumn = newItem;
					}
			}
			else if(currColumn->row > row)
			{
				newItem->nextColumn = currColumn;
				prevRow->nextColumn = newItem;
			}
		}	
	}
	void Remove(int row, int column)
	{
		STableItem* currRow = rows[row];
		STableItem* prevRow = 0;
		while(true)
		{
			if(currRow == 0)
				return;
		
			if(currRow->column > column)
				return;

			if(currRow->row == row && currRow->column == column)
				break;

			prevRow = currRow;
			currRow = prevRow->nextRow;
		}

		//find prev in column
		STableItem* currColumn = columns[column];
		STableItem* prevColumn = 0;
		while(true)
		{
			if(currColumn == 0)
				return;
		
			if(currColumn->row > row)
				return;

			if(currColumn->column == column && currColumn->row == row)
				break;

			prevColumn = currColumn;
			currColumn = prevColumn->nextColumn;
		}

		if(currRow != 0 && currColumn != 0 && currRow->row == row && currColumn->column == column)
		{
			if(prevRow == 0)
			{
				rows[row] = currRow->nextRow;
			}
			else
			{
				prevRow->nextRow = currRow->nextRow;
			}

			if(prevColumn == 0)
			{
				columns[column] = currColumn->nextColumn;
			}
			else
			{
				prevColumn->nextColumn = currColumn->nextColumn;
			}

			delete currRow;
		}		
	}
	int Find(int row, int column)
	{
		STableItem* currRow = rows[row];
		STableItem* prevRow = 0;
		while(true)
		{
			if(currRow == 0)
				return -1;
		
			if(currRow->column > column)
				return -1;

			if(currRow->row == row && currRow->column == column)
				return currRow->value;

			prevRow = currRow;
			currRow = prevRow->nextRow;
		}
		return -1;
	}
	~STable()
	{
		
	}
private:
	STableItem* rows[SPARSE_TABLE_SIZE];
	STableItem* columns[SPARSE_TABLE_SIZE];
};
class StackArray
{
public:
	StackArray(int size)
	{
		arr = new int[size];
		this->size = size;
		this->count = 0;
	}
	int Top()
	{
		if(count != 0)
			return arr[count-1];

		return -1;
	}
	void Push(int value)
	{
		if(count < size-1)
		{
			arr[count] = value;
			count++;
		}	
	}
	void Pop()
	{
		if(count!=0)
			count--;
	}
	~StackArray()
	{
		delete[] arr;
	}
private:
	int* arr;
	int size;
	int count;
};

int fac(int n)
{
	if(n == 1)
		return 1;

	return n*fac(n-1);
}

int getDiagL(int row, int column)
{
	return (column-row)+7;
}

int getDiagR(int row, int column)
{
	return column+row;
}

bool FindSolutionForEightQueens(int* queens, int* columns, int* diagLs, int* diagRs, int queensLeft)
{
	if(queensLeft == 0)
	{
		printf("\n Queens are in next positions:");
		for(int i = 0; i<8; i++)
		{
			printf("\n (%d,%d)", i, queens[i]);
		}
		return true;
	}

	for(int i= 0; i<8; i++)
	{
		int rowIndex = 8-queensLeft;
		int diagL_index = getDiagL(rowIndex, i);
		int diagR_index = getDiagR(rowIndex, i);

		if(columns[i] && diagLs[diagL_index] && diagRs[diagR_index])
		{
			columns[i] = 0; diagLs[diagL_index] = 0; diagRs[diagR_index] = 0;
			queens[rowIndex] = i;
			if(!FindSolutionForEightQueens(queens, columns, diagLs, diagRs, queensLeft-1))
			{
				columns[i] = 1; diagLs[diagL_index] = 1; diagRs[diagR_index] = 1;
				queens[rowIndex] = 0;
			}					
		}	
	}
	return false;

}

void BellmanFord()
{
	int numOfNodes = 5;
	int inf = 1000;

	vector<vector<int>> al(numOfNodes, vector<int>());
	vector<int> dist(numOfNodes, inf);
	vector<vector<int>> ew(numOfNodes, vector<int>(numOfNodes, 0));

	al[0].push_back(1); ew[0][1] = -1;
	al[0].push_back(2); ew[0][2] = 4;
	al[1].push_back(2); ew[1][2] = 3;
	al[1].push_back(3); ew[1][3] = 2;
	al[1].push_back(4); ew[1][4] = 2;
	al[3].push_back(1); ew[3][1] = 1;
	al[3].push_back(2); ew[3][2] = 5;
	al[4].push_back(3); ew[4][3] = -3;

	dist[0] = 0;

	for(int i = 0; i<numOfNodes;i++)
	{
		for(int j = 0; j<numOfNodes; j++)
		{
			for(int k = 0; k<al[j].size(); k++)
			{
				int cid = al[j][k];
				if(dist[cid] > dist[j] + ew[j][cid])
				{
					dist[cid] = dist[j] + ew[j][cid];
				}			
			}
		}
	}

	bool isInCycle = false;
	for(int i = 0; i<numOfNodes; i++)
		for(int j = 0; j<al[i].size();j++)
		{
			int cid = al[i][j];
			if(dist[cid] > dist[i] + ew[i][cid])
				isInCycle = true;
		}


	int a=6;

}


int main()
{
	BellmanFord();

	set<int>* st1 = new set<int>();
	st1->insert(5); st1->insert(3); st1->insert(8);
	
	map<int, int>* mp1 = new map<int, int>();
	mp1->insert(pair<int, int>(2,3));
	map<int, int>::iterator i = mp1->find(2);
	printf("\n%d", i->second);


	int* queens = new int[8]();
	int* columns = new int[8]();
	int* diagLs = new int[15]();
	int* diagRs = new int[15]();

	for(int i = 0; i< 8; i++)
	{
		queens[i] = 0;
		columns[i] = 1;
	}
	
	for(int i = 0; i< 15; i++)
	{
		diagLs[i] = 1;
		diagRs[i] = 1;
	}

	FindSolutionForEightQueens(queens, columns, diagLs, diagRs, 8);

	int resf4 = fac(5);

	stack<int>* stackE = new stack<int>();

	stackE->push(5);
	stackE->push(15);
	int val = stackE->top();
	stackE->pop();
	bool isEmpty = stackE->empty();
	int size = stackE->size();

	queue<int>* queueE = new queue<int>();

	queueE->push(5);
	queueE->push(15);
	queueE->push(22);
	int val33 = queueE->front();
	int val44 = queueE->back();
	queueE->pop();

	StackArray* sa = new StackArray(10);

	int valueSA1 = sa->Top();
	sa->Push(3);
	sa->Push(5);
	int valueSA2 = sa->Top();
	sa->Pop();
	int valueSA3 = sa->Top();

	delete sa;

	STable* table = new STable();
	table->Set(2, 2,3);
	table->Set(14, 2, 6);
	table->Set(9, 2,3);
	table->Set(11, 2,5);

	table->Remove(2,5);
	table->Remove(2,3);

	int ss1 = table->Find(2,3);
	int ss2 = table->Find(2,6);

	delete table;

	CList* clis = new CList();
	clis->AddToBack(5);
	clis->AddToBack(22);
	clis->AddToFront(1);

	SList* list = new SList();
	list->AddToTail(4);
	list->AddToTail(7);
	list->AddToHead(3);
	list->AddToTail(15);
	list->AddToTail(27);
	list->AddToTail(15);
	list->AddToHead(2);
	list->AddToHead(15);

	list->DeleteNodes(15);
	list->DeleteNodes(7);
	list->DeleteNodes(2);
	list->DeleteNodes(44);
	list->DeleteNodes(27);

	bool is1 = list->IsInList(15);
	bool is2 = list->IsInList(3);

	list->DeleteFromHead();
	list->DeleteFromTail();

	vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	
	vector<int> v2(v.begin()+2, v.end());
	vector<int> v3(3,7);
	
	vector<int>* v4 = new vector<int>(v);

	v4->insert(v4->begin(), 5);
	v4->erase(v4->end()-2);

	printVector(&v);
	printVector(&v2);
	printVector(&v3);
	printVector(v4);

	delete v4;

}