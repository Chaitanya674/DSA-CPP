#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int> &weight , vector<int> &value , int i , int capacity){
    if(i == 0){
        if(weight[0] <= capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }

    int include = 0;
    if(weight[i] <= capacity){
        include = value[i] + solve(weight , value , i -1 , capacity - weight[i]);
    }
    int exclude = 0 + solve(weight , value , i -1 , capacity);
    int ans = max(exclude , include);
    return ans;
}

//Memorization
int solveMemo(vector<int> &weight , vector<int> &value , int i , int capacity , vector<vector<int>>&dp){
    if(i == 0){
        if(weight[0] <= capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }
    if(dp[i][capacity] != -1){
        return dp[i][capacity];
    }
    int include = 0;
    if(weight[i] <= capacity){
        include = value[i] + solveMemo(weight , value , i -1 , capacity - weight[i] , dp);
    }
    int exclude = 0 + solveMemo(weight , value , i -1 , capacity, dp);
    dp[i][capacity] = max(exclude , include);
    return dp[i][capacity];
}

int solveTab (vector<int> &weight , vector<int> &value , int i , int capacity){
    //step 1 : make a dp array 2D 
    vector<vector<int>> dp(weight.size(), vector<int>(capacity+1 , 0));

    //step 2 : analyze the 
    for (int w = weight[0] ; w <= capacity; w++){
        if(weight[0] <= capacity){
            dp[0][w] = value[0];
        }
        else{
            dp[0][w] = 0;
        }
    }

    for(int index = 1 ; index < i; index++){
        for(int w = 0 ; w <= capacity ; w++){
            int include = 0;
            if(weight[index] <= w){
                include = value[index] + dp[index -1][ w - weight[index]];
            }
            int exclude = 0 + dp[index -1][w];
            dp[index][w] = max(exclude , include);
            
        }
    }
    return dp[i-1][capacity];
}

int main(){
    vector<int> weight = {1 ,2 , 4 ,5};
    vector<int> value = {5 , 4, 8 , 6};
    int maxWeight = 5;
    vector<vector<int>> dp(4 , vector<int>(maxWeight+1 , -1));
    cout << solve(weight , value ,  3 , maxWeight)<< endl;
    cout << solveMemo(weight , value ,  3 , maxWeight, dp)<<endl;
    cout << solveTab(weight , value , 3 , maxWeight);
    return 0 ;
}