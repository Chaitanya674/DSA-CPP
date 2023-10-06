#include <iostream>
using namespace std;

int solve(long long  nStairs, int i){
    int ans;
    if(nStairs ==  i){
        return 1; 
    }
    if( i> nStairs){
        return 0;
    }
    return (solve(nStairs , i+1) + solve(nStairs , i +2)) % 1000000007;
}

int main(){
    long long nStairs = 33;
    int ans = solve(nStairs , 0);
    cout << ans << " ";
    return 0;
}