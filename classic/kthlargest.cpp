#include<bits/stdc++.h>
using namespace std;

int kthlargest(vector<int> &nums, int k)
{
    priority_queue<int> heap;
    for(int i = 0; i<nums.size();i++)
    {
        heap.push(nums[i]);
    }

    for(int i = 0;i<k-1;i++)
    {
        heap.pop();
    }
    return heap.top();

}


int main()
{
    vector<int> array {3,2,1,5,6,4};
    cout<<kthlargest(array,2);
	return 0;
}