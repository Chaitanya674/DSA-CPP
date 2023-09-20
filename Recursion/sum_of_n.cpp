#include <iostream>
using namespace std;

int sum(int n ){
    if(n==0){
        return 0;
    }
    int pref_sum = sum(n-1);
    return n + pref_sum;
}

int main(){
    int n;
    cin >> n;
    int ans = sum(n);
    cout<< ans;
    return 0;
}