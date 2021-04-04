// 1. get the lsb 
// 2. get the msb in 2 digit number
// last element is size-1
#include<bits/stdc++.h>
using namespace std;

void increment_all(int array[], int size)
{
    const int INCREMENT = 1;
    int counter = 0;
    for(int j = size -1;j>=0; j--)
    {
        int num = array[j] + INCREMENT + counter;
        counter = num>=10?1:0;
        array[j] = num%10;
    }
}

void next_number(int array[], int size)
{
    int num = array[size-1] + 1;
    int counter = num>=10?1:0;
    array[size-1] = num%10;
    for(int j = size -2;j>=0; j--)
    {
        int num = array[j] + counter;
        counter = num>=10?1:0;
        array[j] = num%10;
    }
}

int main()
{
    // int x = 469;
    // cout<<"MSB\t"<<x/10<<"\n";
    // cout<<"LSB\t"<<x%10<<"\n";


    int array[] = {1,2,9};
    int size = sizeof(array)/sizeof(array[0]);
    next_number(array,size);
    for(int i = 0; i<size;++i)
        cout<<array[i];

	return 0;
}

