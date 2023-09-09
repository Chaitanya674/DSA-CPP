#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int array[n];
    // int array[n]  = {10 , 20 , 40 , 30 };
    // cout<<array[3]<<endl;
    // return 0;
    for (int i = 0; i<n ; i++){
        cin>>array[i];
    }
    for (int i = 0 ; i < n ; i++){
        cout<<array[i]<<" ";
    }
    return 0;
}