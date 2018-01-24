#include "stdafx.h"
#include "Stack_Class.h"
#include <iostream>
using namespace std;


// PUSH Operation
void stack::push(int data)
{
	struct node *ptr;
	ptr = new node;
	ptr->data = data;
	ptr->next = NULL;
	if (ptop != NULL)
		ptr->next = ptop;
	ptop = ptr;

}

// POP Operation
int stack::pop()
{
	struct node *temp;
	if (ptop == NULL)
	{
		return -1;
	}
	temp = ptop;
	ptop = ptop->next;
	int popped = temp->data;
	delete temp;
	return popped;
}

// top of the stack
int stack::top()
{

	if (ptop != NULL)
	{
		return ptop->data;
	}
	return -1;
}

//empty flag 
int stack::isEmpty()
{
	return !ptop;
}