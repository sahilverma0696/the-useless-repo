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

}

int     LinkedList::back() {

}

void    LinkedList::insert(int index, int value) {

}

void    LinkedList::erase(int index) {

}

int     LinkedList::valueNfromEnd( int n) {

}

void    LinkedList::reverse() {

}

void    LinkedList::removeValue(int value) {

}


}