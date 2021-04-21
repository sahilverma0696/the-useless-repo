#include<bits/stdc++.h>

using namespace std;

void make_graph(vector<pair<int,int>>* &graph, int capacity) {
    graph = new vector<pair<int,int>>[capacity];
}

void insert(vector<pair<int,int>>* &graph,int capacity,int source,int destination,int weight,bool bidirectional = false) {
    if(source>capacity || destination > capacity)
        return;
    graph[source].push_back(make_pair(destination,weight));
    if(bidirectional)
        graph[destination].push_back(make_pair(source,weight));
}

void print_adjacency(vector<pair<int,int>>* graph, int capacity) {
    if(capacity == 0)
        return;

    for(int i = 0; i<capacity;i++) {
        cout<<"Node "<<i<<" {\n";
        for(int j = 0; j<graph[i].size();j++)
        {
            cout<<"\t"<<graph[i][j].first<<" : "<<graph[i][j].second<<"\n";
        }
        cout<<"}\n\n";
    }
}


void bfs_print(vector<pair<int,int>>* graph, int capacity,int start) {
    bool visited[capacity] = {false};
    queue<int> q;

    q.push(start);

    while(!q.empty()) {
        int node = q.front();q.pop();
        cout<<"Node : "<<node<<"\n";
        for(int i = 0; i <graph[node].size();i++)
        {
            int new_node = graph[node][i].first;
            if(!visited[new_node])
            {
                visited[new_node] = true;
                q.push(new_node);
            }
        }
    }
}
void __dfs_print__(vector<pair<int,int>>* graph, int node, bool visited[]) {
    visited[node] = true;
    cout<<"Node : "<<node<<"\n";

    for( int i = 0; i<graph[node].size();i++)
    {
        int new_node = graph[node][i].first;
        if(!visited[new_node])
        {
            __dfs_print__(graph,new_node,visited);
        }
    }
}
void dfs_print(vector<pair<int,int>>* graph, int capacity)
{
    bool visited[capacity] = {false};

    for( int i = 0; i <capacity;i++)
    {
        if(!visited[i])
    {
        visited[i] = true;
        __dfs_print__(graph,i,visited);
    }
    }
}

int main() {

    int capacity = 7;
    vector<pair<int,int>>* graph = nullptr;
    make_graph(graph,capacity);
    insert(graph,capacity,0,1,3);
    insert(graph,capacity,0,2,5);
    insert(graph,capacity,1,2,7);
    insert(graph,capacity,2,3,1);
    insert(graph,capacity,2,4,5);
    insert(graph,capacity,3,5,2);
    insert(graph,capacity,3,4,9);
    insert(graph,capacity,4,5,1);
    insert(graph,capacity,4,6,2);
    insert(graph,capacity,5,6,8);
    

    // print_adjacency(graph,capacity);
    // bfs_print(graph,capacity,0);
    dfs_print(graph,capacity);
    return 0;


}