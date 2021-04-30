#include<bits/stdc++.h>

using namespace std;

void make_graph(vector<int>* &graph, int capacity)
{
    graph = new vector<int>[capacity];
}

void insert(vector<int>* &graph, int from, int to, bool bidirectional = true) {
    graph[from].push_back(to);
    if(bidirectional)
        graph[to].push_back(from);
}

void print_adjacency(vector<int>* &graph, int capacity)
{
    for(int i = 1; i <capacity;i++)
    {
        cout<<"Node "<<i<<"{\n";
        for(int j = 0; j<graph[i].size();j++)
        {
            cout<<"\t"<<graph[i][j]<<"\n";
        }
        cout<<"}\n";
    }
}

void bfs_print(vector<int>* &graph,int start,int capacity) {
    bool visited[capacity] = {false};

    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int node = q.front();q.pop();
        
        cout<<"Node\t"<<node<<"\n";
        for(auto part:graph[node])
        {
            if(!visited[part]) {
                visited[part] = true;
                q.push(part);
            }
        }
    }
}

void __dfs_print__(vector<int>* &graph,int node, bool visited[]) {

    visited[node] = true;
    cout<<"Node\t"<<node<<"\n";

    for(auto part:graph[node]) {
        if(!visited[part])
            __dfs_print__(graph,part,visited);
    }
}

void dfs_print(vector<int>* &graph,int start, int capacity){
    bool visited[capacity] = {false};

    __dfs_print__(graph,start,visited);
}

bool __check_cyclic__(vector<int>* &graph,int node, int parent, bool visited[]) {
    visited[node] = true;

    for(auto part: graph[node]) {
        if(!visited[part])
            if(__check_cyclic__(graph,part,node,visited))
                return true;
        else if(node != parent)
            return true;
    }
    return false;
}

bool check_cyclic(vector<int>* &graph, int capacity, int start = 1) {

    bool visited[capacity] = {false};
    return __check_cyclic__(graph,start,start,visited);

}

bool __ccd__(vector<int>* &graph, int start,bool ancestor[], bool visited[]) {
    visited[start] = true;
    ancestor[start] = true;

    for( auto part: graph[start]) {
        if(!visited[part] && __ccd__(graph,part,ancestor,visited))
                return true;
        else if(ancestor[part])
            return true;
    }
    ancestor[start] = false;
    return false;
}

bool check_cyclic_directed(vector<int>* &graph, int capacity) {
    bool visited[capacity] = {false};
    bool ancestor[capacity] = {false};
    
    for(int i = 0; i <capacity;i++)
    {
        if(!visited[i])
            if(__ccd__(graph,i,ancestor,visited));
                return true;
    }
    return false;
}

void __t_s__(vector<int>* &graph, vector<int> &result,int start,bool visited[]) {
    visited[start] = true;
    for(int i = 0; i < graph[start].size();i++)
    {
        int new_node = graph[start][i];
        if(!visited[new_node])
        {
            __t_s__(graph,result,new_node,visited);
        }
    }
    result.push_back(start);

}

vector<int> topological_sorting(vector<int>* &graph, int start, int capacity) {
    vector<int> result;
    bool visited[capacity] = { false };

    for(int i = 0; i <capacity;i++)
    {
        if(!visited[i])
            __t_s__(graph,result,i,visited);
    }
    
    return result;
}
int main() {
    // int capacity  = 5;
    // vector<int>* graph = nullptr;
    // make_graph(graph,capacity);
    // insert(graph,1,2);
    // insert(graph,2,3);
    // insert(graph,3,4);
    // insert(graph,4,1);

    // bfs_print(graph,1,capacity);

    // dfs_print(graph,1,capacity);

    // cout<<check_cyclic(graph,capacity,1);

    // print_adjacency(graph,capacity);



    // int capacity = 7;
    // vector<int>* graph_directed = nullptr;
    // make_graph(graph_directed,capacity);

    // insert(graph_directed,1,2,false);
    // insert(graph_directed,2,3,false);
    // insert(graph_directed,3,1,false);
    // insert(graph_directed,3,4,false);
    // insert(graph_directed,4,5,false);
    // insert(graph_directed,4,6,false);
    // insert(graph_directed,6,5,false);

    // // bfs_print(graph_directed,1,capacity);

    // // cout<<check_cyclic_directed(graph_directed,capacity);

    // print_adjacency(graph_directed,capacity);

    int capacity = 6;
    vector<int>* graph_directed = nullptr;
    make_graph(graph_directed,capacity);

    insert(graph_directed,1,2,false);
    insert(graph_directed,1,3,false);
    insert(graph_directed,3,4,false);
    insert(graph_directed,5,4,false);

    vector <int> topological_s = topological_sorting(graph_directed,1,capacity);
    for( int i = 0; i < topological_s.size();i++) {
        cout<<topological_s[i];
    }
    return 0;
}