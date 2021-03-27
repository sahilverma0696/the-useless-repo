// Detect if two linked lists intersect at any node
// that being two nodes stored in same address space

#include"dll.cpp"
#include<bits/stdc++.h>
using namespace dll;
using namespace std;
bool intersection_detection(Node* &root1,Node* &root2) {
    unordered_map<Node*,int> values;
    Node* pointer = root1;
    while(pointer->next != nullptr)
    {
        values[pointer]++;
        pointer = pointer->next;
    }
    pointer = root2;
    while(pointer != nullptr)
    {
        if(values[pointer])
            return true;
        values[pointer]++;
        pointer = pointer->next;
    }
    return false;
}

int main() {
    vector<int> values1 {1,2,3,4,5,6,7,8,9};
    Node* root1 = new Node();
    makeDLL(root1,values1);

    vector<int> values2 {5,6,7,8,9};
    Node* root2 = new Node();
    makeDLL(root2,values2);

    cout<<intersection_detection(root1,root2);

    return 0;

}