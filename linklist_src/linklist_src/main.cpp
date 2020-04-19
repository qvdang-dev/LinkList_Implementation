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
void insert(int value, int Pos);
void display();
void deleteNode(int pos);

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

void insert(int value, int pos)
{
	bool isError;
	node *pInterator = g_pnHead;
	node *pnTemp = new node();
	pnTemp->m_isRear = false;
	pnTemp->m_isHead = false;
	pnTemp->next = NULL;

	pnTemp->data = value;
	isError = false;
	if( pos == 1)
	{
		if(g_pnHead != NULL)
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
		if((pos == 0)|(pInterator == NULL))
			cout << "Error !\n";
		else
		{
			for(int i = 0; i < pos - 2; i++)
			{
				if(pInterator->next == NULL)
				{
					if( i < (pos - 2))
						isError = true;

					break;
				}

				pInterator = pInterator->next;
			}

			if(isError == false)
			{
				if(pInterator->next == NULL)
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
	node *pnTemp = g_pnHead;
	node *DeteleNode;

	IsError = false;
	if( pos == 0 )
	{
		IsError = true;
		cout << "Error !\n";
	}
	else
	{
		if(pos == 1)
		{
			g_pnHead = g_pnHead->next;
			g_pnHead->m_isHead = true;
			pnTemp = NULL;
			delete(pnTemp);
			//free(pnTemp);
		}
		else
		{
			for( int i = 0; i < pos - 2 ; i++)
			{
				if((pnTemp->next)->next == NULL)
				{
					if( i < pos - 2)
					{
						IsError = true;
						break;
					}
				}
				pnTemp = pnTemp->next;
			}

			if(IsError == false)
			{
				DeteleNode = pnTemp->next;
				if((pnTemp->next)->next == NULL)
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

	// cout << "Number of Node: ";
	// scanf_s("%d", &numOfNote);

	// for (int i = 0; i < numOfNote; i++)
	// {
	// 	cout << " + Data " << i << ": ";
	// 	scanf_s("%d", &data);
	// 	insert(data, i + 1);
	// }
	insert(3,1);
	insert(2,2);
	insert(4,1);
	insert(6,3);
	insert(5,2);
	deleteNode(3);
	//deleteNode(1);

	display();

	return 0;
}