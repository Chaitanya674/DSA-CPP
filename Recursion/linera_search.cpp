#include <iostream>
using namespace std;

int search(int arr[], int n , int key){
    if(arr[n] ==  key){
        return n;
    }
    if(n == 0){
        return -1;
    }
    else{
        search(arr, n-1 , key);
    }
}

int main(){
    int n = 5;
    int arr[] = {1,2,3,4,5};
    int key = 3;
    int ans = search(arr , n , key);

    cout << ans << endl;

    return 0 ; 
}