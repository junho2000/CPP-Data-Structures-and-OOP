#include <iostream>
using namespace std;

template <typename T>
class DynamicArray
{
private:
	unsigned int sz;
	T* arr;

public:
	DynamicArray(int size) : sz(size)
	{
		arr = new T[sz];
	}
	~DynamicArray()
	{
		delete[] arr;
	}
	unsigned int size() { return sz; }
	T &operator[](const int size) { return arr[size]; }
	const T &operator[](const int size) const { return arr[size]; }
};
int main()
{
	DynamicArray<int> arr(5);
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}
	return 0;
}