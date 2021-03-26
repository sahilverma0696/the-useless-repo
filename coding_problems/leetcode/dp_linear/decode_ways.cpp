// #include<bits/stdc++.h>
#include<string>
#include<iostream>
using namespace std;

int __numDecodings__(string input, int size) {
    if(size == 0)
        return 0;
    if(size<26) {
        return 1 + __numDecodings__(input,size-1);
    }
    else
        return 0;

}

int numDecodings(string s) {
        return __numDecodings__(s,s.size());
    }

int main()
{
    string input = "226";
    cout<<numDecodings(input);
	return 0;
}