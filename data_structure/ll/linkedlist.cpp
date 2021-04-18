#include "linkedlist.hpp"

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

void    LinkedList::deleteNode(Node* &node) {
    delete node;
    node = nullptr;
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
    if(index > size())
        return -999;
    int current_size = 0;
    Node* current = root;
    while(current_size != index)
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
        return;
    }
    if(index == 0)
        return pushFront(value);

    int position = 0;
    Node* current = root;
    while(position < index && current->next != nullptr )
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
    if(isEmpty() || index < 0)
        return;
    if(index == 0)
    {
        return popFront();
    }
    Node* current = root;
    Node* previous = nullptr;
    int position = 0;
    while(position < index && current->next != nullptr )
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
    Node* previous = nullptr;
    Node* current = root;
    Node* next = nullptr;
    while(current != nullptr)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    root = previous;

}

void    LinkedList::removeByValue(int value) {
    // removes first occurance
    Node* current = root;
    Node* previous = nullptr;
    int poistion = 0;

    while(current->next != nullptr && current->value != value )
    {
        previous = current;
        current = current->next;
        poistion++;
    }

    if(current->value != value)
        return;
    else
        erase(poistion);
}

void    LinkedList::removeDuplicate() {
    std::unordered_map<int,int> map;
    Node* current = root;
    int position =0;
    while(current != nullptr)
    {
        if(map[current->value])
            erase(position);
        else
        {
            map[current->value]++;
        }
        current = current->next;
        position++;
    }
}

bool    LinkedList::isPallindrome() {
    std::stack<int> stack_values;
    Node* slow = root;
    Node* fast = root;

    while(fast!=nullptr && fast->next != nullptr && fast->next->next!= nullptr )
    {
        stack_values.push(slow->value);
        slow = slow->next;
        fast = fast->next->next;
    }

    while(slow != nullptr)
    {
        if(stack_values.top() != slow->value)
            return false;
        stack_values.pop();
        slow = slow->next;     
    }
    return true;

}

bool    LinkedList::isCyclic() {
    Node* slow = root;
    Node* fast = root;

    fast = fast->next->next;
    while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr && slow !=fast)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast == nullptr || fast->next == nullptr || fast->next->next == nullptr)
        return false;
    return true;
}
}

