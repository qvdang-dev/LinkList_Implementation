#include <iostream>
#include "linklist.h"
using namespace std;

int main()
{
	int data, numOfNote;

	insert(3,1);
	insert(2,2);
	insert(4,1);
	insert(6,3);
	insert(5,2);

	display();

	reverse();
	
	DisplayRecurtion(GetHeadNode());


	return 0;
}