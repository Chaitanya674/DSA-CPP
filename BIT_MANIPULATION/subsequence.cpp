#include<iostream>

using namespace std;


//total sets generated will be 2^n - 1 
void generator(int arr[], int n){
    // 2^n -1  this can be written as (1<<n)
    for(int i = 0 ; i < (1<<n); i++){
        for(int j =0 ; j < n ;j++){
            if(i & (1<<j)){
                cout<<arr[j]<< " " ;
            }
        }cout<<endl;
    }
} 

int main(){
    int arr[3] = {3,0,-6};
    generator(arr , 3);
    return 0;
}