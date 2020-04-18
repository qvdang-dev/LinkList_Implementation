#include <stdio.h>
#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
};

void insert(int value);
void display();

node* g_pnHead;
void insert(int value)
{
	node* pnTemp = new node();
	pnTemp->data = value;
	pnTemp->next = NULL;

	if (g_pnHead != NULL)
		pnTemp->next = g_pnHead;

	g_pnHead = pnTemp;

}

void display()
{
	node* pnTemp = g_pnHead;
	cout << "current link list: ";
	while (pnTemp != NULL)
	{
		cout << "[" << pnTemp->data << "|" << pnTemp->next << "]" << "-->";
		pnTemp = pnTemp->next;
	}
	cout << " |NULL|\n";
}

int main()
{
	int data, numOfNote;
	g_pnHead = NULL;

	cout << "Number of Node: ";
	scanf_s("%d", &numOfNote);

	for (int i = 0; i < numOfNote; i++)
	{
		cout << " + Data " << i << ": ";
		scanf_s("%d", &data);
		cout << "\n";
		insert(data);
	}
	display();

	return 0;
}