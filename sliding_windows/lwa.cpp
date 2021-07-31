#include<bits/stdc++.h>

using namespace std;


int lwa(vector<int> arr, int k) {
    unordered_map<int,int> values;
    int maxLen = 0, sum = 0;
    for(int i = 0; i<arr.size();i++)
    {
        sum += arr[i];

        if(sum == k)
            maxLen = i+1;
        
        if(values.find(sum) == values.end())
            values[sum] = i;
        
        if(values.find(sum-k) != values.end())
        {
            if(maxLen < (i - values[sum-k]))
                maxLen = i - values[sum-k];
        }
    }
    return maxLen;
}
int main() {

    cout<<lwa({4,1,2,3,1,1,5},5);
    return 0;
}