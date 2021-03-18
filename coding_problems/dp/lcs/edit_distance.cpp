#include<bits/stdc++.h>
using namespace std;

//int min(int a,int b,int c) { return min(min(a,b),c);}

int __edit_distance__(string string1,int size1,string string2,int size2,vector<vector<int>> &mem)
{
    if(size1 == 0)
        return size2;
    if(size2 == 0)
        return size1;

    if(mem[size1][size2] != -1) return mem[size1][size2];

    if(string1[size1 -1 ] == string2[size2 -1])
    {
        mem[size1][size2] = __edit_distance__(string1,size1 -1,string2,size2 -1,mem);
        return mem[size1][size2];
    }
    else
    {
        mem[size1][size2] = 1+ min(min(__edit_distance__(string1,size1,string2,size2 -1,mem),
                                __edit_distance__(string1,size1 -1,string2,size2,mem)),                                
                                __edit_distance__(string1,size1 -1,string2,size2 -1,mem)
                                );
        return mem[size1][size2];
    }
}

int edit_distance(string string1, string string2)
{   
    int size1 = string1.size();
    int size2 = string2.size();
    vector<vector<int>> mem(size1+1,vector<int>(size2+1,-1));
    return __edit_distance__(string1,size1,string2,size2,mem);
}

int main()
{
    string string1 = "cat";
    string string2 = "cut";
    cout<<edit_distance(string1,string2);
	return 0;
}