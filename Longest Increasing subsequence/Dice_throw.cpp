#include<iostream>
#include<vector>

using namespace std;

long long solve(int dice , int faces , int target){
    //base case
    if (target < 0 )
    {
        return 0;
    } 
    if(dice ==0 && target != 0  ){
        return 0;
    }
    if(target == 0 && dice != 0){
        return 0;
    }
    if (dice == 0 && target == 0 ){
        return 1;
    }
    //calls for each dice
    long long ans = 0; 
    for(int i = 1 ; i <= faces ; i++)
    {
        ans += solve(dice -1 , faces , target -i);
    }
    return ans;
}

int solveMemo(int dice , int faces , int target ,vector<vector<int>>& dp){
    //base case
    if (target < 0 )
    {
        return 0;
    } 
    if(dice ==0 && target != 0  ){
        return 0;
    }
    if(target == 0 && dice != 0){
        return 0;
    }
    if (dice == 0 && target == 0 ){
        return 1;
    }
    if(dp[dice][target] != -1){
        return dp[dice][target];
    }
    //calls for each dice
    int ans =  0;
    for(int i = 1 ; i <= faces ; i++)
    {
        ans+= solveMemo(dice -1 , faces , target -i, dp);
    }
    return dp[dice][target] = ans;
}

long long solveTab(int dice , int faces , int target){
    vector<vector<long long>> dp(dice+1 , vector<long long>(target +1 , 0));
    dp[0][0] = 1; 
    for(int d = 1; d <= dice ; d++ ){
        for (int y = 1 ; y <= target ; y++){
            long long ans =  0;
            for(int i = 1 ; i <= faces ; i++)
            {
                if(y - i >= 0)
                    ans+= dp[d - 1][y - i];
            }
            dp[d][y] = ans;
        }
    }
    return dp[dice][target];
}


int main(){
    int n = 3;
    int m = 6;
    int x = 12;
    cout<< solve(n, m, x) << endl;
    vector<vector<int>> dp(n+1 , vector<int>(x +1 , -1));
    cout<< solveMemo(n , m , x , dp) << endl;
    cout<< solveTab(n , m , x ) << endl;
    return 0;
}