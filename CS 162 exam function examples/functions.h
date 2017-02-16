#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <iostream>
#include <cstring>
#include <cctype>

struct node
{
	int data;
	node * next;

};

//the prototypes do not need the variable NAME in the parameter list
//but they do need the data type of each parameter


double larger(double x, double y);

double compareThree(double x, double y, double z); 

int nthFibonacciNum(int first, int second, int nthFibNum);

//VALUE PARAMETER: a formal parameter that recieves a copy of the content of teh corresponding actual parameter
//REFERENCE PARAM: dataType& variableName	
//a formal param that gets recieves the location (in memeory) of the corres. act. param.

void printStars(int blanks, int starsInLine);



class listType
{
public: 
	bool isEmptyList() const;
	bool isFullList() const;
	int search(int searchItem) const;
	void insert(int newElement);
	void remove(int removeElement);
	void destroyList();
	void printList() const;
	listType(); //constructor
private:
	int list[100];
	int length;
};



class integerManipulation
{
public:
	void setNum(int n);
	int getNum();
	void reverseNum();
	void classifyDigits();
	int getEvensCount();
	int getOddsCount();
	int getZerosCount();
	int sumDigits(int num);
	integerManipulation(int n = 0);
private:
	int num;
	int revNum;
	int evensCount;
	int oddsCount;
	int zerosCount;
};


int sumOfList(node * head);

void insert(node *& head, int position, int newInt);
//or
/*
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	bool add(int val);
	bool remove(int val);
	void printAscending() const;
	void printDescending() const;

private:
	struct classNode
	{
		int data;
		classNode * next;
		classNode * prev;
	};
	classNode * head, *tail;
	int count; //ok to add a count variable here?


};

*/








#endif // !FUNCTIONS_H
