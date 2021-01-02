#include<iostream>
using namespace std;

struct DoublyLinkedList{
    int value;
    DoublyLinkedList* previous ;
    DoublyLinkedList* next;
    DoublyLinkedList(){
        previous = nullptr;
        next = nullptr;
    }
};

void InsertNode(DoublyLinkedList* &head,int data, int position)
{
    DoublyLinkedList* pointer = head;
    DoublyLinkedList* previous_pointer = nullptr;
    int pointer_position = 0;
    
    DoublyLinkedList* new_node = new DoublyLinkedList();
    new_node->value = data;

    if(!new_node)
    {
        std::cout<<"Memory not allocated";
    }
    if(position==0){
        if(head==nullptr){
            head = new_node;
        }
        else{
            new_node->next = pointer;
            pointer->previous = new_node;
            head = new_node;
        }
    }
    else{
        while(pointer!=nullptr && pointer_position<position){
            pointer_position++;
            previous_pointer = pointer;
            pointer= pointer->next;
        }
        if(pointer == nullptr){
            previous_pointer->next = new_node;
            new_node ->previous = previous_pointer;
        }
        else 
        {
        previous_pointer->next = new_node;
        new_node ->previous = previous_pointer;

        new_node->next = pointer;
        pointer->previous = new_node;
        }
    }
}

int length(DoublyLinkedList* head)
{
    DoublyLinkedList* pointer = head;
    int length = 0;
    while(pointer!=nullptr){
        length++;
        pointer = pointer->next;
    }
    return length;
}

void print(DoublyLinkedList* head)
{
    DoublyLinkedList* pointer = head;
    while(pointer!= nullptr)
    {
        cout<<pointer->value;
        pointer = pointer->next;
    }
}

void print_reverse(DoublyLinkedList* head){
    DoublyLinkedList* pointer = head;
    while(pointer!=nullptr)
        pointer = pointer->next;
    
    while(pointer->previous!=nullptr)
    {
        cout<<pointer->value;
        pointer = pointer->previous;
    }
}

void deletedll(DoublyLinkedList* &head, int position)
{
    DoublyLinkedList* pointer = head;
    DoublyLinkedList* previous_pointer = nullptr;
    int pointer_position = 0;

    if(position==0)
    {
        if(pointer== nullptr)
        {
            cout<<"List empty";
        }
        else
        {
            pointer = pointer->next;
            head = pointer;
        }
    }
    else
    {
        while(pointer!=nullptr && pointer_position < position)
        {
            pointer_position++;
            previous_pointer = pointer;
            pointer = pointer->next;
        }
        if(pointer == nullptr)
        {
            cout<<"Out of memory";
        }
        else
        {
            previous_pointer = pointer->next;
            pointer = pointer ->next;
            pointer->previous = previous_pointer;
        }
    }
    
}

int main()
{   
    DoublyLinkedList* node = new DoublyLinkedList();
    node->value = 0;
    InsertNode(node,1,0);
    InsertNode(node,2,2);
    print(node);
    cout<<length(node);
    deletedll(node,1);
    print(node);
    return 0;
}