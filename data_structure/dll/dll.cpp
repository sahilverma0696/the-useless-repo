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
};

struct dll_end_points
{
    Node* head;
    Node* tail;
    dll_end_points();
};

dll_end_points::dll_end_points()
{
    head = nullptr;
    tail = nullptr;
}

dll_end_points* emptyDLL    ();
void    makeDLL             (Node* &root, std::vector<int> &values);
void    insert_tail         (Node* &tail,int value);
void    insert_head         (Node* &root,int value);
void    print_dll           (Node* root);

dll_end_points* emptyDLL    ()
{
    Node* head = new Node();
    Node* tail = new Node();

    head->next = tail;
    tail->previous = head;
    
    dll_end_points* ends = new dll_end_points();
    ends->head = head;
    ends->tail = tail;
    return ends;
}
void    makeDLL             (Node* &root, std::vector<int> &values)
{
    if(root == nullptr)
        return;
    Node* tail = new Node();
    root->next = tail;
    tail->previous = root;

    for(int i = 0; i<values.size();i++)
        insert_tail(tail,values[i]);

}

void    insert_tail         (Node* &tail,int value)
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

void    insert_head         (Node* &root,int value)
{
    if(root == nullptr)
        return;
    Node* next = root->next;
    Node* new_node = new Node();
    new_node->val = value;

    root->next = new_node;
    new_node->previous = root;

    new_node->next = next;
    next->previous = new_node;
}
void    print_dll           (Node* root)
{
    if(root == nullptr)
        return;
    
    Node* current = root->next;
    while(current->val!= -999)
    {
        std::cout<<current->val;
        current = current->next;
    }
    std::cout<<"\n";
}

}

/*
using namespace dll;
int main()
{   
    std::vector<int> values {1,2,3,4,5,6,7,8,9};
    Node* root = new Node();
    makeDLL(root,values);
    print_dll(root);
    insert_head(root,10);
    print_dll(root);
    return 0;
}
*/
