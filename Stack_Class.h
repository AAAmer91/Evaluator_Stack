// A class to represent a stack
#include <iostream>
#include <string>


struct node
{
	double data;
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
	void push(double data); // to insert an element
	double pop();  // to delete an element
	double top(); // to show the stack
	int isEmpty();
};