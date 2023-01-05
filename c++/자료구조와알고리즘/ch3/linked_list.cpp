#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
class LinkedList
{
private:
    Node* head;
public:
    LinkedList() :head(NULL)
    {}
    ~LinkedList()
    {
        while(!empty())
        {
            pop_front();
        }
    }
    void push_front(int val)
    {
        Node* new_node = new Node {val, head};
        if (head != NULL)
            new_node->next = head;
        head = new_node;
    }
    void pop_front()
    {
        if(head == NULL)
            return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void print_all()
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<", ";
            temp = temp->next;
        }
        cout<<endl;
    }
    bool empty()
    {
        return head == NULL;
    }
};
int main()
{
    LinkedList ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.print_all();
    
    ll.pop_front();
    ll.print_all();
    
    return 0;
}