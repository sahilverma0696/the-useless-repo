#include<bits/stdc++.h>
using namespace std;

int __ll__(vector<int>& coins, int amount, int size, vector<vector<int>> &mem)
    {
        if(amount == 0)
            return 0;
        if(size  == 0)
            return INT_MAX-1;
        if(size == 1)
        {
            if( amount%coins[0] == 0 )
                return amount/coins[0];
            else
                return INT_MAX-1; 
        }
        if(mem[amount][size] != -1)
            return mem[amount][size];
        
         if(coins[size-1]>amount)
            return mem[amount][size] =  __ll__(coins,amount,size - 1,mem);
        return mem[amount][size]= min(__ll__(coins,amount,size - 1,mem),1+__ll__(coins,amount - coins[size-1],size,mem));
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        vector<vector<int>> mem(amount+1,vector<int>(size+1,-1));
        int res = __ll__(coins,amount,size,mem);
        return res > 2000000 ? -1:res;
    }

int main()
{
	return 0;
}