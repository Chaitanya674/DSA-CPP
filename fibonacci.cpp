#include <iostream>
using namespace std;

int fib(int n){
    // int i = 0;
    // int j = 1;
    // int nextTerm;
    // for (int k = 1 ; k <=n ;k++){
    //     cout<<i<<endl;
    //     nextTerm = i +j;
    //     i = j ;
    //     j = nextTerm;
    // }
    if(n == 0){
        return 0;
    }
    int p = fib(n-1) + fib(n);
    cout<<p<<endl;
    return p;
}

int main(){
    int n ;
    cin>>n;
    fib(n);
    return 0;
}

