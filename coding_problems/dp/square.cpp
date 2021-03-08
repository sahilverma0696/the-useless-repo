#include<bits/stdc++.h>
using namespace std;

int __square__(int n, vector<int> memo);
int square(int n)
{
    vector<int> memo(n+1,0);
    return __square__(n, memo);
}

int __square__(int n, vector<int> memo)
{
    if(n == 0 || n == 1)
        return 1;
    if(memo[n]!=0)
        return memo[n];
    memo[n] *= __square__(n-1,memo);
}

int main()
{
    cout<<square(5);
	return 0;
}