#include<iostream>

using namespace std;

int numberofonce(int n){
    int count = 0;
    while(n){
        n = n & n-1;
        count++;
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    int ans = numberofonce(n);
    cout<<ans;
    return 0;
}