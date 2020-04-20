#pragma once
#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
	bool m_isHead;
	bool m_isRear;
};

void insert(int value);
void insert(int value, int Pos);
void display();
void deleteNode(int pos);
void reverse();
node *GetHeadNode();
void DisplayRecurtion(node *pNode);



