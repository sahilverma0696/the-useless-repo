#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
 {
     vector<vector<int>> result;
     for(int i = 0; i < intervals.size()-1;i++)
     {
         if(intervals[i][1] - intervals[i+1][0]>=0)
         {
            vector<int> temp {intervals[i][0], intervals[i+1][1]};
            result.push_back();
         }

     }
     return result;
}

int main()
{
	return 0;
}