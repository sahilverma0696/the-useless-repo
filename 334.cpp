#include<bits/stdc++.h>
using namespace std;

// The 24 game is played as follows. You are given a list of four integers, each between 1 and 9, in a fixed order. By placing the operators +, -, *, and / between the numbers, and grouping them with parentheses, determine whether it is possible to reach the value 24.

// For example, given the input [5, 2, 7, 8], you should return True, since (5 * 2 - 7) * 8 = 24.

// Write a function that plays the 24 game.

bool isTwentyFour(vector<int> input)
{
    // Recursive function -> since the elements are just 4 numbers, leads to finite set of methods.
    // trying all possibilities with 4 differnt operations 
    // adding ( & ) at every level

    return 0;
}

bool __is24__(vector<int> input,int current,bool open)
{
    if(current == 24)
        return true;

    
}


int main() {

    cout<<isTwentyFour({5,2,7,8});
    return 0;
}