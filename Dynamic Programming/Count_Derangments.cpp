#include<iostream>
#include<vector>

using namespace std;
#define MOD 1000000007

int solve(int n){
    //base case 
    if (n==1){
        return 0;
    }
    if (n == 2){
        return 1 ;
    }
    int ans = ( ((n-1) % MOD) * ((solve(n-1)%MOD) + (solve(n-2)%MOD)) %MOD);
    return ans;
}

int main(){
    cout<< solve(10)<< endl;
    return 0 ;
}