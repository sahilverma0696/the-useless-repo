/*
https://leetcode.com/problems/generate-parentheses/
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/

#include<bits/stdc++.h>
using namespace std;

void __balance__(int left, int right, vector<string> &result,string output)
{
    if(left == 0 && right == 0)
    {
        result.push_back(output);
        //result.push_back("\t");  // optional -> looks better
        return;
    }
    if(left > 0)
        __balance__(left -1 ,right,result,output+"(");
    if(left < right)
        __balance__(left ,right-1,result,output+")");
    
}

vector<string> balance(int n)
{
    vector<string> result;
    __balance__(n,n,result,"");
    return result;
}

/* chumma level
void balance(int n)
{
    if(n == 0)
        return;
    cout<<"(";
    balance(n-1);
    cout<<")";
}
*/

int main()
{
    vector<string> result = balance(3);
    for(int i = 0; i <result.size();i++)
        cout<<result[i];
	return 0;
}