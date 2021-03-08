#include<bits/stdc++.h>
using namespace std;

/*
Cracking the coding interview
String rotated: check if string1 is a rotated string of string2.
string1 = melonwater string2 = watermelon -> true
*/

/* slow one 
bool isRotated(string check, string original)
{
    for(int i = 0;i<original.size();i++)
    {
        if(original.find(check.substr(i)) != std::string::npos)
        {
            if(original.find(check.substr(0,i)) != std::string::npos)
                return true;
        }
    }
    return false;
}
*/

//fast one 

bool isRotated(string check, string original)
{
    string temp = original + original;
    if(temp.find(check) != string::npos)
        return true;
    return false;
}


int main()
{
    string string1 = "melonwater";
    string string2 = "watermelon";
    //cout<<string1.substr(5);
    //cout<<string1.substr(0,5);
    cout<<"false"<<false<<"\n";
    cout<<isRotated(string1,string2);
	return 0;
}