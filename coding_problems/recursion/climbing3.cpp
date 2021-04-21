#include<bits/stdc++.h>

using namespace std;

int climb(int n) {
    if( n == 0 || n== 1)
        return 1;
    if(n<0)
        return 0;
    return climb(n-1) + climb(n-2) + climb(n-3);
}

int main() {
    cout<<climb(10);
    return 0;
}