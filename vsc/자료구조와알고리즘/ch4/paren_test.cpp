#include <iostream>
#include <stack>
#include <vector>
using namespace std;
//올바르게 괄호가 되어있는지 확인

bool paren_check(const string &str)
{
	stack<char> stk;
	for (char a : str) {
		if (a == '(' || a == '{' || a == '[')
			stk.push(a);
		else {
			if (stk.empty())
				return false;
			else {
				if (stk.top() == '(' && a == ')' ||
					stk.top() == '{' && a == '}' ||
					stk.top() == '[' && a == ']')
					stk.pop();
				else
					return false;
			}
		}
	}

	return stk.empty();
}

int main()
{

	cout << paren_check("(){}[]") << endl;
	cout << paren_check("((((()))))") << endl;
	cout << paren_check("(){[()]}") << endl;

	cout << paren_check(")(") << endl;
	cout << paren_check("((({}))") << endl;
	cout << paren_check("({)}") << endl;

	return 0;
}
