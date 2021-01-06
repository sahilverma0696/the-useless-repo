#include<iostream>

struct node {
public:
    int data; // change to private and make getter setter
    node* next;
    node* previous;

    node(int value)
    {   
        data = value;
        next = this;
        previous = this;
    }
};


int Length(node* head)
{
    node* current_pointer = head;
    int list_length = 0; 
    while(current_pointer->next!=head) // could have done with do while too xD
    {
        list_length++;
        current_pointer = current_pointer->next;
    }
    list_length++;
    return list_length;
}


void Print(node* head)
{
    node* current_pointer = head;
    do
    {
        std::cout<<current_pointer->data<<"->";
        current_pointer = current_pointer->next;
    }
    while(current_pointer!=head);
    std::cout<<"\b\b  \n";

}


void InsertNode(node* &head,int data, int position)
{
    node* new_node = new node(data);
    if(!new_node)
    {
        std::cout<<"Memory not allocated.\n";
    }

    node* previous_pointer = nullptr;
    node* pointer = head;
    int pointer_position = 0;
    
    if(position == 0)
    {
        if(head == nullptr){
            new_node->next=new_node;
            new_node->previous= new_node;
            head = new_node;
        } 
        else
        {
            previous_pointer = head->previous;

            new_node->next = head;
            head->previous = new_node;
            
            new_node->previous = previous_pointer;
            previous_pointer->next = new_node;

            head= new_node;
        }
        
    }
    else
    {
        while(pointer->next!=head && pointer_position<position)
        {   
            pointer_position++;
            previous_pointer = pointer;
            pointer= pointer->next;
        }
        if(pointer==head)
        {
            previous_pointer = pointer->previous;

            previous_pointer->next = new_node;
            new_node->previous = previous_pointer;

            new_node->next = pointer;
            pointer->previous = new_node;
        }
        else
        {
            previous_pointer->next = new_node;
            new_node ->previous =previous_pointer;

            new_node->next = pointer;
            pointer->previous = new_node;
        }
        
    }
    
}


void Delete(node* &head, int position)
{
    node* current_pointer = head;
    node* previous_pointer = nullptr;
    int pointer_position =0;

    if(head==nullptr)
    {
        std::cout<<"List is empty";
    }
    if(position == 0){
        previous_pointer = current_pointer->previous;

        previous_pointer ->next = current_pointer ->next;
        current_pointer ->previous = previous_pointer;

        head = current_pointer->next;
        delete current_pointer;
        current_pointer = nullptr;

    }
    else{
        while(current_pointer->next!=head && pointer_position < position)
        {
            pointer_position++;
            current_pointer = current_pointer->next;
        }
            previous_pointer = current_pointer->previous;
            
            previous_pointer->next = current_pointer->next;
            current_pointer = current_pointer ->next;
            current_pointer->previous = previous_pointer;
            
    }
}


int main()
{

node* head = new node(0);


InsertNode(head,1,1);
InsertNode(head,2,2);
InsertNode(head,3,3);
InsertNode(head,5,1);
Print(head);
std::cout<<Length(head)<<"\n";
Delete(head,2);
Print(head);

return 0;
}