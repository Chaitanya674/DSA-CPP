#include <iostream>
#include <vector>

using namespace std;

int fibo(int n){
    vector<int> memo;
    if(n == 1 || n == 0){
        return n;
    }
    return fibo( n-1) + fibo(n - 2);
}

int main(){
    int n;
    cin>> n;
    int i = 0 ;
    while( i < n ){
        cout << fibo(i) << " " << endl;
        i++;
    }
    return 0;
}