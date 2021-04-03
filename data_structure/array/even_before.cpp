#include<bits/stdc++.h>
using namespace std;
// Function to make all the even position of an array before.

// Two pointer method

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void array_change( int array[], int size)
{
    int j = 1;
    for( int i = 2; i <size;i+=2)
    {
        swap(array[i],array[j]);
        j++;
    }
}

int main()
{
    int array[] = {1,2,3,4,5};
    int size = sizeof(array)/sizeof(array[0]);
    array_change(array,size);
    for(int i = 0; i<size;i++)
        cout<<array[i];
	return 0;
}

