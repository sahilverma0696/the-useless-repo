#include<bits/stdc++.h>
#include<cstring>
using namespace std;

void __subSTR__(string input, string output)
{
    if(input.size() == 0)
    {
        cout<<output<<"\n";
        return;
    }
    char c = input[0]; // case of backtracking 
    char x = toupper(input[0]);
    __subSTR__(input.substr(1),output+input[0]);
    __subSTR__(input.substr(1),output + x);
    input = c+input; // this is revisited and solved again
    
}

void subSTR(string input)
{
    for(int i = 0; i<input.size();i++)
    __subSTR__(input,"");
}
int main()
{
    string input = "ab";
    subSTR(input);
	return 0;
}