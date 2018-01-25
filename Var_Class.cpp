#include "stdafx.h"
#include "Var_Class.h"
#include <iostream>
using namespace std;


void Variables::setvariable(string EXP) {
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
	vartable[cLHS] = evaluatePostfix(infixToPostfix(RHS));
}

double Variables::getvar(char c) {
	return vartable[c];
}