// Evaluator_Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include "Infix2Postfix.h"
#include "evaluatePostfix.h"
#include "Stack_Class.h"
#include "Var_Class.h"

Variables V;

int main()
{
	string exp; 
	bool setflag;
	cout << "Enter Expression" << endl;
	cout << "Type 0 to END!" << endl;
	while (true) {
		do {
			setflag = false;
			getline(cin, exp);
			if (exp == "0")
				return 0;
			for (int i = 0; i < exp.length(); i++) {
				if (exp.at(i) == '=') {
					V.setvariable(exp);
					setflag = true;
					break;
				}
			}
		} while (setflag);

		exp = infixToPostfix(exp);
		cout << exp << endl;
		cout << evaluatePostfix(exp) << endl;
	}
	return 0;
}