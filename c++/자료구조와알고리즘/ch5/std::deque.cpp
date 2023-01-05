#include <deque>
#include <iostream>
using namespace std;
// deque(뎈) 양방향 큐임. 앞과 뒤에서 요소를 넣고 뺄 수 있음. 스택과 큐를 합친거라고 생각하면 됨.

int main()
{
	deque<int> d{10, 20, 30, 40}; // vector와 비슷함
	d.push_front(50);
	d.push_back(60);

	for (int i = 0; i < d.size(); i++)
		cout << d[i] << ", ";
	cout << endl;

	//for(const auto& i : d)
	//    cout<<i<<", ";
	//cout<<endl;

	return 0;
}
