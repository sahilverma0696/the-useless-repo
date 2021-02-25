#include<iostream>
#include<queue>
#include<stack>
#include<map>

#include"../dll/dll.cpp"


namespace binary_tree
{

struct Node
{
    Node* left;
    int val;
    Node* right;
    Node();
};

//prototypes
void    insert_node         (Node* root);
void    insert_node         (Node* root,std::queue<int> values);
void    print_preorder      (Node* node);
void    print_inorder       (Node* node);
void    print_postorder     (Node* node);
void    depth_first_print   (Node* root);
void    breadth_first_print (Node* root);
void    print_leaf_nodes    (Node* root);
int     count_leaf_nodes    (Node* root);
void    top_view            (Node* root);
void    __top_view_helper__ (Node* root,std::map<int,int> &map,int h_dist);
void    bottom_view         (Node* root);
void    __bottom_view_helper__(Node* root, std::map<int,int> &map, int h_dist);
void    left_view           (Node* root);
void    right_view          (Node* root);
dll::   dll_end_points* binary_tree_to_dll(Node* root);
void    delete_node         (Node* &root, int value);// have to complete
int     getLevel            (Node* root);
int     getHeight           (Node* root);
int     getEdges            (Node* root);
Node*   getLastNode         (Node* root);

Node::  Node()
{
    left = nullptr;
    right = nullptr;
    val = 0;
}
void    insert_node         (Node* root)
{
    if(root == nullptr)
        return;

    std::queue<Node*> q;
    Node* current = nullptr;

    q.push(root);
    std::cout<<"Enter -1 for empty value.\n";
    if(root->val == 0)
    {
        std::cout<<"Enter the value of root\t";
        std::cin>>root->val;
    }
    int value =0;
    while(!q.empty())
    {
        current = q.front();q.pop();
        if(current->left == nullptr)
        {
            std::cout<<"Enter the value of left child for\t"<<current->val<<"\t";
            std::cin>>value;
            if(value!=-1)
            {
                current->left = new Node();
                current->left->val=value;
                q.push(current->left);
            }
        }
        if(current->right == nullptr)
        {
            std::cout<<"Enter the value of right child for\t"<<current->val<<"\t";
            std::cin>>value;
            if(value!=-1)
            {
                current->right = new Node();
                current->right->val=value;
                q.push(current->right);
            }
        }
    }

}

void    insert_node         (Node* root,std::queue<int> values)
{
    if(root == nullptr && values.empty())
        return;

    std::queue<Node*> q;
    Node* current = root;
    root->val = values.front();values.pop();
    q.push(current);

    while(!q.empty())
    {
        current = q.front();q.pop();
        if(values.empty()) break;
        current->left = new Node();
        current->left->val = values.front();values.pop();
        q.push(current->left);
        if(values.empty()) break;
        current->right = new Node();
        current->right->val = values.front();values.pop();
        q.push(current->right);
    }

}
void    print_preorder      (Node* node)
{
    if(node!= nullptr)
    {
        std::cout<<node->val;
        print_preorder(node->left);
        print_preorder(node->right);
    }
}

void    print_inorder       (Node* node)
{
    if(node!=nullptr)
    {
        print_inorder(node->left);
        std::cout<<node->val;
        print_inorder(node->right);
    }
}

void    print_postorder     (Node* node)
{
    if(node!= nullptr)
    {
        print_postorder(node->left);
        print_postorder(node->right);
        std::cout<<node->val;
    }
}

void    depth_first_print   (Node* root)
{
    Node* current = root;
    std::stack<Node*> stack_dfs;
    while(!stack_dfs.empty() || current!= nullptr)
    {
        while(current!= nullptr)
        {
            stack_dfs.push(current);
            current = current->left;
        }
        current = stack_dfs.top(); stack_dfs.pop();
        std::cout<<current->val;
        current = current->right;
    }
    std::cout<<"\n";

}

void    breadth_first_print (Node* root)
{
    if(root == nullptr)
    return;

    std::queue<Node*> q;
    Node* current = nullptr;

    q.push(root);
    while(!q.empty())
    {
        current = q.front();q.pop();

        std::cout<<current->val;
        if(current->left!=nullptr)
            q.push(current->left);
        if(current->right!=nullptr)
            q.push(current->right);
    }
    std::cout<<"\n";
}


void    print_leaf_nodes    (Node* root)
{   
    if(root->left == nullptr && root->right == nullptr)
    {
        std::cout<<root->val;
        return;
    }
    print_leaf_nodes(root->left);
    print_leaf_nodes(root->right);

}

int     count_leaf_nodes    (Node* root)
{
    if(root->left  == nullptr || root->right == nullptr)
        return 1;
    
    return count_leaf_nodes(root->left) + count_leaf_nodes(root->right);
}

void    top_view            (Node* root)
{
    if(root == nullptr)
        return;

    std::map<int,int> map;
    __top_view_helper__(root,map,0);
    std::cout<<"\n";
    for(std::map<int,int>::iterator itr = map.begin();itr!=map.end();itr++)
        std::cout<<itr->second<<" ";
    std::cout<<"\n";
}

void    __top_view_helper__ (Node* root,std::map<int,int> &map,int h_dist)
{
    if(root == nullptr)
        return;
    if(!map[h_dist])
        map[h_dist] = root->val;
    __top_view_helper__(root->right,map,h_dist +1);
    __top_view_helper__(root->left,map,h_dist -1);
    
}

void    bottom_view         (Node* root)
{   if(root == nullptr)
    return;

    std::map<int,int>map;
    __bottom_view_helper__(root,map,0);
        for(std::map<int,int>::iterator itr = map.begin();itr!=map.end();itr++)
        std::cout<<itr->second<<" ";
    std::cout<<"\n";
}
void    __bottom_view_helper__(Node* root, std::map<int,int> &map, int h_dist)
{
    if(root == nullptr)
        return;
    map[h_dist] = root->val;

    __bottom_view_helper__(root->left,map,h_dist -1);
    __bottom_view_helper__(root->right,map,h_dist +1);
}
void    left_view           (Node* root)
{
    if(root == nullptr)
        return;
    std::queue<Node*> q;
    q.push(root);
    Node* current = nullptr;
    while(!q.empty())
    {
        int size = q.size();
        for(int i = 0;i<size;i++)
        {
            current = q.front();q.pop();
            if(i == 0)
                std::cout<<current->val;
            if(current->left != nullptr) q.push(current->left);
            if(current->right != nullptr) q.push(current->right);
        }
    }
}
void    right_view          (Node* root)
{
    if(root == nullptr)
        return;
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        for(int i =0; i<size;i++)
        {
            Node* current = q.front();q.pop();
            if(i == size -1)
            {
                std::cout<<current->val;
            }
            if(current->left != nullptr) q.push(current->left);
            if(current->right != nullptr) q.push(current->right);
        }
    }
    std::cout<<"\n";
}

