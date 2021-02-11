#include<bits/stdc++.h>
#include<string>
using namespace std;

int postfix(vector<char> input)
{
    vector<int> value_stack;
    int v1 =0, v2 = 0;
    for(int i = 0;i<input.size();i++)
    {
        if(input[i]=='+'|| input[i]=='-'||input[i]=='*'||input[i]=='/')
        {
            v2 = value_stack.back(); value_stack.pop_back();
            v1 = value_stack.back(); value_stack.pop_back();
            if(input[i]=='+')
            {
                value_stack.push_back(v1+v2);
            }
            else if(input[i]=='-')
                value_stack.push_back(v1-v2);
            else if(input[i]=='*')
                value_stack.push_back(v1*v2);
            else if(input[i]=='/')
                value_stack.push_back(v1/v2);
        }
        else
        {
            value_stack.push_back(input[i] -'0');
        }
    }
    return value_stack.back();
}

int main()
{
    vector<char> sample {'2', '1', '+', '3', '*'};
    cout<<postfix(sample);
	return 0;
}