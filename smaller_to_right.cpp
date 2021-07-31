#include<bits/stdc++.h>
using namespace std;

vector<int> smallerRight(vector<int> &input)
{
    int n = input.size();
    vector<int> result(n,0);
    for(int i = n -2;i>=0;i--)
    {
        if(input[i]>input[i+1])
            result[i] = result[i+1]+1;
        else
            result[i] = result[i+1];
    }
    return result;
}

int main() {
    vector<int> result;
    vector<int> input = {3,4,9,6,1};
    result = smallerRight(input);
    for(int x:result)
        cout<<x;
    return 0;
}
