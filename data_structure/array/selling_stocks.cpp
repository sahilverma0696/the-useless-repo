#include<bits/stdc++.h>
using namespace std;

int stocks(vector<int> values)
{
    int min_price = INT_MAX, max_profit = 0;
    for(auto price: values)
    {
        int max_day = price - min_price;
        max_profit = max(max_profit,max_day);
        min_price = min(min_price,price);
    }
    return max_profit;
}

int main()
{
    vector<int> values = {310,315,275,295,260,270,290,230,255,250};
    cout<<stocks(values);
	return 0;
}