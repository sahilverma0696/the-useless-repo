/*
Problem 22
This problem was asked by Microsoft.

Given a dictionary of words and a string made up of those words (no spaces), return the original sentence in a list. If there is more than one possible reconstruction, return any of them. If there is no possible reconstruction, then return null.

For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", you should return ['the', 'quick', 'brown', 'fox'].

Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond", return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].
*/

#include<bits/stdc++.h>
using namespace std;

void __solution__(unordered_map<string,int> dict,string input,string output,vector<string> &result)
{
    
    if(dict[output])
    {
        result.push_back(output);
        output = "";
    }
    if(input.size() == 0)
        return;

    __solution__(dict,input.substr(1),output+input[0],result);
}

vector<string> solution(unordered_map<string,int> dict,string input)
{
    vector<string> result;
    __solution__(dict,input,"",result);
    return result;
}

int main()
{
    unordered_map<string,int> map;
    map["quick"] = 1;
    map["brown"] = 1;
    map["the"] = 1;
    map["fox"] = 1;
    string input ="thequickbrownfox";

    vector<string> result = solution(map,input);
    for(int i = 0; i<result.size();i++)
        cout<<result[i]<<"\n";
	return 0;
}