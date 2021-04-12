#pragma once

namespace ll {
struct Node {
    int value;
    Node* next;
    Node(int value);
    };

class LinkedList {
private:
    Node* root;
    void deleteNode(Node* &node);
public:
            LinkedList(int value);
            ~LinkedList();
    int     size();
    bool    isEmpty();
    int     valueAt( int index);
    void    pushFront(int value);
    void    popFront();
    void    pushBack(int value);
    void    popBack();
    int     front();
    int     back();
    void    insert(int index, int value);
    void    erase(int index);
    int     valueNfromEnd( int n);
    void    reverse();
    void    removeByValue(int value);

};

}