#include<bits/stdc++.h>


struct Node {
    Node* left;
    int data;
    Node* right;
    Node(){
        left = nullptr;
        data = 0;
        right = nullptr;
    }
};


void insert(Node* &root, int root_value)
{
    Node* current = nullptr;
    std::queue <Node*> que;
    root->data = root_value;
    std::cout<<"Root value inserted\n";
    que.push(root);
    while(!que.empty())
    {
        current = que.front();que.pop();

        if(current->left == nullptr)
        {
            int value = 0;
            std::cout<<"Enter the left child value of parent:\t"<<current->data<<"\t:";
            std::cin>>value;
            if(value != -1)
            {
                current->left = new Node();
                current->left->data = value;
                std::cout<<"Left child inserted\n";
                que.push((current->left));
            }
        }
        
        
        if(current->right == nullptr)
        {
            int value = 0;
            std::cout<<"Enter the right child value of parent:\t"<<current->data<<"\t:";
            std::cin>>value;
            if(value != -1)
            {
                current->right = new Node();
                (current->right)->data = value;
                std::cout<<"Right child inserted\n";
                que.push(current->right);
            }
        }
        
    }
}
void print_pre_order(Node* node)
{
    if(node != nullptr)
    {
        std::cout<<node->data<<"\n";
        print_pre_order(node->left);
        print_pre_order(node->right);

    }
}
void print_in_order(Node* node)
{
    if(node != nullptr)
    {
        
        print_in_order(node->left);
        std::cout<<node->data<<"\n";
        print_in_order(node->right);

    }
}
void print_post_order(Node* node)
{
    if(node != nullptr)
    {
        
        print_post_order(node->left);
        print_post_order(node->right);
        std::cout<<node->data<<"\n";

    }
}

int main()
{
    Node* root = new Node();
    insert(root,1);
    print_pre_order(root);
    std::cout<<"\n";
    print_in_order(root);
    std::cout<<"\n";
    print_post_order(root);
    std::cout<<"\n";
    return 0;
}