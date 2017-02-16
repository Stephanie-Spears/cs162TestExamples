#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
	/* to make a pyramid of stars */
	int noOfLines = 5;
	int counter;
	int noOfBlanks = 30;

	for (counter = 1; counter <= noOfLines; counter++)
	{
		printStars(noOfBlanks, counter);
		noOfBlanks--;
	}

	/* to manipulate an integer */
	integerManipulation number;
	int num;

	cout << "enter an integer: ";
	cin >> num;
	cout << endl;

	number.setNum(num);
	number.classifyDigits();
	cout << number.getNum() << "-----" << endl;
	cout << "the number of even digits: " << number.getEvensCount() << endl;
	cout << "the number of odds digits: " << number.getOddsCount() << endl;
	cout << "zeros: " << number.getZerosCount() << endl;
	number.reverseNum();
	number.sumDigits(num);

	/*
	& returns the address of its operand. 
	int x;
	int *p;
	p = &x; //assigns the address of x to p. so x and the VALUE of p refer to the same memory location


	int num1, num2;
	int *numptr;
	num1 = 100; //num1 means "the value held in the memory locatino named num1"
	num2 = num1; //copeis the integer "100" at the memory location "num1" into the memory loc. "num2"

	numptr = &num1; //copies the address of the memory location of num1 into numptr, NOT the integer value it is holding.
	*/

	/*
	DEREFERENCING OPERATOR
	* refers to the object to which its operand (that is, the pointer) points.

	int x = 25;
	int *p;
	p = &x; //stores the address of x into p
	cout << *p << endl; //prints the value stored in the memory space pointed to by p, which is the value of x.
	*p = 55; //stores 55 in the memory location pointed to by p--that is, in x.

	struct studentType
	{
	char name[26];
	double gpa;
	char grade;
	};

	studentType student; //object of type studentType.
	studentType *studentPtr; //pointer variable of type studentType
	studentPtr = &student; //stores teh address of student in studentPtr.
	(*studentPtr).gpa = 3.9 //stores 3.9 in teh gpa componenet of the object student
	studentPtr->gpa = 3.9 //does the same as above. easier notation.
	*/


	/*
	DYNAMIC VARIABLES
	new dataType; //operator "new" allocates memory (as a variable) of the specified type and returns a pointer to it (an address)
	new dataType[intExp]; //this allocated memory is uninitialized

	int *p;
	char *q;
	int x;
	p=&x; //stores teh address of x in p. no new memory is allocated
	p = new int; //creates a variable during execution somewhere in memory and stores the address of the allocated memory in p (which is accessed via pointer dereferencing "*p")
	q = new char [16]; //creates an array of 16 components of type char and stores teh base address of the array in	q.
	
	//since dynamic variables are unnamed, it cannot be accessed directly. it is accessed indireclty by the pointer returned by new.
	int *p; //p is a pointer of type int
	char *name; //pointer of type char
	string *str; //pointer of type string
	p = new int; //allocates memory of type int and stores the address in "p"
	*p = 28; //stores 28 in the allocated memory
	name = new char[5]; //allocates mem for an array of five char components and stores the base address of the array in "name"
	strcpy(name, "John"); //stores "John" in name
	str = new string; //allocates mem of type string, stores adderess in str
	*str = "Sunny Day"; //stores string "Sunny Day" in the memory pointed to by str
	//to delete the values we can use delete p or delete [] p, but some systems will leave the memory
	//allocated, so we should always set oour pointers back to NULL.
	
	*/

	/*
	
	int *p;
	int *q;
	p=q; //copies value of q into p. both p and q point to the same mem location
	p == q //compares pointer vars for equality. is true if they have the same value (ie. point to the same mem loc)


	void pointerParameters(int* &p, double *q)
	{...} // both p and q are pointers. p is a reference parameter, and q is a value parameter.
	//the function can change the value of *q, but not the value of q.
	//However, the function can change the value of both p and *p

	int* testExp(...)
	{...} //pointer of type int

	int *board[4]; //array of four pointers. can now use these pointers to create the rows of board
	for(int row = 0; row < 4; row++)
	{board[row] = new int[6];}

	int **board; //declares board to be a pointer to a pointer. board and *board are both pointers.
	//now board can store teh address of a pointer or an array of pointers, and *board can store the
	//address of a memory space or an arrya of values

	DEEP COPY

	int *first; //pointer variable
	int *second; //pointer variable
	first = new int[10]; //creates an array of 10 components and stores the base address into first.
	second = new int[10];
	for (int j = 0; j < 10; j++)
	{second[j] = first[j];} //copies the array pointed to by first into the array pointed to by second.
	//both first and second now point to their own data. if second deletes its memory, there is no effect
	//on first.

	*/

	/*
	LINKED LISTS

	every node (except the last node) contains the address of the next node (link/pointer), and data.

	struct nodeType
	{
	int info;
	nodeType *link;
	};
	nodeType *head; //this is how we declare the "link" component, since the link is a pointer
	//the address of the first node is stored in the pointer "head"
	current = head; //copies the value of head into current.
	current = current->link; //copies the value of current->link into current.
	//so current points to the second node in the list


	to traverse:

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

	SUPPOSE p points to the node with the info "65," and a new node with info "50" is to be created and
	inserted after p. 
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
	
	
	*/
	



	//after copying data, a VALUE param has no connection to the ACTUAL param, so it cannot
	//pass any results back to the calling function. Any changes made are discarded
	//REFERENCE parameters recieve the address of the actual param, so they can pass back
	//one or more values from a function and can change the value of the actual param
	//REF is useful in three situations: 
	//1) when the value of the acutal param needs to be changed.
	//2)when you want to return more than one value from a function
	//3)when passing an address would save memory space and time compared to copying a large amount of data
	//you can make a REF param const, which stops the formal parameter form being able to change
	//the corresponding actual parameter
	//a constant value cannot be passed to a NONconstant reference parameter.
	//if a formal parameter is a NONconstant reference param, during a function call, its 
	//corresponding actual param must be a variable
	//unlike global variables (not recommneded), global named constants have no side effects, 
	//because their values cannot be changed during program execution.








/*
	LinkedList aList;

	aList.add(3);
	aList.add(1);
	aList.add(6);
	aList.printAscending;
	aList.printDescending;
	aList.remove(3);
	aList.printAscending;
*/




	return 0;
}