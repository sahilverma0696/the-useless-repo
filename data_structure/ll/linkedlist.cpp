#include"linkedlist.h"

namespace ll{

Node::Node(int value) {
    this->value = value;
    next = nullptr;
}


LinkedList::LinkedList(int value) {
    root = new Node(value);
}

LinkedList::~LinkedList() {

}

int     LinkedList::size() {
    Node* current  = root;
    int size = 0;
    while(current != nullptr)
    {
        size++;
        current  = current->next;
    }
    return size;
}

bool    LinkedList::isEmpty() {
    return root == nullptr ? true:false;
}

int     LinkedList::valueAt(int index) {
    int current_size = 0;
    Node* current = root;
    while(current != nullptr || current_size != index)
    {
        current = current->next;
        current_size++;
    }
    int result = current->value;
    current = nullptr;
    return result;


}

void    LinkedList::pushFront(int value) {
    Node* new_node = new Node(value);
    new_node->next = root;
    root = new_node;
}

void     LinkedList::popFront() {
    if(isEmpty())
        return;
    Node* current = root->next;
    deleteNode(root);
    root = current;

}

void    LinkedList::pushBack(int value ) {
    Node* new_node = new Node(value);
    Node* current = root;
    while(current->next != nullptr)
    {
        current = current->next;
    }
    current->next = new_node;
    current = nullptr;

}

void    LinkedList::popBack() {
    if(isEmpty())
        return;
    Node* current = root;
    while(current->next->next != nullptr)
    {
        current = current->next;
    }
    Node* todelete = current->next;
    deleteNode(todelete);
    current ->next =  nullptr;


}

int     LinkedList::front() {

    if(isEmpty())
        return -999;
    return root->value;
}

int     LinkedList::back() {
    if(isEmpty())
        return -999;
    Node* current = root;
    while(current->next != nullptr)
        current = current->next;
    return current->value;
}

void    LinkedList::insert(int index, int value) {

    if(isEmpty())
    {
        root->value;
        return;
    }
    int position = 0;
    Node* current = root;
    while(current->next != nullptr || position != index)
    {
        current = current->next;
        position++;
    }
    if(current->next == nullptr)
    {
        current->next = new Node(value);
    }
    else{
        Node* next = current->next;
        current->next = new Node(value);
        current->next->next = next;
    }


}

void    LinkedList::erase(int index) {
    if(isEmpty())
        return;
    Node* current = root;
    Node* previous = nullptr;
    int position = 0;
    while(current->next != nullptr || position != index)
    {
        previous = current;
        current = current->next;
        position++;
    }
    if(current->next == nullptr)
    {
        previous->next = nullptr;
        deleteNode(current);
    }
    else{
        previous->next = current->next;
        deleteNode(current);

    }

}

int     LinkedList::valueNfromEnd( int n) {
    int position = size();
    if(n>position)
        return -999;
    int get_position = position - n;
    return valueAt(get_position);
}

void    LinkedList::reverse() {
    Node* previous = root;
    Node* current = root;
    Node* next = root->next;
    while(next != nullptr)
    {
        current = next;
        next = next->next;
        current->next = previous;
        previous = current;
        
    }

}

void    LinkedList::removeValue(int value) {
    // removes first occurance
    Node* current = root;
    Node* previous = nullptr;

    while(current->value != value || current != nullptr)
    {
        previous = current;
        current = current->next;
    }
    if(current == nullptr)
        return;
    else {
        previous->next = current->next;
        deleteNode(current);
    }
}


}