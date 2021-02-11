#include<bits/stdc++.h>
using namespace std;


void oneHit(string current, vector<string> &path,vector<string> & oneHit)
{
    // check current vs path: the words which can be made from path: fill in oneHit
}
int wordLadder(string start, string end, vector<string> &path)
{
    vector<string>::iterator itr = path.begin();
    if(find(path.begin(), path.end(),end)!=path.end())
        return -1;

    vector<string> queue;
    queue.push_back(start);
    while(!queue.empty())
    {
        string current_string = queue.back();queue.pop_back();
        
    }
    return -1;
}


int main()
{
    string start = "hit";
    string end = "cog";
    vector<string> paths {"hot","dot","dog","lot","log"};

	return 0;
}