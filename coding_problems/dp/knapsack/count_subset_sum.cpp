#include<bits/stdc++.h>
using namespace std;

// Recursive
// int __count_subset_sum__(vector<int> numbers, int size,int target) {
//     if(size == 0)
//         return 0;
//     if(target == 0)
//         return 1;
//     if(numbers[size-1]>target) {
//         return (__count_subset_sum__(numbers,size-1,target));
//     }
//     else {
//         return (__count_subset_sum__(numbers,size-1,target-numbers[size]) + __count_subset_sum__(numbers,size-1,target));
//     }
// }

// int count_subset_sum(vector<int> numbers,int target) {
//     return __count_subset_sum__(numbers,numbers.size(),target);
// }

// Memoized
int __count_subset_sum__(vector<int> numbers, int size,int target,vector<vector<int>> &mem) {
    if(size == 0)
        return 0;
    if(target == 0)
        return 1;
    if(mem[numbers[size-1]][target]!= -1) return mem[numbers[size-1]][target];
    if(numbers[size-1]>target) {
        mem[numbers[size-1]][target] = (__count_subset_sum__(numbers,size-1,target,mem));
    }
    else {
        mem[numbers[size-1]][target] = (__count_subset_sum__(numbers,size-1,target-numbers[size],mem) + __count_subset_sum__(numbers,size-1,target,mem));
    }
}

int count_subset_sum(vector<int> numbers,int target) {
    int size = numbers.size();
    vector<vector<int>>mem(size+1,vector<int>(target+1,-1));
    return __count_subset_sum__(numbers,size,target,mem);
}

int main()
{
    vector<int> numbers = { 2,3,5,8,10};
    cout<<count_subset_sum(numbers,5);
	return 0;
}



