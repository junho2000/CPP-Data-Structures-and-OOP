#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// vector 순서 뒤집기

template <typename T>
void reverse(vector<T> &vec)
{
	stack<T, vector<T>> stk(vec); // 스택의 기본 container를 vector로 지정.

	//    stack<T> stk;
	//    for(const auto a : vec)
	//        stk.push(a);

	for (int i = 0; i < vec.size(); i++) {
		vec[i] = stk.top();
		stk.pop();
	}
}

int main()
{

	vector<int> vec1{10, 20, 30, 40};
	vector<string> vec2{"KIM", "JOHN", "PARK"};

	reverse(vec1);
	for (auto a : vec1) {
		cout << a << ", ";
	}
	cout << endl;

	reverse(vec2);
	for (auto a : vec2) {
		cout << a << ", ";
	}
	cout << endl;

	return 0;
}
