#include"singlylinkedlist.h"

SinglyLinkedList::SinglyLinkedList          ()
{
    
}

SinglyLinkedList::~SinglyLinkedList         ()
{
    delete head;
    head = nullptr;

}

void        SinglyLinkedList::insertNode    (int value, int position)
{
    node*   pointer             = head;
    node*   previous_pointer    = nullptr;
    node*   new_node            = new node();
    int     pointer_position    = 0;

    new_node->value = value;

    if(!new_node)
    {
        std::cout<<"Memory not allocated";
    }    
    else if(position == 0)
    {

        if(head == nullptr)
        {
            head = new_node;
        }
        else
        {
            new_node->next = pointer;
            head = new_node;
        }
    }
    else
    {
        while(pointer!=nullptr && pointer_position<position)
        {
            pointer_position++;
            previous_pointer = pointer;
            pointer = pointer->next;
        }
        previous_pointer->next= new_node;
        new_node->next = pointer;
    }
}

void        SinglyLinkedList::deleteNode    (int position)
{
    node*   pointer = head;
    node*   previous_pointer    = nullptr;
    int     pointer_posistion   = 0;

    if(head == nullptr)
    {
        std::cout<<"List is already empty";
    }
    else if( position == 0)
    {
        head = head->next;
        delete pointer;
        pointer = nullptr;
    }
    else
    {
        while(pointer!=nullptr && pointer_posistion<position)
        {
            pointer_posistion++;
            previous_pointer = pointer;
            pointer=pointer->next;
        }
        if(pointer==nullptr)
        {
            std::cout<<"Position out of memeory";
        }
        else
        {
            previous_pointer->next = pointer->next;
            delete pointer;
            pointer = nullptr;
        }
    }
}

int         SinglyLinkedList::length        ()
{
    int     length      = 0;
    node*   pointer     = head;

    while(pointer!=nullptr)
    {
        length++;
        pointer = pointer->next;
    }

    return length;

}

void        SinglyLinkedList::print         ()
{
    node*   pointer     = head;

    while(pointer!=nullptr)
    {
        std::cout<<pointer->value<<"->";
        pointer=pointer->next;
    }
    std::cout<<"\b\b  \n";
    pointer = nullptr;
}

void        SinglyLinkedList::reverse       ()
{
    node* previous = nullptr;
    node* current  = head;
    node* next = nullptr;

    while(current!= nullptr){
   
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
       
    }
    head = previous;

}