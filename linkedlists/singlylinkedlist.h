#pragma once 
#include<iostream>

struct node
{
    int value;
    node* next;
};

class SinglyLinkedList
{
private:
    node* head;
public:
                SinglyLinkedList    ();
                ~SinglyLinkedList   ();

    void        insertNode          (int value,int position);
    void        deleteNode          (int position);

    int         length              ();
    void        print               ();

};