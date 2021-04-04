#include<bits/stdc++.h>
using namespace std;

bool jump_game(int array[], int size)
{
    int last_jump = size-1;
    for(int i = size -1; i>=0; i--)
    {
        if(array[i]+i >= last_jump);
            last_jump = i;
    }

    return last_jump == 0;
}

int main()
{   
    int array[] = {2,3,1,1,4};
    int size = sizeof(array)/sizeof(array[0]);
    cout<<jump_game(array,size);
	return 0;
}

