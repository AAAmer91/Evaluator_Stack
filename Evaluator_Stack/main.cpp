// Evaluator_Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include "Infix2Postfix.h"
#include "evaluatePostfix.h"
#include "Stack_Class.h"

vector<pair<char, int>> vartable;

void setvariable(string);

int main()
{
	string exp; 
	bool setflag;
	cout << "Enter Expression" << endl;
	cout << "Type 0 to END!" << endl;
	do {
		do {
			setflag = false;
			getline(cin, exp);
			for (int i = 0; i < exp.length(); i++) {
				if (exp.at(i) == '=') {
					setvariable(exp);
					setflag = true;
					break;
				}
			}
		} while (setflag);

		exp = infixToPostfix(exp);
		cout << exp << endl;
		cout << evaluatePostfix(exp) << endl;
	} while (exp != "0");
	return 0;
}

void setvariable(string EXP) {
	int index;
	static int row = 0;
	for (index = 0; index < EXP.length(); index++) {
		if (EXP.at(index) == '=')
			break;
	}
	string::iterator it = EXP.begin();

	std::string LHS(it, it + index);
	std::string RHS(it + index + 1, EXP.end());
	char cLHS = LHS.at(0);
	vartable.push_back(pair<char, int>(cLHS, evaluatePostfix(infixToPostfix(RHS))));
}