#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution {
public:
    int solve(vector<int>& o , int lane , int pos , vector<vector<int>>& dp){
        if (pos == o.size() - 1){
            return 0;
        }
        if(dp[lane][pos] != -1){
            return dp[lane][pos];
        }
        if(o[pos+1] != lane){
            return solve(o , lane  , pos+1, dp);
        }
        else{
            //sidway jump
            int ans = INT_MAX;
            for (int i = 1 ; i<= 3;i++){
                if(lane != i && o[pos] != i){
                    ans  = min(ans , 1 + solve(o , i , pos, dp));
                }
            }
            dp[lane][pos] = ans;
        }
        return dp[lane][pos];
    }
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(4 , vector<int>(obstacles.size() , -1));
        int ans = solve(obstacles, 2 , 0, dp);
        return ans;
    }
};