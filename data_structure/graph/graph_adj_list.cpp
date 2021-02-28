#include<iostream>
#include<vector>
#include<queue>

namespace graph{
void insert_graph(std::vector<int>* node, int from, int to,bool bi_dir);
void print_list(std::vector<int>* node, int capacity);
void breadth_first_printing(std::vector<int>* node, int starting_node, int capacity);

void insert_graph(std::vector<int>* node, int from, int to, bool bi_dir = false)
{
    if(node == nullptr)
    {
        int capacity;
        std::cout<<"Enter the capacity of the graph";
        std::cin>>capacity;
        node = new std::vector<int>[capacity];
    }
    node[from].push_back(to);
    if(bi_dir == true)
        node[to].push_back(from);
}

void print_list(std::vector<int>* node, int capacity)
{
    if(node ==  nullptr)
        return;
    for( int i = 0;i<capacity;i++)
    {
        std::cout<<i<<"->\t";
        for(int val:node[i])
            std::cout<<val;
        std::cout<<"\n";
    }
}

void breadth_first_printing(std::vector<int>* node, int starting_node, int capacity)
{
    int visited[capacity] = {0};
    std::queue<int> q;
    q.push(starting_node);
    int current_node;
    int i =0;
    std::cout<<starting_node;
    visited[starting_node] = 1;
    while(!q.empty())
    {
        current_node = q.front();q.pop();
        for(i = 0;i<node[current_node].size();i++)
        {
            std::cout<<node[current_node][i];
            if(visited[current_node] == 0)
            {
                q.push(node[current_node][i]);
                visited[current_node] = 1;
            }
        }
    }
}
}
using namespace graph;

int main()
{
    int capacity;
    std::cout<<"Enter the total number of nodes";
    std::cin>>capacity;
    std::vector<int>* graph = nullptr;
    if(capacity>0)
        graph= new std::vector<int>[capacity];
    for(int i =0; i<capacity;i++)
        insert_graph(graph,i,capacity-i);
    print_list(graph,capacity);
    std::cout<<"\n";
    breadth_first_printing(graph,1,capacity);
    return 0;
}