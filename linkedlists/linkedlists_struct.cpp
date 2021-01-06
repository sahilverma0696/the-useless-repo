#include<iostream>
using namespace std;


struct SinglyLinkedList{
    int value;
    SinglyLinkedList* next;
    SinglyLinkedList(int x):value(x),next(nullptr){};

};

int listlength(SinglyLinkedList *head){
    int count =0;
    SinglyLinkedList* pointer = head;
    while(pointer!=nullptr){
        count++;
        pointer = pointer->next;
    }
    return count;
}

void insertNode(SinglyLinkedList* &head, int data, int position){
    SinglyLinkedList* pointer = head;

    SinglyLinkedList* new_node = new SinglyLinkedList(data);
    int pointer_pos = 0;
    SinglyLinkedList* previous_pointer = nullptr;
    if(!new_node){
        cout<<"memory error";
    }
    else if(position == 0){
        new_node->next = pointer;
        head = new_node;
    }
    else {
        while(pointer!=nullptr && pointer_pos < position){
            pointer_pos++;
            previous_pointer = pointer;
            pointer = pointer->next;
        }
        previous_pointer->next = new_node;
        new_node->next = pointer;

    }
}

void printNodes(SinglyLinkedList* head)
{
    SinglyLinkedList* pointer = head;
    while(pointer!=nullptr){
        cout<<pointer->value<<"->";
        pointer= pointer->next;
    }
    cout<<"\n";
}
void deleteNode(SinglyLinkedList* &head, int position){
    SinglyLinkedList* pointer = head;
    SinglyLinkedList* previous_pointer = nullptr;
    int pointer_position = 0;
    if(position==0){
        head=head->next;
    }
    else{
        while(pointer!=nullptr && pointer_position < position){
            pointer_position++;
            previous_pointer = pointer;
            pointer = pointer->next;
        }
        if(pointer==nullptr){
            cout<<"Position does not exist\n";
        }
        else
            previous_pointer ->next= pointer->next;
    }

}
// Floyd's cycle detection

bool cycle_detection(SinglyLinkedList* head)
{
    SinglyLinkedList* slow_pointer = head;
    SinglyLinkedList* fast_pointer = head;
    if(head == nullptr)
    {
        return false;
    }
    for(;;)
    {   
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next;
        if(fast_pointer == nullptr || slow_pointer == nullptr)
            return false;
        else
            fast_pointer = fast_pointer->next;
        if(slow_pointer == fast_pointer)
        {
            return true;
        }
        if(fast_pointer == nullptr || slow_pointer == nullptr)
            return false;
    }
}


int main()
{
    SinglyLinkedList* node = new SinglyLinkedList(5);
    

    //cout<<listlength(node)<<"\n";
    printNodes(node);
    insertNode(node,6,1);
    insertNode(node,7,2);
    insertNode(node,8,3);
    insertNode(node,9,4);

    //cout<<listlength(node)<<"\n";
    printNodes(node);
    deleteNode(node,2);
    printNodes(node);
    delete node;
    node=nullptr;
    return 0;
}
