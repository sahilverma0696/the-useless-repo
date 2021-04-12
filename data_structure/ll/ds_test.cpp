#include<iostream>
#include "linkedlist.hpp"

int main() {
    ll::LinkedList* root = new ll::LinkedList(1);
    root->pushBack(2);
    root->pushBack(2);

    ll::LinkedList* head = root;

    // std::cout<<"SIZE\t"<<head->size()<<"\n";

    // std::cout<<"Value At\t"<<head->valueAt(2)<<"\n";
    // for(int i = 0; i<head->size();i++)
    // {
    //     std::cout<<head->valueAt(i)<<"\t";
    // }
    // std::cout<<"\n";

    // std::cout<<"Is Empty\t"<<head->isEmpty()<<"\n";

    root->pushFront(0);
    root->pushBack(4);

    // for(int i = 0; i<head->size();i++)
    // {
    //     std::cout<<head->valueAt(i)<<"\t";
    // }
    // std::cout<<"\n";

    // root->popFront();
    // root->popBack();

    // for(int i = 0; i<head->size();i++)
    // {
    //     std::cout<<head->valueAt(i)<<"\t";
    // }
    // std::cout<<"\n";

    // std::cout<<"FRONT\t"<<head->front()<<"\n";

    // std::cout<<"BACK\t"<<head->back()<<"\n";

    //  root->insert(1,-1);

    // for(int i = 0; i<head->size();i++)
    // {
    //     std::cout<<head->valueAt(i)<<"\t";
    // }
    // std::cout<<"\n";
    // root->erase(0);

    // std::cout<<"FRONT\t"<<head->front()<<"\n";

    // std::cout<<"Value from N\t"<<head->valueNfromEnd(head->size())<<"\n";

    // root->removeByValue(2);

    // for(int i = 0; i<head->size();i++)
    // {
    //     std::cout<<head->valueAt(i)<<"\t";
    // }
    // std::cout<<"\n";

    root->pushFront(3);
    root->pushFront(3);

    // root->reverse();

    // for(int i = 0; i<head->size();i++)
    // {
    //     std::cout<<head->valueAt(i)<<"\t";
    // }
    // std::cout<<"\n";
    // std::cout<<"Duplicate Checks\n";
    // root->removeDuplicate();

    root->pushFront(5);
    for(int i = 0; i<head->size();i++)
    {
        std::cout<<head->valueAt(i)<<"\t";
    }
    std::cout<<"\n";

    std::cout<<"Pallindrome Check\t"<<root->isPallindrome()<<"\n";

    return 0;
}