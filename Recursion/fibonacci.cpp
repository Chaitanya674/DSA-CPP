#include <iostream>
using namespace std;

int fibonacci(int n ){
    if(n==0 || n==1){
        return n;
    }
    int pref_sum =  fibonacci(n-1) + fibonacci(n-2);
    return pref_sum;
}

int main(){
    int n;
    cin >> n;
    int ans = fibonacci(n);
    cout<< ans;
    return 0;
}