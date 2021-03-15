#include<bits/stdc++.h>
using namespace std;

// Recursive

// int knapsack(int val[],int weigh[],int capacity,int arr_size)
// {
//     if(arr_size == 0 || capacity == 0)
//         return 0;
//     if(weigh[arr_size-1] > capacity)
//         return knapsack(val,weigh,capacity,arr_size-1);
//     else 
//         return max( val[arr_size-1]+knapsack(val,weigh,capacity-weigh[arr_size-1],arr_size-1) ,
//                                     knapsack(val,weigh,capacity,arr_size-1)
//                     );
        
// }

// Memoization

// int __knapsack__(int val[],int weigh[],int capacity,int arr_size,vector<vector<int>> & mem)
// {
//     if(arr_size == 0 || capacity == 0)
//         return 0;
//     if(mem[arr_size][capacity] != -1) return mem[arr_size][capacity];
//     if(weigh[arr_size-1] > capacity)
//     {
//         mem[arr_size][capacity] = __knapsack__(val,weigh,capacity,arr_size-1,mem);
//         return mem[arr_size][capacity];
//     }
        
//     else 
//     {
//         mem[arr_size][capacity] = max( val[arr_size-1]+__knapsack__(val,weigh,capacity-weigh[arr_size-1],arr_size-1,mem) ,
//                                     __knapsack__(val,weigh,capacity,arr_size-1,mem)
//                     );
//         return mem[arr_size][capacity];
//     }
// }
// int knapsack(int val[],int weigh[],int capacity,int arr_size)
// {
//     vector<vector<int>>mem(arr_size+1,vector<int>(capacity+1,-1));
//     return __knapsack__(val,weigh,capacity,arr_size,mem);
// }

// Tabulation

int knapsack(int val[],int weigh[],int capacity,int arr_size)
{
    vector<vector<int>>mem(arr_size+1,vector<int>(capacity+1));
    for(int i = 1; i<=arr_size;i++)
    {
        for(int j = 1;j<=capacity;j++)
        {
            if(weigh[i-1] <= j)
                mem[i][j] = max( val[i - 1] + mem[i - 1][j - weigh[i - 1]],
                                              mem[i - 1][j]
                                );
            else
                mem[i][j] = mem[i-1][j];
        }
    }
    return mem[arr_size][capacity];
}

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout<<knapsack(val,wt,W,n);
	return 0;
}
