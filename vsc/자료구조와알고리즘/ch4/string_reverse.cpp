#include <iostream>
#include <stack>
using namespace std;
//문자열을 거꾸로 출력하는 문제

string reverse(const string &str)
{
	stack<char> stk;
	string res;

	for (char c : str)
		stk.push(c);

	while (!stk.empty()) {
		res += stk.top();
		stk.pop();
	}

	return res;
}
int main()
{
	string str1 = "HELLO";
	string str2 = "ALGORITHM";

	cout << "HELLO -> " << reverse(str1) << endl;
	cout << "ALGORITM -> " << reverse(str2) << endl;

	return 0;
}