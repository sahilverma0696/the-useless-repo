#include<bits/stdc++.h>
using namespace std;

void reverse(string &sample, int lower_bound, int upper_bound)
{
    char temp;
    while(lower_bound < upper_bound)
    {
        temp = sample[lower_bound];
        sample[lower_bound] = sample[upper_bound];
        sample[upper_bound ] = temp;
        lower_bound++;upper_bound--;
    }
}


void reverse_word(string complete, string word)
{
    int pos = complete.find(word);
    reverse(complete,pos,pos+word.size()-1);
    cout<<complete;
}

int main()
{
    string sample = "the sky is blue";
    string word = "sky";
    reverse_word(sample,word);
    return 0;
}