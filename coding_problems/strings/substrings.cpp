#include<bits/stdc++.h>
using namespace std;

void print_substring(string input,string output)
{
    if(input.size() == 0)
    {
        cout<<output<<"\n";
        return;
    }
    print_substring(input.substr(1),output);
    print_substring(input.substr(1),output+ input[0]);

}

int main()
{
    string input = "sahil";
    string output = "";
    print_substring(input,output);
	return 0;
}