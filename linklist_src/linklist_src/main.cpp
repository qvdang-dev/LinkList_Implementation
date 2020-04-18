#include <stdio.h>
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
void display();

node* g_pnHead;
node* g_pnRear;

void insert(int value)
{
	node* pnTemp = new node();
	pnTemp->data = value;
	pnTemp->next = NULL;
	pnTemp->m_isHead = false;
	pnTemp->m_isRear = true;

	if (g_pnRear == NULL)
	{
		g_pnHead = pnTemp;
		g_pnHead->m_isHead = true;	
	}
	else
	{
		g_pnRear->next = pnTemp;
		g_pnRear->m_isRear = false;
	}

	g_pnRear = pnTemp;
	
}

void display()
{
	node* pnTemp = g_pnHead;
	cout << "Current LinkList: "<<endl;
	while (pnTemp != NULL)
	{
		cout << "[Data: " << pnTemp->data;
		cout << "|Addr: " << pnTemp;
		cout << "|Next: " << pnTemp->next;
		cout << "|IsHead: " << pnTemp->m_isHead << "|IsRear: ";
		cout << pnTemp->m_isRear << "]\n";
		pnTemp = pnTemp->next;
	}
	cout << "|End|\n";
}

int main()
{
	int data, numOfNote;
	g_pnHead = NULL;
	g_pnRear = NULL;

	cout << "Number of Node: ";
	scanf_s("%d", &numOfNote);

	for (int i = 0; i < numOfNote; i++)
	{
		cout << " + Data " << i << ": ";
		scanf_s("%d", &data);
		insert(data);
	}
	display();

	return 0;
}