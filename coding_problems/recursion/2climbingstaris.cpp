#include <iostream>
#include<chrono>
#include<vector>
using namespace std;
using namespace std::chrono;


// Recursive 
int climbStairs(int n) {
    if(n < 0)
        return 0;
    if( n == 0 || n == 1)
        return 1;
    return climbStairs(n-1) + climbStairs(n-2);
}
// Memoized
// int __fn__(int n, vector<int> mem)
//     {
//         if(n == 1 || n == 2)
//             return n;
//         if(mem[n] != -1)    
//             return mem[n];

//         return mem[n] = __fn__(n - 1,mem) + __fn__(n -2,mem); 
        
//     }
//     int climbStairs(int n) {
        
//         vector<int> mem(n+1,-1);
        
//         return __fn__(n,mem);
//     }


// Bottom Up
// int climbStairs(int n) {
//         if(n == 1 || n==2)
//             return n;
//         vector<int> mem(n+1,0);
//         mem[1] = 1;
//         mem[2] = 2;
        
//         for(int i = 3;i<=n;i++)
//         {
//             mem[i] = mem[i-1]+mem[i-2];
//         }
//         return mem[n];
//     }

int main()
{

    auto start = high_resolution_clock::now();
    cout<<climbStairs(35);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\n\n\nExecution Summary:\n"<< duration.count() << " microseconds\n";
    
	return 0;
}