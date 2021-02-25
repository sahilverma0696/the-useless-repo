#include<vector>
#include<iostream>

namespace dll
{

struct Node
{
    Node* previous;
    int val;
    Node* next;
    Node();
};

Node::Node()
{
    previous = nullptr;
    val = -999;
    next = nullptr;
}

void insert_tail(Node* &tail,int value);

void makeDLL(Node* &root, std::vector<int> &values)
{
    if(root == nullptr)
        return;
    Node* tail = new Node();
    root->next = tail;
    tail->previous = root;

    for(int i = 0; i<values.size();i++)
        insert_tail(tail,values[i]);

}

void insert_tail(Node* &tail,int value)
{
    if(tail->previous == nullptr)
        return;
    
    Node* new_node = new Node();
    new_node->val = value;
    Node* previous = tail->previous;

    previous->next = new_node;
    new_node->previous = previous;
    new_node->next = tail;

    tail->previous = new_node;
}

void print_dll(Node* root)
{
    if(root == nullptr)
        return;
    
    Node* current = root->next;
    while(current->val!= -999)
    {
        std::cout<<current->val;
        current = current->next;
    }
}


}

using namespace dll;
int main()
{   
    std::vector<int> values {1,2,3,4,5,6,7,8,9};
    Node* root = new Node();
    makeDLL(root,values);
    print_dll(root);
    return 0;
}
