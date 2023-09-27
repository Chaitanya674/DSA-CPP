#include<iostream>

using namespace std;

int partition(int arr[] , int start , int end ){
    int pivot = arr[start];
    int count = 0;
    for(int i = start+1; i <= end; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }
    //place pivot at right place 
    int pivotIndex = start+ count;
    swap(arr[pivotIndex] , arr[start]);

    //left and right part
    int i = start, j = end; 
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i]< pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }

        if (i < pivotIndex && j > pivotIndex){
            swap(arr[i++] , arr[j--]);
        }

    }

    return pivotIndex;
}
void quickSort(int *arr , int start , int end){
    //base case
    if (start >= end){
        return; 
    }
    int pivot = partition(arr , start , end);
    //partitions in quick for sort 
    //recursion 
    quickSort(arr , start , pivot-1);
    
    quickSort(arr , pivot+1 , end);
    //merge the lists 
}

int main(){
    int arr[7] = {38 , 27 , 43 , 3 , 9 , 82 , 10};
    quickSort(arr , 0 , 6);
    for(int i = 0; i < 7 ; i++){
        cout<< arr[i] << " ";
    } 
    return 0 ;
}