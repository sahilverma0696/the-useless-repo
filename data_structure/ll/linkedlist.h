#pragma once

namespace ll {
struct Node {
    int value;
    Node* next;
    Node(int value);
    };

class LinkedList {
private:
    Node* node;
public:
            LinkedList(int value);
            ~LinkedList();
    int     size();
    bool    isEmpty();
    int     valueAt();
    void    pushFront();
    int     popFront();
    void    pushBack();
    void    popBack();
    int     front();
    int     back();
    void    insert(int index, int value);
    void    erase(int index);
    int     valueNfromEnd( int n);
    void    reverse();
    void    removeValue(int value);

};
}
