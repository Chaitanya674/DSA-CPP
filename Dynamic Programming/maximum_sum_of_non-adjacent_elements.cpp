#include<iostream >
#include<vector>

using namespace std;

int solver(int *arr, int n){
    if (n < 0 ){
        return 0;
    }
    if (n ==  0 ){
        return arr[0];
    }
    int incl = solver(arr , n -2) + arr[n];
    int excl = solver(arr , n-1) + 0;
    return max(incl , excl);
}

//Memorization 
int solver_dp(int *arr, int n  , vector<int> &dp){
    if (n < 0 ){
        return 0;
    }
    if (n ==  0 ){
        return arr[0];
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int incl = solver_dp(arr , n -2  , dp) + arr[n];
    int excl = solver_dp(arr , n-1 , dp) + 0;
    dp[n] = max(incl , excl);
    return dp[n];
}

int main(){
    int arr[] = {9 , 9 , 8, 2};
    int n = 4;
    vector<int> dp(n , -1);
    int ans = solver(arr , n -1);
    int dp_ans = solver_dp(arr , n-1  , dp);
    cout<< ans << endl;
    cout<< dp_ans <<endl; 
    return 0;
}