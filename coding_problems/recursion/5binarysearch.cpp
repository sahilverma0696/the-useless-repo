#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> values, int low,int high, int key)
{
    int mid = (low+high)/2;
    if(low>high)
        return -1;
    if(values[mid] == key)
        return mid;
    
    if(values[mid] > key)
        return binary_search(values,low,mid-1,key);
    if(values[mid] < key)
        return binary_search(values,mid+1,high,key);
    return -1;
}

int main()
{
    vector<int> values = {1,3,6,88,99,214,546,8356,25341};
    cout<<binary_search(values,0,values.size(),3);
	return 0;
}
