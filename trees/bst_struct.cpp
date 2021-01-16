#include<iostream>

struct Node 
{
    Node* left_child;
    int data;
    Node* right_child;
    Node(int value)
    {
        left_child = nullptr;
        right_child = nullptr;
        data = value;

    }
};

Node* insert(Node* & root,int value)
{
    if(!root)
    {
        return new Node(value);
    }
    if(value>root->data)
    {
        root->right_child = insert(root->right_child, value);
    }
    else
    {
        root->left_child = insert(root->left_child, value);
    }
    return root;
}

int main()
{
    Node* root = new Node(7);
    insert(root,3);
    return 0;
}