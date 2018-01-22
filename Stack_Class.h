// A class to represent a stack
#include <iostream>
#include <string>


struct node
{
	int data;
	struct node *next;
};

// Creating a class STACK
class stack
{
	struct node *ptop;
public:
	stack() // constructor
	{
		ptop = NULL;
	}
	void push(int data); // to insert an element
	int pop();  // to delete an element
	int top(); // to show the stack
	int isEmpty();
};