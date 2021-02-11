#include<bits/stdc++.h>
using namespace std;

float median( vector <int> array1, vector <int> array2)
{
    priority_queue<int> heap;
    
    for(int i = 0;i<array1.size();i++) heap.push(array1[i]);

    for(int i = 0;i<array2.size();i++) heap.push(array2[i]);

    int median_position = (array1.size()+array2.size())/2;

    if(median_position%2 == 0)
    {
        for(int i = 0; i<median_position-1;i++) heap.pop();
        int val1 = heap.top(); heap.pop();
        int val2 = heap.top();
        return (float)(val1+val2)/2;
    }
    else
    {   for(int i = 0; i<median_position;i++) heap.pop();
        return (float)heap.top();
    }
}

int main()
{

	return 0;
}
