#include<bits/stdc++.h>
using namespace std;

// Recursive
int knapsack(int val[],int weigh[],int capacity,int arr_size)
{
    if(arr_size == 0 || capacity == 0)
        return 0;
    if(weigh[arr_size-1] > capacity)
        return knapsack(val,weigh,capacity,arr_size-1);
    else 
        return max( val[arr_size-1]+knapsack(val,weigh,capacity-weigh[arr_size-1],arr_size-1) ,
                                    knapsack(val,weigh,capacity,arr_size-1)
                    );
        
}

// Memoization


int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout<<knapsack(val,wt,W,n);
	return 0;
}












