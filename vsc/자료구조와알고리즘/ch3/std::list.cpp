#include <iostream>
#include <list> //양방향 linked_list
using namespace std;

int main()
{
	list<int> l1;
	l1.push_back(10);
	l1.push_back(20);

	list<int> l2{10, 20, 30, 40};

	for (auto n : l1)
		cout << n << ", ";
	cout << endl;

	for (auto n : l2)
		cout << n << ", ";
	cout << endl;

	l2.splice(l2.end(), l1); // l2.end()에 l1이어 붙임, l1의 원소들은 다 삭제됨.
	for (auto n : l2)
		cout << n << ", ";
	for (auto n : l1)
		cout << n << ", ";
	cout << endl;

	l2.sort();
	for (auto n : l2)
		cout << n << ", ";
	cout << endl;

	return 0;
}