#include <iostream>
#include <string>
#include <map>
#include "Infix2Postfix.h"
#include "evaluatePostfix.h"

class Variables
{
	map<char, double> vartable;
public:
	void setvariable(string EXP);
	double getvar(char c);
};

