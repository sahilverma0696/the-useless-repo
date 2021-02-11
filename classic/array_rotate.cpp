#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int> &array,int lower_bound, int upper_bound );
void array_rotate(vector<int> array, int pivot)
{
    reverse(array,0,pivot-1);
    reverse(array,pivot,array.size()-1);
    reverse(array,0,array.size()-1);

    for(int i = 0; i <array.size();i++)
    {
        cout<<array[i];
    }
}

void reverse(vector<int> &array,int lower_bound, int upper_bound )
{
    int temp = 0;
    while(lower_bound<upper_bound)
    {
        temp = array[lower_bound];
        array[lower_bound] = array[upper_bound];
        array[upper_bound] = temp;
        lower_bound++; upper_bound--;
    }
}
int main()
{
    vector<int> array {1,2,3,4,5,6,7};
    array_rotate(array,3);
	return 0;
}