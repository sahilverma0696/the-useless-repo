#include<bits/stdc++.h>
using namespace std;

int add_numbers(int a, int b) {
    if(b == 0)
        return a;
    add_numbers(a^b,(a&b)<<1);
}

int main()
{
    cout<<add_numbers(10,15);
	return 0;
}
