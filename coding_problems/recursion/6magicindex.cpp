// Return index where a[i] == i;
#include<bits/stdc++.h>
using namespace std;

int magicIndex(vector<int> values, int low, int high) {
    int mid = (low+high)/2;

    if(values[mid] == mid)
        return mid;
    if(low>high)
        return -1;
    if(values[mid]>mid)
        return magicIndex(values,low,mid-1);
    else
        return magicIndex(values,mid+1,high);
    return false;
}

int main()
{
    vector<int> values = {-1,1,3,6,88,99,214,546,8356,25341};
    cout<<magicIndex(values,0,values.size());
	return 0;
}
