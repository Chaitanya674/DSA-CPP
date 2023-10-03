#include <iostream>
#include <vector>

using namespace std;

//memorization = store the value of sub problems 
int fibo(int n , vector<int> &dp){
    //step 1 
    if(n <= 1){
        return n;
    }
    //step 3
    if(dp[n] != -1){
        return dp[n];
    }
    //step 2
    dp[n]  = fibo( n-1 , dp) + fibo(n - 2 , dp);
    return dp[n];
}

int main(){
    int n;
    cin>> n;
    int j = 0 ;
    vector<int> dp(n+1);
    for(int i= 0 ; i <= n ; i++){
        dp[i] = -1;
    }
    while( j < n ){
        cout << fibo(j , dp) << " " << endl;
        j++;
    }
    return 0;
}