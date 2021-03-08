#include<bits/stdc++.h>
using namespace std;
void push_(stack<int> &stack,int target)
{
    if(stack.empty())
    {
    stack.push(target);
    return;
    }
    int val = stack.top();stack.pop();
    push_(stack,target);
    stack.push(val);
}

void reverse_stack(stack<int> &stack)
{
    if(!stack.empty())
    {
    int val = stack.top();stack.pop();
    reverse_stack(stack);
    push_(stack,val);
    }
}

int main()
{
    stack<int> stack;
    for(int i = 0; i<4;i++)
        stack.push(i);
    
    

    cout<<"\n";

    reverse_stack(stack);
    int s = stack.size();
    cout<<"\n"<<s<<"\n";
    for(int i = 0; i<s;i++)
    {
        cout<<stack.top();
        stack.pop();
    }

	return 0;
}