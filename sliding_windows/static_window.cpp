#include<bits/stdc++.h>

using namespace std;

int max_window(vector<int> values, int k)
{
    int result = 0, cmax = 0;
    for(int i=0; i < k;i++)
    {
        cmax += values[i];
    }
    for(int i =k; i<values.size();i++)
    {
        cmax = cmax + values[i] - values[i-k];
        result = max(result,cmax);
    }
    return result;
}

int main()
{
    cout<<max_window({2,3,6,4,5},3);
    return 0;
}