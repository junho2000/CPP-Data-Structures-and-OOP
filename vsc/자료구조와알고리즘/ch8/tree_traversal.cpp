#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
// 깊이 우선 탐색 : 전위 중위 후위 순회
// 너비 우선 탐색 : 레벨 순서 순회
struct Node
{
    char data;
    Node* left;
    Node* right;

    Node(char c) : data(c), left(nullptr), right(nullptr)
    {}
};

//preorder traversal(전위 순회) : 1.현재노드 2.왼쪽 서브트리 3.오른쪽 서브트리
void preorder(Node* node)
{
    if(node)
    {
        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
    }
}
//inorder traversal(중위 순회) : 1.왼쪽 서브트리 2.현재노드 3.오른쪽 서브트리
void inorder(Node* node)
{
    if(node)
    {
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
}
//postorder traversal(후위 순회) : 1.왼쪽 서브트리 2.오른쪽 서브트리 3.현재노드
void postorder(Node* node)
{
    if(node)
    {
        postorder(node->left);
        postorder(node->right);
        cout<<node->data<<" ";
    }
}
//levelorder traversal(레벨 순서 순회) : 낮은 레벨에 있는 노드를 모두 방문한 후, 큰 레벨로 이동하여 방문을 반복 큐를 사용
void levelorder(Node* node)
{
    queue<Node*> q;
    q.push(node);
    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}
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

    preorder(root); cout<<endl;
    inorder(root); cout<<endl;
    postorder(root); cout<<endl;
    levelorder(root); cout<<endl;

    delete_tree(root);
    
    return 0;
}