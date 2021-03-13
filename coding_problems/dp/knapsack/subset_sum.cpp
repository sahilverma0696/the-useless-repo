#include<bits/stdc++.h>
using namespace std;

int __subset__(vector<int> numbers,int size,int target, int memo[6][12])
{
    if(size == 0)
        return 0;
    if(target == 0)
        return 1;
    int x =numbers[size - 1];

    numbers.pop_back();
    if(memo[size][target]!= -1) return memo[size][target];
    if(x>target)
    {
    memo[size][target] = __subset__(numbers,size -1,target,memo);
    }
    else
    {
        memo[size][target] = (__subset__(numbers,size -1,target -x,memo) || __subset__(numbers,size -1,target,memo));
    }
    return memo[size][target];
}

bool subset(vector<int> numbers,int target)
{
    
    int size = numbers.size();
    int memo[6][12] = {-1};
    if(__subset__(numbers,6,12,memo)==1)
        return true;
    else 
        return false;
}

int main()
{
    vector<int> numbers {2,3,7,8,10};
    int target = 11;
    cout<<true;
    cout<<subset(numbers,target);
	return 0;
}