#include<iostream>
#include<string>
#include<vector>
using namespace std;
//BST binary search tree(이진탐색트리) : 일종의 자료구조 , 계층적 구조를 표현하는 것이 아닌 자료의 효율적인 관리
// 왼쪽 섭트리 < 노드 키값 < 오른쪽 섭트리 -> 중위 순회하면 오름차순으로 정렬된 값을 얻을 수 있음
// 자료의 탐색 삽입 삭제 모두 O(logn)

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int key) : data(key), left(nullptr), right(nullptr)
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
class BinarySearchTree
{
private:
    Node* root = nullptr;

    void insert_impl(Node* curr, int value)
    {
        if(value < curr->data)
        {
            if(curr->left == nullptr)
                curr->left = new Node(value);
            else
                insert_impl(curr->left, value);
        }
        else
        {
            if(curr->right == nullptr)
                curr->right = new Node(value);
            else
                insert_impl(curr->right, value);
        }
    }
    Node* erase_impl(Node* node, int value)
    {
        if(node == nullptr)
            return nullptr;
        if(value < node->data)
        {
            node->left = erase_impl(node->left, value);
        }
        else if(value > node->data)
        {
            node->right = erase_impl(node->right, value);
        }
        else // value == node->data인 경우
        {
            if(node->left && node->right)//자식이 둘다 있는 경우
            {
                auto succ = successor(node);//value보다 바로 다음으로 큰 것
                node->data = succ->data;
                node->right = erase_impl(node->right, succ->data);
            }
            else
            {
                auto tmp = node->left ? node->left : node->right;
                delete node;
                return tmp;
            }
        }
        return node;
    }
    Node* successor(Node* node)//node의 자식이 둘다 있는 경우에만 실행됨, node의 succesor를 찾음
    {
        auto curr = node->right;
        while(curr && curr->left)
            curr = curr->left;
        return curr;    
    }
    Node* find_impl(Node* curr, int value)
    {
        if(curr == nullptr)
            return nullptr;

        if(value == curr->data)
            return curr;
        else
        {
            if(value < curr->data)
                return find_impl(curr->left, value);
            else
                return find_impl(curr->right, value);
        }
    }
    void inorder_impl(Node* curr)
    {
        if(curr != nullptr)
        {
            inorder_impl(curr->left);
            cout<<curr->data<<" ";
            inorder_impl(curr->right);
        }
        
    }
public:
    ~BinarySearchTree(){ delete_tree(root); };
    void insert(int value)
    {
        if(!root) // when root is null, allocate first Node
            root = new Node(value);
        else
            insert_impl(root, value);
    }
    Node* find(int value)
    {
        return find_impl(root, value);
    }
    void inorder()
    {
        inorder_impl(root);
    }
    void erase(int value)
    {
        root = erase_impl(root, value);
    }
};


int main()
{
    BinarySearchTree bst;
    
    bst.insert(10);
    bst.insert(14);
    bst.insert(5);
    bst.insert(7);
    bst.insert(18);
    bst.insert(4);
    bst.insert(6);
    bst.insert(20);
    bst.insert(16);
    bst.inorder(); cout<<endl; //오름차순 순서로 출력

    if(bst.find(7))
        cout<<"7 is found"<<endl;
    else
        cout<<"7 is not found"<<endl;
    
    if(bst.find(15))
        cout<<"15 is found"<<endl;
    else
        cout<<"15 is not found"<<endl;

    bst.insert(9);
    bst.insert(12);
    bst.inorder(); cout<<endl;

    bst.erase(4);
    bst.erase(5);
    bst.erase(14);
    bst.inorder(); cout<<endl;

    bst.insert(15);
    bst.erase(10);
    bst.inorder(); cout<<endl;


    return 0;
}