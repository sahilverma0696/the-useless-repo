#include<bits/stdc++.h>
using namespace std;

void quicksort(int low,int high,vector<int>& values)
{
    if(low>=high) return;
    int i = low, pivot = values[i], j = high;

    for(;;)
    {
        while(values[i]<pivot) i++;
        while(values[j]>pivot) j--;
        if(i>=j) break;
        swap(values[i],values[j]);
        i++;j--;
    }
    quicksort(low,i-1,values);
    quicksort(j+1,high,values);


}

int main() 
{
    vector<int> values = {5,3,1,4,2};
    for(int x: values)
        cout<<x<<"\t";
    cout<<"\n";

    quicksort(0,values.size()-1,values);

    for(int x:values)
        cout<<x<<"\t";

    return 0;
}