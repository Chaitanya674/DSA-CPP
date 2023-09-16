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
    int arr[4] = {1,2,3,4};
    generator(arr , 4);
    return 0;
}