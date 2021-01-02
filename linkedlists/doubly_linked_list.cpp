#include<iostream>

struct DoublyLinkedList{
    int value;
    DoublyLinkedList* previous ;
    DoublyLinkedList* next;
    DoublyLinkedList(){
        previous = nullptr;
        next = nullptr;
    }
};

void insert_node(DoublyLinkedList* &head,int data, int position)
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
    while(pointer!=nullptr)
    {
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
        std::cout<<pointer->value<<"->";
        pointer = pointer->next;
    }
    std::cout<<"\b\b  \n";
    pointer = nullptr;
}

void print_reverse(DoublyLinkedList* head)
{
    DoublyLinkedList* pointer = head;
    while(pointer->next!=nullptr)
        pointer = pointer->next;
    
    while(pointer!=nullptr)
    {
        std::cout<<pointer->value<<"->";
        pointer = pointer->previous;
    }
    std::cout<<"\b\b";
}


void delete_dll(DoublyLinkedList* &head, int position)
{
    DoublyLinkedList* pointer = head;
    DoublyLinkedList* previous_pointer = nullptr;
    int pointer_position = 0;

    if(position==0)
    {
        if(pointer== nullptr)
        {
            std::cout<<"List empty";
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
            std::cout<<"Out of memory";
        }
        else if( pointer->next==nullptr)
        {
            previous_pointer->next = nullptr;
            delete pointer;
            pointer = nullptr;
        }
        else
        {
            previous_pointer->next = pointer->next;
            pointer = pointer ->next;
            pointer->previous = previous_pointer;

        }
    }
    
}

int main()
{   
    DoublyLinkedList* node = new DoublyLinkedList();
    node->value = 1;
    insert_node(node,0,0); // Insert front
    insert_node(node,2,2); // Insert back
    insert_node(node,5,1); // Insert in-between
    print(node);
    std::cout<<length(node)<<"\n";
    delete_dll(node,3);
    print(node);
    print_reverse(node);
    return 0;
}