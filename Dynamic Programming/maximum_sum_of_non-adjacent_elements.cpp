#include<iostream >

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


int main(){
    int arr[] = {9 , 9 , 8, 2};
    int n = 4;
    int ans = solver(arr , n -1);
    cout<< ans << endl;
    return 0;
}