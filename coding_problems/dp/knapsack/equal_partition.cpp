#include<bits/stdc++.h>
using namespace std;

int __equal_partition__ ( vector<int> numbers, int size, int target) {
    if(size == 0)
        return 0;
    if(target == 0)
        return 1;
    if(numbers[size -1 ] > target) {
        return __equal_partition__ (numbers,size -1, target);
    }
    else {
        return __equal_partition__ (numbers,size -1, target - numbers[size])|| __equal_partition__ (numbers,size -1, target);
    }
}

bool equal_partition ( vector<int> numbers) {
    int sum = 0;
    for(int i = 0; i <numbers.size();i++)
    {
        sum += numbers[i];
    }
    if(sum%2 == 0)
    {
       int result= __equal_partition__(numbers,sum/2,sum/2);
       if(result == 1) {
           return true;
       }
        else
            return false;

    }
    else
        return false;
}

int main()
{
    vector<int> numbers = { 2,3,5};
    cout<<equal_partition(numbers);
	return 0;
}