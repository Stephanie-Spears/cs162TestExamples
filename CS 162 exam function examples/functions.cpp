#include "functions.h"

#include <iostream>

using namespace std;


double larger(double x, double y)
{
	//no local variables
	if (x >= y)
	{
		return x;
	}
	else
	{
		return y;
	}

}

double compareThree(double x, double y, double z)
{
	return larger(x, larger(y, z));
}

int nthFibonacciNum(int first, int second, int nthFibNum)
{
	int current;
	int counter;

	if (nthFibNum == 1)
	{
		current = first;
	}
	else if (nthFibNum == 2)
	{
		current = second;
	}
	else
	{
		counter = 3;
		while (counter <= nthFibNum)
		{
			current = second + first;
			first = second;
			second = current;
			counter++;
		}
	}
	return current;
}


bool isPalindrome(string str)
{
	int length = str.length();
	for (int i = 0; i < length / 2; i++)
	{
		if (str[i] != str[length - 1 - i])
		{
			return false;
		}
	}
	return true;
}


void printStars(int blanks, int starsInLine)
{
	int count;
	for (count = 1; count <= blanks; count++)
	{
		cout << ' ';
	}
	for (count = 1; count <= starsInLine; count++)
	{
		cout << " * ";
	}
	cout << endl;
}

void integerManipulation::setNum(int n)
{
	num = n;
}
int integerManipulation::getNum()
{
	return num;
}
void integerManipulation::reverseNum()
{
	int remainder;
	while (num != 0)
	{
		remainder = num%10;
		revNum = revNum * 10 + remainder;
		num /= 10;
	}
	cout << "reverse num: " << revNum << endl;;
}
void integerManipulation::classifyDigits()
{
	int temp;
	temp = abs(num);
	int digit;
	while (temp != 0)
	{
		digit = temp - (temp / 10) * 10;
		temp = temp / 10;
		if (digit % 2 == 0)
		{
			evensCount++;
			if (digit == 0)
			{
				zerosCount++;
			}
		}
		else
		{
			oddsCount++;
		}
	}
}
int integerManipulation::getEvensCount()
{
	return evensCount;
}
int integerManipulation::getOddsCount()
{
	return oddsCount;
}
int integerManipulation::getZerosCount()
{
	return zerosCount;
}
int integerManipulation::sumDigits(int num)
{
	int sum = 0;
	while (num != 0)
	{
		sum = sum + num % 10;
		num = num / 10;
	}
	cout << "the sum is: " << sum << endl;
	return 0;
}
integerManipulation::integerManipulation(int n)
{
	num = n;
	revNum = 0;
	evensCount = 0;
	oddsCount = 0;
	zerosCount = 0;
}


/*int sumOfList(node * head)
{


	return 0;
}

void insert(node *& head, int position, int newInt)
{

}
*/

/*
LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

LinkedList::~LinkedList()
{
	classNode * current = head;

	while (head != NULL)
	{
		current = head->next;
		delete head; //delete the node pointed to by head.
		head = current;
	}
}

bool LinkedList::add(int val) //makes an ordered list...
{
	classNode * current; //pointer to traverse the list
	classNode *trailCurrent; //pointer just before the current
	classNode *newNode; //pointer to create a node
	bool found;

	newNode = new classNode; //create a node (allocate space in memory that can hold information for datatype "Node" (ie. address of the head/tail, space for data to be inserted, address of pointers to the prev and next nodes in the list)
	newNode->data = val; //store the given val inside the node's data section.
	newNode->next = NULL; //newnode's "next" link is set to null (since we're unsorted)
	newNode->prev = NULL; //newnode's "prev" link is set to null. *IS THIS OK HERE, OR DOES IT ALWAYS ASSUME THAT THE NEW VALUE IS ALONE 

	if (head == NULL)
	{//if the val passed in is the first to be added to the list
		head = newNode; //then the newnode data replaces the null of head and tail
		tail = newNode;
		count++;
	}
	else //if it's not the first in the list
	{
		found = false;
		current = head;

		while (current != NULL && !found) //while current doesn't point to an empty node, and found is still false
		{
			if (current->data >= val) //if the current pointer points to a value that is bigger than or equal to the value we're trying to pass in
			{
				found = true; //breaks out of the "notfound" while loop.
			}
			else
			{
				trailCurrent = current; //the address just before "current" is now set to "current"
				current = current->next; //the address of current is changed to the address of the following node link.
										 //this is breaking (replacing) the old links to the previously contiguous nodes and allowing the new node to be linked up between them
			}
		}
		if (current == head) //if the current node IS THE FIRST node
		{
			head->prev = newNode; //insert newNode before first
			newNode->next = head;
			head = newNode; //update address so now head points to the correct beginning
			count++;
		}
		else
		{
			if (current != NULL) //insert newnode between trailCurrent and current
			{
				trailCurrent->next = newNode;
				newNode->prev = trailCurrent;
				newNode->next = current;
				current->prev = newNode;
			}
			else
			{
				trailCurrent->next = newNode;
				newNode->prev = trailCurrent;
				tail = newNode;
			}
			count++;
		}
	}
	return true;
}

bool LinkedList::remove(int val)
{
	classNode * current; //pointer to traverse the list
	classNode * trailCurrent; //pointer just before current
	bool found;

	if (head == NULL)
	{
		cout << "List is Empty" << endl;

	}
	else if (head->data == val)
	{
		current = head;
		head = head->next;
		if (head != NULL)
		{
			head->prev = NULL;
		}
		else
		{
			tail = NULL;

		}
		count--;
		delete current;
	}
	else
	{
		found = false;
		current = head;
		while (current != NULL && !found) //search list
		{
			if (current->data >= val)
			{
				found = true;
			}
			else
			{
				current = current->next;
			}
		}
		if (current == NULL)
		{
			cout << "Item to be deleted is not in the list. " << endl;
		}
		else if (current->data == val) //check if item being pointed at and item to be deleted are same
		{
			trailCurrent = current->prev;
			trailCurrent->next = current->next;
			if (current->next != NULL)
			{
				current->next->prev = trailCurrent;
			}
			if (current == tail)
			{
				tail = trailCurrent;
			}
			count--;
			delete current;
		}
		else
		{
			cout << "Item to be deleted is not in the list." << endl;
		}
	}
	return true;
}

void LinkedList::printAscending() const
{
	classNode * current; //pointer to traverse the list
	current = head; //set the pointer to the first node in the list

	while (current != NULL) //while the node that current points to ISN'T empty
	{
		cout << current->data << " "; //output the value stored in data (pointed to by current)
		current = current->next; //set the new "current" pointer to the address stored in the "next" node

	}

}

void LinkedList::printDescending() const
{
	classNode * current; //pointer to traverse the list
	current = tail; //set current to point to the last node in the list

	while (current != NULL) //while current points to an address that ISN'T empty
	{
		cout << current->data << " "; //output data stored in the address pointed to by "current"
		current = current->prev; //set the address stored in the pointer "current" to the address stored in the "prev" node
	}
}

*/




int sumOfList(node * head);

void insert(node *& head, int position, int newInt);