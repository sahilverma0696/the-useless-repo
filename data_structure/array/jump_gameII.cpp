#include<bits/stdc++.h>
using namespace std;

// int __jump__(int array[], int current, int dest)
// {
//     if(current>=dest) return 0;

//     int temp = INT_MAX;
    
//     for(int i = 1; i <=array[current];i++)
//     {
//         temp = min(temp,1+__jump__(array,current+i,dest));
//     }

//     return temp;

// }


// int jump ( int array[], int size)
// {
    
//     return __jump__(array,0,size-1);
// }

int __jump__(int array[], int current, int dest,vector<int> &mem)
{
    if(current == dest)  return 0;
    if(mem[current]!= -1) return mem[current];

    int temp = INT_MAX;

    for(int i = 1; i <=array[current];i++)
    {
        if(i+current>dest) break;
        temp = min(temp,1+__jump__(array,current+i,dest,mem));

    }
    mem[current] = temp;
    return temp;
}
int jump(int array[], int size)
{
    vector<int> mem (size+1,-1);
    return __jump__(array,0,size-1,mem);
}
int main()
{
    int array[] = {2,3,1,1,4};
    int size = sizeof(array)/sizeof(array[0]);
    int result  = jump(array,size);
    cout<<result;
	return 0;
}

