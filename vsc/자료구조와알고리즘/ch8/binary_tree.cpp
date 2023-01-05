#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Node
{
    char data;
    Node* left;
    Node* right;

    Node(char c) : data(c), left(nullptr), right(nullptr)
    {}
};
void delete_tree(Node* node)
{
    if(node)
    {
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    }
}
int main()
{
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('F');

    //메모리 해제..!!
    //이진 트리 삭제 -> 후위 순회 방식을 따름... 1.왼쪽 섭트리 2.오른쪽 섭트리 3.자기자신

    

    return 0;
}