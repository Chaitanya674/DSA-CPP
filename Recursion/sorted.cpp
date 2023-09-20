#include<iostream>

using namespace std;

bool sorted(int arr[] , int n){
    if (n == 1){
        return true;
    } 
    bool resArray = sorted(arr+1 , n-1);
    return (arr[0] < arr[1] && resArray);
}

int main(){
    int n = 6;
    int arr[] = {1,4,7,32,63,2};
    bool ans = sorted(arr, n);
    cout<<ans;
    return ans;
}