dll::   dll_end_points* binary_tree_to_dll(Node* root)
{
    if(root == nullptr)
        return nullptr;
    
    Node* current = nullptr;
    std::queue<Node*> q;
    dll::dll_end_points* DLL_terminals = dll::emptyDLL();
    q.push(root);
    while(!q.empty())
    {
        current = q.front();q.pop();
        insert_tail(DLL_terminals->tail,current->val);

        if(current->left != nullptr) q.push(current->left);
        if(current->right != nullptr) q.push(current->right);

    }
    return DLL_terminals;

}

void    delete_node         (Node* &root, int value)
{

    return;
}

int     getLevel            (Node* root)
{
    if(root->left == nullptr || root->right == nullptr)
        return 1;

    int left  =1+getLevel(root->left);
    int right =1+getLevel(root->right);

    return (left>right)?left:right;
}

int     getHeight           (Node*root)
{
    if(root->left == nullptr || root->right == nullptr)
        return 0;

    int left  =1+getHeight(root->left);
    int right =1+getHeight(root->right);

    return (left>right)?left:right;
}

int     getEdges            (Node* root)
{
    if(root->left == nullptr && root->right == nullptr)
        return 0;
    
    int left_edges = 1+getEdges(root->left);
    int right_edges = 1+getEdges(root->right);

    return left_edges+right_edges;
}

}

using namespace binary_tree;

int main()
{
    Node* root = new Node();
    std::queue<int> values;

    for(int i = 1; i<8;i++)
        values.push(i);

    insert_node(root,values);
    breadth_first_print(root);
    //depth_first_print(root);

    //print_leaf_nodes(root);
    std::cout<<count_leaf_nodes(root);

    //top_view(root);
    //bottom_view(root);
    //right_view(root);
    //left_view(root);

    //print_preorder(root);
    //std::cout<<"\n";
    //print_inorder(root);
    //std::cout<<"\n";
    //print_postorder(root);
    //std::cout<<"\n";
/*
    dll::dll_end_points* dll = new dll::dll_end_points();
    dll =binary_tree_to_dll(root);
    dll:print_dll(dll->head);
*/
    //std::cout<<getlevel(root);
    //std::cout<<getHeight(root);
    //std::cout<<getEdges(root);



    return 0;
}
