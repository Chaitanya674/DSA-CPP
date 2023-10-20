#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution {
public:
    int solve(vector<int>& v , int i, int j){
        //base case
        if(i +1 == j){
            return 0;
        }
        int ans = INT_MAX;
        for(int k = i+1 ; k<j; k++){
            ans = min(ans ,v[i]*v[k]*v[j] + solve(v , i , k)+ solve(v , k , j));
        }
        return ans;
    }
    int solveMemo(vector<int>& v , int i, int j , vector<vector<int>> &dp){
        //base case
        if(i +1 == j){
            return 0;
        }
        if (dp[i][j] != INT_MAX){
            return dp[i][j];
        }

        for(int k = i+1 ; k<j; k++){
            dp[i][j] = min(dp[i][j] ,v[i]*v[k]*v[j] + solveMemo(v , i , k, dp)+ solveMemo(v , k , j, dp));
        }
        return dp[i][j];
    }
    int solveTab(vector<int>& v){
        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i = n-1 ; i >=0 ; i--){
            for(int j = i+2 ; j < n ; j++){
                int ans = INT_MAX;
                for(int k = i+1 ; k<j; k++){
                    ans = min(ans ,v[i]*v[k]*v[j] + dp[i][k]+ dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        int ans = solveTab(values);
        return ans;
    }
};