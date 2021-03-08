#include<iostream>
#include<string>

using namespace std;

void __print_substr__(string input, string output, string first)
{
    if(input.size() == 0)
    {
        cout<<first+output<<"\n";
        return;
    }  
    __print_substr__(input.substr(1),output+ input[0],first);
    __print_substr__(input.substr(1),output +"_" + input[0],first);
}
void print_substr(string input)
{
    string output = "";
    __print_substr__(input.substr(1),output,input.substr(0,1));
}

int main()
{
    string input = "abc";
    print_substr(input);
    return 0;
}