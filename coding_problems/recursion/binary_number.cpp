#include<bits/stdc++.h>
using namespace std;

void __binary_number__(int n,int ones, int zeros,string output,vector<string> &result)
{
    if(n == 0)
    {
        result.push_back(output);
        return;
    }
    if(ones>zeros)
    {
        __binary_number__(n-1,ones+1,zeros,output +"1",result);
        __binary_number__(n-1,ones,zeros+1,output +"0",result);
    }
    if(ones == 0 || ones == zeros)
    {
        __binary_number__(n-1,ones+1,zeros,output +"1",result);
    }

}

vector<string> binary_number ( int n)
{
    vector<string> result;
    __binary_number__(n,0,0,"",result);
    return result;
}

int main()
{
    vector<string> result = binary_number(3);
    for(int i = 0;i<result.size();i++)
        cout<<result[i]<<"\n";
	return 0;
}