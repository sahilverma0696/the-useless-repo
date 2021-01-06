#include<iostream>

struct node {
public:
    int data;
    node* next;
    node* previous;

    node(int value)
    {   
        data = value;
        next = this;
        previous = this;
    }
};


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
        while(pointer!=head && pointer_position<position)
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

int main()
{

node* head = new node(0);


InsertNode(head,1,1);
InsertNode(head,2,2);
InsertNode(head,3,3);
InsertNode(head,5,2);

return 0;
}