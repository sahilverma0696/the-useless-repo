#include<bits/stdc++.h>
using namespace std;

// Count of subsets with sum equal to X

// Recursive
// int __count_subset_sum__(vector<int> numbers, int size,int target) {
//     if(target == 0)
//         return 1;
//     if(size == 0)
//         return 0;
//     if(numbers[size-1]>target) {
//         return (__count_subset_sum__(numbers,size-1,target));
//     }
//     else {
//         return (__count_subset_sum__(numbers,size-1,target-numbers[size-1]) + __count_subset_sum__(numbers,size-1,target));
//     }
// }

// int count_subset_sum(vector<int> numbers,int target) {
//     return __count_subset_sum__(numbers,numbers.size(),target);
// }

// Memoized
// int __count_subset_sum__(vector<int> numbers, int size,int target,vector<vector<int>> &mem) {
//     if(target == 0)
//         return 1;
//     if(size == 0)
//         return 0;
//     if(mem[numbers[size-1]][target]!= -1) return mem[numbers[size-1]][target];
//     if(numbers[size-1]>target) {
//         mem[numbers[size-1]][target] = (__count_subset_sum__(numbers,size-1,target,mem));
//         return mem[numbers[size-1]][target];
//     }
//     else {
//         mem[numbers[size-1]][target] = (__count_subset_sum__(numbers,size-1,target-numbers[size],mem) + __count_subset_sum__(numbers,size-1,target,mem));
//         return mem[numbers[size-1]][target];
//     }
// }
// 
// int count_subset_sum(vector<int> numbers,int target) {
//     int size = numbers.size();
//     vector<vector<int>>mem(size+1,vector<int>(target+1,-1));
//     return __count_subset_sum__(numbers,size,target,mem);
// }

// Tabulation
int count_subset_sum(vector<int> numbers, int target)
{
    vector<vector<int>>mem(numbers.size()+1,vector<int>(target+1));
    
    for(int i = 0; i<=numbers.size();i++) 
    {   for(int j= 0; j<=target;j++) 
            if(j == 0)
                mem[i][j] = 1;
    }

    for(int i = 1; i<=numbers.size();i++) 
        for(int j= 1; j<=target;j++) 
            if(numbers[i-1] > target)
                mem[i][j] = mem[i-1][j];
            else
                mem[i][j] = mem[i - 1][j - numbers[i - 1]]+ mem[i - 1][j];
    return mem[numbers.size()][target];
}

int main()
{
    vector<int> numbers = { 2,3,5,8,10};
    cout<<count_subset_sum(numbers,5);
	return 0;
}



