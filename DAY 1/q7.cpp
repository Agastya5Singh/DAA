/*
Write a program to display an array of n integers (n>1), where at every index
of the array should contain the product of all elements in the array except the
element at the given index. Solve this problem by taking single loop and
without an additional array.
*/
#include<bits/stdc++.h>
using namespace std;
void product(int arr[],int n){
    int prod = 1;
    for(int i = 0 ; i<n ; i++){
        prod *= arr[i];
       
    }
   
    for(int i = 0 ; i<n ; i++){
        arr[i] = prod/arr[i];
    }
}
int main(){
    int n;
    cout<<"Enter the n\n";
    cin>>n;
    int arr[n];
    for(int i = 0 ; i<n ; i++){
     cin>>arr[i];
    }
    product(arr,n);
    cout<<"The product of all elements in the array except that index val is\n";
    for(int i = 0; i<n; i++){
     cout<<arr[i]<<" ";
    }
     return 0;
}