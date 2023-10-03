#include <iostream>
#include <vector>

using namespace std;

//tabulation 
// int main(){
//     int n;
//     cin>> n;
//     vector<int> dp(n+1);
//     dp[0] = 0;
//     dp[1] = 1;
//     for(int i= 2 ; i <= n ; i++){
//         dp[i] = dp[i-1] + dp[i - 2];
//     }
//     cout << dp[n]<<" ";
//     return dp[n];
// }

//optimized one 
int main(){
    int n;
    cin>> n;
    int prev1 = 0;
    int prev2 = 1;
    for(int i= 2 ; i <= n ; i++){
        int cur = prev1 + prev2;
        prev1 = prev2;
        prev2 = cur;
    }
    cout << prev2 <<" ";
    return prev2;
}