#include<bits/stdc++.h>
using namespace std;

void __allSubstr__(string input, string output)
{
    if(input.size() == 0)
    {
        cout<<output<<"\n";
        return;
    }
    __allSubstr__(input.substr(1), output);
    __allSubstr__(input.substr(1), output+input[0]);
}

void allSubstr(string input)
{
    __allSubstr__(input,"");
}
int main()
{
    string input = "tictaktoe";
    allSubstr(input);
	return 0;
}