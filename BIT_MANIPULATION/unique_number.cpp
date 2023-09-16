#include<iostream>

using namespace std;

int unique(int arr[], int n){
    int xorsum = 0;
    for(int i = 0 ;i<n ;i++){
        cout<<xorsum<<endl;
        xorsum = xorsum^arr[i];
    }
    return xorsum;
}

int main(){
    int arr[5] = {1, 2, 66, 2 , 1};
    int ans = unique(arr, 5);
    cout<<ans<<endl;
    return 0;
}