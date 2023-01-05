#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *prev;
	Node *next;
};
class DoublyLinkedList
{
private:
	int count;
	Node *header;
	Node *trailer;

public:
	DoublyLinkedList() : count(0)
	{
		header = new Node{0, NULL, NULL};
		trailer = new Node{0, NULL, NULL};
		header->next = trailer;
		trailer->prev = header;
	}
	~DoublyLinkedList()
	{
		while (!empty()) {
			pop_front();
		}
		delete trailer;
		delete header;
	}
	bool empty()
	{
		return count == 0;
	}
	int size()
	{
		return count;
	}
	void insert(Node *p, int val) // Node p 앞에 insert
	{
		Node *new_node = new Node{val, p->prev, p};
		new_node->next->prev = new_node;
		new_node->prev->next = new_node;
		count++;
	}
	void erase(Node *p)
	{
		p->next->prev = p->prev;
		p->prev->next = p->next;
		delete p;
		count--;
	}
	void push_front(int val)
	{
		insert(header->next, val);
	}
	void push_back(int val)
	{
		insert(trailer, val);
	}
	void pop_front()
	{
		if (!empty())
			erase(header->next);
	}
	void pop_back()
	{
		if (!empty())
			erase(trailer->prev);
	}
	void print_all()
	{
		Node *temp = header->next;
		while (temp != trailer) {
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << endl;
	}
	void print_reverse()
	{
		Node *temp = trailer->prev;
		while (temp != header) {
			cout << temp->data << ", ";
			temp = temp->prev;
		}
		cout << endl;
	}
};
int main()
{
    DoublyLinkedList ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.print_all();
    ll.print_reverse();
    
    ll.pop_back();
    ll.pop_front();
    ll.print_all();
    
    ll.push_front(100);
    ll.push_back(400);
    ll.print_all();
    ll.print_reverse();
    
	return 0;
}