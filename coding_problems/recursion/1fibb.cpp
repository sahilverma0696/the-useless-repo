#include <iostream>
#include<chrono>
#include<vector>
using namespace std;
using namespace std::chrono;


// int fib ( int n ) {
//     // Particular base condition related to fibb sequence
//     if(n == 1 || n == 2)
//         return 1;
//     if( n == 0 )
//         return 0;
//     return fib(n-1)+ fib(n-2);
// }


// int __fib__(int n, vector<int> mem)
// {
//     if(n == 1 || n == 2)    return 1;
//     if(mem[n] != -1)    return mem[n];

//     mem[n] = __fib__(n-1,mem) + __fib__(n-2,mem);
//     return mem[n];

// }



// int fib(int n)
// {
//     vector<int> mem(n+1,-1);
//     // int* mem = new int[n+1];
//     // std::fill_n(mem, n+1, -1); 
//     return __fib__(n,mem);
// }

int fib(int n)
{
    if(n == 0)              return 0;
    int result = 0;
    int a = 0, b = 1;
    for(int i = 2; i<=n;i++)
    {
        result = a+b;
        a = b;
        b = result;
    }
    return result;
}

int main()
{
    auto start = high_resolution_clock::now();
    cout<<fib(25);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\n\n\nExecution Summary:\n"<< duration.count() << " microseconds\n";
    return 0;
}