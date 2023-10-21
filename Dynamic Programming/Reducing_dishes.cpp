#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int solve(vector<int> &arr , int i , int j ,vector<vector<int>>& dp){
        if( i == arr.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        //incude 
        int include = arr[i] * (j+1) + solve(arr , i+1 , j+1 , dp);
        //exclude
        int exclude = 0 + solve(arr  , i+1 , j , dp);
        dp[i][j] = max(include , exclude);
        return dp[i][j];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = sizeof(satisfaction) / sizeof(satisfaction[0]);
        sort(satisfaction.begin() , satisfaction.end());
        int m = satisfaction.size();
        vector<vector<int>> dp(m+1  , vector<int>(m, -1 ));
        int ans = solve(satisfaction , 0 , 0 , dp);
        return ans;
    }
};