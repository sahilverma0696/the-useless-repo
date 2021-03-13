#include<bits/stdc++.h>
using namespace std;

int knapsack(int val[],int weigh[],int capacity,int arr_size)
{
    if(arr_size == 0 || int capacity == 0)
        return 0;
    if(weigh[arr_size-1]<capacity)
        return max(val[arr_size-1]+knapsack(val,weigh,capacity-weigh[arr_size-1],arr_size-1),knapsack(val,weigh,capacity-weigh[arr_size-1],arr_size-1));
    else if ( weigh[n-1]>capacity)
        return knapsack(val,weigh,capacity-weigh[arr_size-1],arr_size-1);
}

int main()
{
	return 0;
}














s  = ""
vec = 1,2,3,4,5

if(s.find(vec<5>))
    not include
else
{
    output + include
    not include;
}

sahil

sa

sahil.find(sa)!= string::npos












