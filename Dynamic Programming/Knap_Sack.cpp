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
int main(){
    vector<int> weight = {1 ,2 , 4 ,5};
    vector<int> value = {5 , 4, 8 , 6};
    int maxWeight = 5;
    cout << solve(weight , value ,  3 , maxWeight);
    return 0 ;
}