#include <iostream>
using namespace std;

int main(){
    //check Palimdrone
    int n;
    cin>>n;

    char arr[n+1];
    bool check = 1;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] != arr[n-i]){
            check = 0;
        }
    }
    return check;
}