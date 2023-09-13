#include <iostream>
using namespace std;

void increment(int a){
    a++;
}

int main(){
    int a = 10;
    int* aptr = &a;
    cout<<*aptr<< endl;
    cout<<&a<< endl;

    *aptr = 11;
    cout<<&a<< endl;

    aptr++;
    cout<<aptr<<endl;
    cout<<&a<< endl;

    int arr[] = {10, 20 ,30 };
    cout<< *arr <<endl;

    int *ptr = arr;
    //one way to traverse
    // for(int i = 0; i< 3; i++){
    //     cout<<*ptr<<endl;
    //     ptr++;
    // }

    //second way
    for(int i = 0 ; i< 3; i++){
        cout<<*(arr+i)<<endl;
        ////arr++; // illegal
    }

    increment(a);
    cout << &a << endl;
    cout << a << endl;

    return 0;


}