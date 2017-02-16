#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstring>
#include <cctype>

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


#endif // !LINKEDLIST_H
