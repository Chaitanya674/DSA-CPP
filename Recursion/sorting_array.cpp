#include<iostream>

using namespace std;

bool isSorted(int arr[] , int n){
    if(n == 0 || n == 1){
        return true; 
    }
    if (arr[n-1] > arr[n]){
        return false;
    }
    else{
        isSorted(arr , n-1);
    }
}

int main(){
    int n = 5;
    int arr[] = {1,2,3,4,5};
    bool sort = isSorted(arr , n);
    cout<<sort<<endl;

    return 0;
}
