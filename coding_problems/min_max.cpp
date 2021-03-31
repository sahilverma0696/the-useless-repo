
#include <iostream>
#include<chrono>

using namespace std;
using namespace std::chrono;


// Same speed

// int max(int x, int y) {
//     return x>y?x:y;
// }

int max(int x,int y) {
    return x ^ ((x ^ y) & -(x < y));
}

// int min(int x,int y) {
//     return x>y?y:x;
// }

int min(int x, int y) {
    return y ^ ((x ^ y) & -(x < y));
}


int main()
{

    auto start = high_resolution_clock::now();
	
    int maxi = min(5,10);
	
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout<<maxi;
    
    cout <<"\n\n\nExecution Summary:\n"<< duration.count() << " microseconds\n";
    
	return 0;
}