/*
Write a program to swap pair of elements of an array of n integers from starting.
If n is odd, then last number will be remain unchanged.
*/
#include<bits/stdc++.h>
using namespace std;
void swap_pair(int arr[],int n){
    for(int i = 0 ; i<n ; i+=2){
        if(i+1<n)
        swap(arr[i],arr[i+1]);
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
    swap_pair(arr,n);
    for(int i = 0; i<n; i++){
     cout<<arr[i]<<" ";
    }
     return 0;
}