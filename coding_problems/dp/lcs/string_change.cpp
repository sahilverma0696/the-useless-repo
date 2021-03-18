#include<bits/stdc++.h>
using namespace std;

// Given two string, operations INSERT REMOVE,
// find the min number of operations needed to convert one string to other.

int __lca__(string string1,int size1,string string2, int size2,vector<vector<int>> &mem)
{
    if(size1 == 0 || size2 == 0)
        return 0;
    
    if(mem[size1][size2] != -1) return mem[size1-1][size2-1];
    
    if(string1[size1-1] == string2[size2-1])
    {
        mem[size1][size2] = 1+__lca__(string1,size1 -1,string2,size2,mem);
        return mem[size1][size2];
    }
    else
    {
        mem[size1][size2] = max(__lca__(string1,size1-1,string2,size2,mem),__lca__(string1,size1,string2,size2-1,mem));
        return mem[size1][size2];
    }
}

int lca(string input,string output)
{
    int size1 = input.size();
    int size2 = output.size();
    vector<vector<int>> mem(size1+1,vector<int>(size2+1,-1));
    return __lca__(input,input.size(),output,output.size(),mem);
}

vector<int> string_change(string input, string output)
{
    int lcs_length = lca(input,output);
    vector<int> result;
    result.push_back(output.size() - lcs_length);
    result.push_back(input.size() - lcs_length);
    return result;
}
int main()
{
    string output = "heap";
    string input = "pea";
    vector<int> result = string_change(input,output);
    cout<<"Insertion\t"<<result[0]<<"\n";
    cout<<"Deletion\t"<<result[1]<<"\n";
	return 0;
}