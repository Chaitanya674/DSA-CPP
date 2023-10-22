#include<iostream>
#include<vector>

using namespace std;

int solve(int n  , int a[] , int curr , int prev , vector<vector<int>>& dp)
{
    if(curr == 0 ){
        return 0 ;
    }
    if(dp[curr][prev+1] != -1){
        return dp[curr][prev+1];
    }
    //include
    int take = 0;
    if(prev == -1 || a[curr] > a[prev]){
        take = 1 + solve(n , a , curr+1 , curr, dp);
    } 
    int notTake = 0+ solve(n , a, curr+1 , prev, dp);
    return dp[curr][prev+1] = max(take  , notTake);
}

int main(){
    int  a[] = {1, 5, 8, 9 , 2, 10};
    int n = 6;
    vector<vector<int>> dp(n , vector<int>(n+1 , -1));
    cout<< solve(n , a , 0 , 0, dp) << endl;
}