#include "linkedList.h"

#include <iostream>

using namespace std;



current = head;
while(current != null)
{ current = current->link;} // process current node

to output:
current = head;
while (current!=null)
{cout << current->info << " "; current = current->link;}

INSERTION

struct nodeType
{ int info; nodeType *link;};

nodeType *head, *p, *q, *newNode;

//SUPPOSE p points to the node with the info "65," and a new node with info "50" is to be created and
//inserted after p.
newNode = new nodeType; //create newNode
newNode->info = 50; //store 50 in the new node
newnNode->link = p->link;
p->link = newNode;

INSERT NEWNODE BETWEEN P AND Q

using TWO POINTERS we can simplify the insertion code. SUPPOSE q points to the node with info 34.
newNode->link = q;
p->link = newNode;


DELETION

node with info "34" is to be deleted from the list.
p->link = p->link->link. //this doesn't deallocate the memory in this node, just cuts it off *not good
DO THIS INSTEAD:
q = p->link;
p->link = q->link;
delete q;

BUILD FORWARD:
nodeType *first, *last, *newNode;
int num;
//first points to the first node in the list. Since the list starts empty, both first and last are null.
//so we must have these statements:
first = null;
last = null;

cin>>num; //read and store a number in num
newNode = new nodeType; //allocate mem of type nodeType and store the address of the allocaed mem in newNode
newNode->info = num; //copy the value of num into the field of newNode
newNode->link = null; //initialize the link field of newNode to null
if(first == null) //if first is null, the list is empty.
{first = newNode; last = newNode;} //make first and last point to newNode
else //list isn't empty
{last->link = newNode; last = newNode;} //insert newNode at the end of the list, set last to point to the acutal last node in teh list
TO BUILD A LINKED LIST, WE CAN PUT THE PREVIOUS STATEMENT IN A LOOP

nodeType* buildListForward()
{
nodeType *first, *newNode, *last;
int num;
cout << "enter a list of int: " << endl;
cin >> num;
first = null;

while (num != EOF) //or some other condition
{
newNode = new nodeType;
newNode->info = num;
newNode->link = null;
if(first == null)
{
first = newNode;
last = newNode;
}
else
{
last->link = newNode;
last = newNode;
}
cin >> num;
}
return first;
}


BUILD LIST BACKWARD

nodeType* buildListBackward()
{
nodeType *first, *newNode;
int num;
cout << "enter a list of int: " << endl;
cin >> num;
first = null;
while (num!=EOF) //or something
{
newNode = new nodeType;
newNode->info = num;
newNode->link = first; //put newNode at teh beginning
first = newNode; //update the head pointer of the list
cin >> num;
}
return first;
}





int removeEven(node *& head)
{
	node **currentptr = &head;
	int numberOfItemsRemoved = 0;

	while (*currentptr)
	{
		if ((*currentptr)->data % 2)  // Odd
		{
			currentptr = &(*currentptr)->next;
			continue;
		}

		// Remove a node with an even value

		node *p = *currentptr;
		*currentptr = p->next;
		delete p;

		numberOfItemsRemoved++;
	}

	return numberOfItemsRemoved;
}





int removeEven(node *& head)
{
	node * temp = head;
	int even = 0;

	while (temp != NULL && (temp->data % 2) == 0)
	{
		even++;
		temp = temp->next;
		delete temp;
	}

	cout << "There were " << even << " nodes deleted." << endl;

	return even;

}

