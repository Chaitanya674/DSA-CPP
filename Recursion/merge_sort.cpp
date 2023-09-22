#include<iostream>

using namespace std;


void merge(int *arr , int start , int end){
    int mid = (start +end) /2;
    int len1 =  mid- start +1;
    int len2 =  end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int k = start;
    for(int i =  0 ;i < len1 ; i++ ){
        first[i] = arr[k++];
    }

    k = mid +1;
    for(int i = 0; i< len2 ; i++){
        second[i] = arr[k++];
    }

    //merge 2 sorted arrays
    int idx1 = 0;
    int idx2 = 0;
    k = start;

    while(idx1 < len1 && idx2 < len2){
        if (first[idx1] < second[idx2]){
            arr[k++] = first[idx1++];
        }
        else{
            arr[k++] = second[idx2++];
        }
    } 

    while(idx1 < len1){
        arr[k++] = first[idx1++];
    }

    while (idx2 < len2){
        arr[k++] = second[idx2++];
    }

    delete []first;
    delete []second;
}

//Faster than bubble , insertion and selection  
void MergeSort(int *arr ,int start , int end){
    
    //base case
    if(start >= end){
        return ;
    }
    int mid = (end + start) / 2;

    MergeSort(arr , start , mid);
    MergeSort(arr , mid+1 , end);
    merge(arr , start , end);
}

int main(){
    int arr[7] = {38 , 27 , 43 , 3 , 9 , 82 , 10};
    MergeSort(arr , 0 , 6);
    for(int i = 0; i < 7 ; i++){
        cout<< arr[i] << " ";
    } 
    return 0;
}