#include<iostream>
#include<vector>

namespace bst
{

struct Node
{
    Node* left;
    int val;
    Node* right;
    Node();
};

Node::Node()
{
    left = nullptr;
    val = -999;
    right = nullptr;
}


void print_preorder(Node* root);
void insert(Node* &root, std::vector<int>values);
void __insert_helper__(Node* &root,int value);

void insert_iterative(Node* &root, std::vector<int>values);
void __insert_itr_helper__(Node* &root,int value);

void insert(Node* &root, std::vector<int>values)
{
    for(int i = 0;i < values.size();i++)
        __insert_helper__(root,values[i]);
}

void __insert_helper__(Node* &root, int value)
{
    if(root == nullptr)
    {
        root = new Node();
        root->val = value;
    }
    if(root->val < value)
        __insert_helper__(root->right,value);
    if(root->val >value)
        __insert_helper__(root->left,value); 
}

void insert_iterative(Node* &root, std::vector<int>values)
{
    if(values.size() == 0)
        return;
    for(int i = 0;i < values.size();i++)
        __insert_itr_helper__(root,values[i]);
}
void __insert_itr_helper__(Node* &root,int value)
{
    Node* current  = root;
    if(root == nullptr)
        {
            root = new Node();
            root->val = value;
            return;
        }
    while(true)
    {
        if(current->val < value)
        {
            if(current->right!= nullptr)
                current = current->right;
            else
            {
            current->right = new Node();
                current->right->val = value;
                break;
            }
        }
        else
        {
            if(current->left != nullptr)
                current = current->left;
            else
            {
                current->left = new Node();
                current->left->val = value;
                break;
            }
        }
        
    }
}

void print_preorder(Node* root)
{
    if(root != nullptr)
    {
        std::cout<<root->val;
        print_preorder(root->left);
        print_preorder(root->right);
    }
}
}

using namespace bst;

int main()
{
    std::vector<int> values  {1,2,3,4,5,6,7};
    Node* root = nullptr;
    insert_iterative(root,values);
    //__insert_itr_helper__(root,5);
    print_preorder(root);

    return 0;
}

