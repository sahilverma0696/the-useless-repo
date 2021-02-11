#include<bits/stdc++.h>
using namespace std;

bool wildcard(string main_string, string wildcard_string)
{
    int i = 0;
    while(i<main_string.size())
    {
        if(i < wildcard_string.size() && wildcard_string[i]== '?' || main_string[i]==wildcard_string[i]);
        else
            return false;
        return true;
    }

}

int main()
{
    cout<<"True\t"<<true<<endl;
    cout<<"Output\t"<<wildcard("aaab","aa?b")<<endl;
	return 0;
}