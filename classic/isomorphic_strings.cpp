#include<bits/stdc++.h>
using namespace std;

bool isIsomorphic(string string1, string string2)
{
    if(string1.size()!=string2.size())
        return false;

    unordered_map<char,char> mapper;

    for(int i = 0; i < string1.size(); ++i)
    {
        if(mapper[string1[i]]!=string2[i])
            if(!mapper[string1[i]])
                mapper[string1[i]] = string2[i];
            else 
                return false;
    }
    
    return true;

}

int main()
{
    string s = "abbbz";
    string t = "zxxxz";
    cout<<"True"<<true<<endl;
    cout<<isIsomorphic(t,s);
	return 0;
}