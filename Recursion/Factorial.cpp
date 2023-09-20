#include <iostream>
using namespace std;

int factorial(int n ){
    if(n==0){
        return 0;
    }
    int pref_sum = factorial(n-1);
    return n * pref_sum;
}

int main(){
    int n;
    cin >> n;
    int ans = factorial(n);
    cout<< ans;
    return 0;
}