// Evaluator_Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Infix2Postfix.h"
#include "evaluatePostfix.h"
#include "Stack_Class.h"



int main()
{


	string exp = "13^2+31";
	exp = infixToPostfix(exp);
	//printf("%s", exp);
	cout <<exp<< endl;
	//printf("Value of %s is %d", exp, evaluatePostfix(exp));
	cout << evaluatePostfix(exp) << endl;
	return 0;
}
