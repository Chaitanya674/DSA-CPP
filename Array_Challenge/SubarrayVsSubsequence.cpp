//SUB-ARRAY
//Numebr of subarray = nC2+n = n*(n+1)/2
//SUB-SEQUENCE
//derived from the array selecting zero or more elements without changing the order of the remaining elements
//Number of subsequences that can be formed = 2^n

//Every subarray is a sequence but every subsequence is not a subarray

//Longest Arithmetic Subarray
#include <iostream>
using namespace std;

int main(){
    int ans = 2;
    int n;

    cin>>n;
    int a[n];

    for (int i =  0 ; i <n;i++){
        cin>>a[i];
    }
    int pd = a[1] - a[0];
    int j = 2;
    int curr =2;

    while(j <n){
        if(pd == a[j]-a[j-1]){
            curr++;
        }
        else{
            pd = a[j]- a[j-1];
            curr = 2;
        }
        ans = max(curr , ans);
        j++;
    }

    cout<<ans<<endl;

    return 0;
}