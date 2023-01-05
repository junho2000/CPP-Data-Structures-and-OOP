#include <iostream>
#include <vector>
using namespace std;
//operator[], front, back, push_back, pop_back, clear, size, empty -> O(1)
// insert, erase -> O(n)

int main()
{
	vector<int> vec1 {1, 2, 3, 4};
	cout << vec1.capacity() << ":" << vec1.size() << endl;

	vec1.push_back(5); // capacity가 부족하면 2배로 늘리고 뒤에 붙임
	cout << vec1.capacity() << ":" << vec1.size() << endl;

	vec1.push_back(6);
	cout << vec1.capacity() << ":" << vec1.size() << endl;

	vec1.insert(vec1.begin(), 0);
	cout << vec1.capacity() << ":" << vec1.size() << endl; // 0 1 2 3 4 5 6

	vec1.erase(vec1.begin() + 1, vec1.begin() + 3); // 1 ~ 2까지 마지막 인덱스는 포함 x
	cout << vec1.capacity() << ":" << vec1.size() << endl;
	for (int i = 0; i < vec1.size(); i++)
		cout << vec1[i] << endl; // 0 3 4 5 6

	// for(int i=0; i<vec1.size(); i++)
	//     cout<<vec1[i]<<endl; // 0 3 4 5 6 5 6 0 erase대상 뒤에 남은 걸 앞에 붙여넣기함. 앞으로 땡겨진 만큼 뒤에 요소를 지우지 않음.

	return 0;
}