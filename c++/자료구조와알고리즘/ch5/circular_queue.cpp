#include <iostream>
#define MAX_QUEUE 10
using namespace std;

template <typename T>
class CircularQueue
{
private:
	T *arr;
	int front_idx;
	int rear_idx;
	int count;
	int capacity;

public:
	CircularQueue(int sz = MAX_QUEUE) // default로 사이즈 10으로 지정
	{
		arr = new T[sz];
		front_idx = 0;
		rear_idx = -1;
		count = 0;
		capacity = sz;
	}
	~CircularQueue()
	{
		delete[] arr;
	}
	void enqueue(const T &a)
	{
		if (full()) {
			cout << "Stack Overflow!!" << endl;
			return;
		}
		rear_idx = (rear_idx + 1) % capacity;
		arr[rear_idx] = a;
		count++;
	}
	void dequeue()
	{
		if (empty()) {
			cout << "Stack Underflow!!" << endl;
			return;
		}
		front_idx = (front_idx + 1) % capacity;
		count--;
	}
	const T &front() const
	{
		return arr[front_idx];
	}
	bool empty()
	{
		return count == 0;
	}
	bool full()
	{
		return count == capacity;
	}
	int size() const
	{
		return count;
	}
};

int main()
{
	CircularQueue<int> q(5); // size 5로 지정

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.dequeue();
	q.dequeue();
	q.enqueue(60);
	q.enqueue(70);

	q.enqueue(80); // overflow

	while (!q.empty()) {
		const auto &a = q.front();
		cout << a << ", ";
		q.dequeue();
	}
	cout << endl;

	return 0;
}
