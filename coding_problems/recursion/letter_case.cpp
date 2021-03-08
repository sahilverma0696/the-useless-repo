/*
https://leetcode.com/problems/letter-case-permutation/

Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.
*/
#include<bits/stdc++.h>
using namespace std;

void __letter_case__(string input,string output, vector<string> &result)
{
    if(input.size() == 0)
    {
        result.push_back(output);
        return;
    }
    char c = input[0];
    if(isdigit(input[0]))
        __letter_case__(input.substr(1),output+input[0],result);
    else
    {
        char x = tolower(input[0]);
        __letter_case__(input.substr(1),output+x,result);
        char y = toupper(input[0]);
        __letter_case__(input.substr(1),output+y,result);
    }
    input = c+input;
}

vector<string> letter_case(string input)
{
    vector<string> result;
    __letter_case__(input,"",result);
    return result;
}
int main()
{
    string input = "a1B2";
    vector<string>result = letter_case(input);
    for(int i = 0; i <result.size();i++)
    {
        cout<<result[i];
        cout<<"\n";
    }
	return 0;
}