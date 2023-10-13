#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int solve(int n , int x , int y , int z){
    if(n == 0 ){
        return 0;
    }
    if(n < 0){
        return INT_MIN;
    }
    int a = solve(n - x , x , y , z) +1;
    int b = solve(n - y , x , y , z) +1;
    int c = solve(n - z , x , y , z) +1;
    int ans = max(a , max(b , c));
    return ans;
}

//Memorization 
int solveMemo(int n , int x , int y , int z , vector<int> &dp){
    if(n == 0 ){
        return 0;
    }
    if(n < 0){
        return INT_MIN;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int a = solveMemo(n - x , x , y , z , dp) +1 ;
    int b = solveMemo(n - y , x , y, z , dp) + 1;
    int c = solveMemo(n - z , x, y, z , dp) + 1;
    dp[n] = max(a , max(b , c));
    return dp[n];
}

//Tabulation 
int solveTab(int n , int x , int y , int z ){
    vector<int> dp(n+1, INT_MIN);
    dp[0] = 0;
    for(int i = 0 ; i <= n ;i++){
        if (i - x >= 0 ){
            dp[i] = max(dp[i] , dp[i-x] + 1);
        }
        if (i - y >= 0 ){
            dp[i] = max(dp[i] , dp[i-y] + 1);
        }
        if (i - z >= 0 ){
            dp[i] = max(dp[i] , dp[i-z] + 1);
        }
    }
    if (dp[n] < 0 ){
        return 0;
    }else{
        return dp[n];
    }
}

int  main(){
    cout << solve(7 , 5, 2, 2) << endl;
    vector<int> dp(8+1 , -1);
    cout << solveMemo(8 , 3, 3, 3 , dp) << endl;
    cout << solveTab(7 , 5 , 2, 2) << endl;
    return 0;
}