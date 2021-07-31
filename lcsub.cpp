#include<bits/stdc++.h>
using namespace std;

int lcsubstring(string a, string b)
{
    vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1));
    int m = 0;
    for(int i = 1; i<=a.size();i++)
    {
        for(int j = 1;j<=b.size();j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j] = 1+ dp[i-1][j-1];
                m = max(dp[i][j],m);
            }
            else
                dp[i][j] = 0; // string 
            
        }
    }

    return m;
}


int main() {
    string a = "ABCDFE";
    string b = "ZABCDSS";
    cout<<lcsubstring(a,b);
    return 0;
}