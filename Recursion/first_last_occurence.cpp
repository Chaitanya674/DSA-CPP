#include<iostream>

using namespace std;

int fandl(int arr[] , int n , int i , int key){
    if (i == n-1){
        return -1;
    }
    if (arr[i] ==key){
        return i;
    }
    return fandl(arr , n , i+1 , key);
}

int last(int arr[], int n , int i , int key){
    int restArray = last(arr, n, i+1, key);
    if (restArray != -1){
        return restArray;
    }
    if (arr[i] ==key){
        return i;
    }
    return -1;
}

int main(){
    int n = 6;
    int arr[] = {1,4,7,4,63,4};
    int f = fandl(arr, n , 0, 4);
    int l = last(arr , n , 0 , 4);
    cout<<f <<endl;
    cout<<l <<endl;
    return 0;
}