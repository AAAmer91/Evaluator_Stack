#include "stdafx.h"
#include "evaluatePostfix.h"
#include "Stack_Class.h"
#include <string>
#include <vector>

extern vector<pair<char, int>> vartable;

int replacevariable(char c) {
	for (auto it = vartable.begin(); it != vartable.end(); it++)
	{
		if (it->first == c)
			return it->second;
	}

}

int evaluatePostfix(string exp)
{
	stack st;
	double operand = 0;
	int idigit = 0;
	// Scan all characters one by one
	for (int i = 0; exp[i]; ++i)
	{
	
				// If the scanned character is an operand (number here),
				// push it to the stack.
				if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z')) {
					int operand = replacevariable(exp[i]);
					st.push(operand);
				}
				else if (isdigit(exp[i])){
					operand = (operand * 10) + (exp[i] - '0');
					if (isdigit(exp[i + 1])) {
						idigit++;
						continue;
					}
					st.push(operand);
				}
				else if(exp[i] == ' ')
				{
					operand = 0;
					continue;
				}
				//  If the scanned character is an operator, pop two
				// elements from stack apply the operator
				else
				{
					int val1 = st.pop();
					int val2 = st.pop();

			switch (exp[i])
			{
			case '+': st.push( val2 + val1); break;
			case '-': st.push( val2 - val1); break;
			case '*': st.push( val2 * val1); break;
			case '/': st.push( val2 / val1); break;
			case '^': st.push(pow(val2,val1)); break;
			}
		}
	}
	return st.pop();
}