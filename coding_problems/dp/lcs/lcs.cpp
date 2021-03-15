#include<bits/stdc++.h>
using namespace std;

// Longest common subsequence

// Recursive

// int __lcs__(vector<char> s1, vector<char> s2,int size1,int size2)
// {
//     if(size1 == 0 || size2 == 0)
//         return 0;
//     if(s1[size1-1] == s2[size2-1])
//     {
//         return 1 + __lcs__(s1,s2,size1-1,size2-1);
//     }
//     else
//     {
//         return max( __lcs__(s1,s2,size1-1,size2),__lcs__(s1,s2,size1,size2-1));
//     }
// }
// int lcs (vector<char> s1, vector<char> s2)
// {
//     return __lcs__(s1,s2,s1.size(),s2.size());
// }

// Memoized 

// int __lcs__(vector<char> s1, vector<char> s2,int size1,int size2,vector<vector<int>> & mem)
// {
//     if(size1 == 0 || size2 == 0)
//         return 0;

//     if(mem[size1][size2] != -1) return mem[size1-1][size2-1];

//     if(s1[size1-1] == s2[size2-1])
//     {
//         mem[size1][size2] = 1 + __lcs__(s1,s2,size1-1,size2-1,mem);
//         return mem[size1][size2];
//     }
//     else
//     {
//         mem[size1][size2] = max( __lcs__(s1,s2,size1-1,size2,mem),__lcs__(s1,s2,size1,size2-1,mem));
//         return mem[size1][size2];
//     }
// }
// int lcs (vector<char> s1, vector<char> s2)
// {
//     vector<vector<int>> mem (s1.size()+1,vector<int>(s2.size() + 1,-1));
//     return __lcs__(s1,s2,s1.size(),s2.size(),mem);
// }


// Tabulization

int lcs ( vector<char> s1,vector<char> s2)
{
    vector<vector<int>> mem (s1.size()+1,vector<int>(s2.size() + 1));
    for(int i = 1;i<=s1.size();i++)
    {
        for(int j = 1;j<=s2.size();j++)
        {
            if(s1[i] == s2[j])
                mem[i][j] = 1+ mem[i-1][j-1];
            else
                mem[i][j] = max( mem[i][j-1], mem[i][j-1]);
        }
    }
    return mem[s1.size()][s2.size()];
}

int main()
{
    vector<char> X = {'A','G','G','T','A','B'};
    vector<char> Y = {'G','X','T','X','A','Y','B'};
    cout<<lcs(X,Y);
	return 0;
}