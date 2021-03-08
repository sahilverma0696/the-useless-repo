#include<iostream>
#include<vector>

using namespace std;

/*
int helper(vector<int> &memo, int n);
int fibb ( int n)
{
    if(n<0) return 0;
    vector<int> memo(n+1,0);

    return helper(memo,n);
}

int helper(vector<int> &memo, int n)
{
    if(n == 1 || n == 2) return 1;

    if(memo[n]!= 0) return memo[n];
    memo[n] = helper(memo,n-1) + helper(memo,n-2);
}

*/

//O(1) space
int fibb(int n)
{
    if(n ==1 || n == 2) return 1;

    int prev =1, curr = 1;

    for(int i =3; i<=n;i++)
    {
        int sum  = prev+curr;
        prev = curr;
        curr = sum;
    }
    return curr;
} 
int main()
{   
    cout<<fibb(10);
    return 0;
}

