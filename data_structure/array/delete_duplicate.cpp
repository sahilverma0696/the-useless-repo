#include<bits/stdc++.h>
using namespace std;

int delete_duplicate(vector<int> &array)
{
    if(array.empty())
        return 0;
    
    int wi = 1;
    for(int i = 1;i<array.size();++i)
    {
        if(array[wi-1]!= array[i])
            array[wi++] = array[i];
    }
    return wi;
}

int main()
{
    vector<int> array =  {1,2,3,3,4,5,6,7,7,8,8};
    int result = delete_duplicate(array);
    for(int i  =0; i<array.size();i++)
        cout<<array[i];
	return 0;
}