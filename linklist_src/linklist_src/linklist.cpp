#pragma once
#include "linklist.h"

using namespace std;

node* g_pnHead;
node* g_pnRear;

void insert(int value)
{
	node* pnTemp = new node();
	pnTemp->data = value;
	pnTemp->next = NULL;
	pnTemp->m_isHead = false;
	pnTemp->m_isRear = true;

	// Check if Link list is emty or not
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

void insert(int value, int pos)
{
	bool isError;
	node* pInterator = g_pnHead;
	node* pnTemp = new node();
	pnTemp->m_isRear = false;
	pnTemp->m_isHead = false;
	pnTemp->next = NULL;

	pnTemp->data = value;
	isError = false;
	if (pos == 1)
	{
		if (g_pnHead != NULL)
		{
			g_pnHead->m_isHead = false;
			pnTemp->next = g_pnHead;
		}
		else
		{
			g_pnRear = pnTemp;
		}
		g_pnHead = pnTemp;
		g_pnHead->m_isHead = true;
	}
	else
	{
		if ((pos == 0) | (pInterator == NULL))
			cout << "Error !\n";
		else
		{
			for (int i = 0; i < pos - 2; i++)
			{
				if (pInterator->next == NULL)
				{
					if (i < (pos - 2))
						isError = true;

					break;
				}

				pInterator = pInterator->next;
			}

			if (isError == false)
			{
				if (pInterator->next == NULL)
				{
					pInterator->m_isRear = false;
					pnTemp->m_isRear = true;
				}
				pnTemp->next = pInterator->next;
				pInterator->next = pnTemp;
			}
			else
			{
				cout << "Error !\n";
			}
		}
	}
}

void deleteNode(int pos)
{
	bool IsError;
	node* pnTemp = g_pnHead;
	node* DeteleNode;

	IsError = false;
	if (pos == 0)
	{
		IsError = true;
		cout << "Error !\n";
	}
	else
	{
		if (pos == 1)
		{
			g_pnHead = g_pnHead->next;
			g_pnHead->m_isHead = true;
			pnTemp = NULL;
			delete(pnTemp);
			//free(pnTemp);
		}
		else
		{
			for (int i = 0; i < pos - 2; i++)
			{
				if ((pnTemp->next)->next == NULL)
				{
					if (i < pos - 2)
					{
						IsError = true;
						break;
					}
				}
				pnTemp = pnTemp->next;
			}

			if (IsError == false)
			{
				DeteleNode = pnTemp->next;
				if ((pnTemp->next)->next == NULL)
				{
					pnTemp->m_isRear = true;
				}
				pnTemp->next = DeteleNode->next;
				DeteleNode = NULL;
				delete(DeteleNode);
				//free(DeteleNode);
			}
			else
			{
				cout << "Error !\n";
			}

		}

	}

}

void reverse()
{
	node* pCurrent = g_pnHead;
	node* pNext;
	node* pPre = NULL;

	pCurrent->m_isHead = false;
	pCurrent->m_isRear = true;
	while (pCurrent != NULL)
	{
		pNext = pCurrent->next;
		pCurrent->next = pPre;
		pPre = pCurrent;
		pCurrent = pNext;
	}
	g_pnHead = pPre;
	g_pnHead->m_isHead = true;
	g_pnHead->m_isRear = false;
}

void reverseUsingRecursion(node *pNote)
{
	pNote->m_isHead = false;
	pNote->m_isRear = false;

	if(pNote->next == NULL)
	{
		g_pnRear = g_pnHead;
		g_pnRear->m_isRear = true;
		g_pnHead = pNote;
		g_pnHead->m_isHead = true;

		return;	
	}	
	reverseUsingRecursion(pNote->next);

	node *Temp = pNote->next;
	Temp->next = pNote;
	pNote->next = NULL;
}

void DisplayRecurtion(node* pNode)
{
	static bool first = false;

	if (pNode == NULL)
	{
		cout << "|End|";
		first = false;
		return;
	}

	if (first == false)
	{
		first = true;
		cout << "Current LinkList: " << endl;
	}

	cout << "[Data: " << pNode->data;
	cout << "|Addr: " << pNode;
	cout << "|Next: " << pNode->next;
	cout << "|IsHead: " << pNode->m_isHead << "|IsRear: ";
	cout << pNode->m_isRear << "]\n";
	DisplayRecurtion(pNode->next);

}

void display()
{
	node* pnTemp = g_pnHead;
	cout << "Current LinkList: " << endl;
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

node *GetHeadNode()
{
	return g_pnHead;
}