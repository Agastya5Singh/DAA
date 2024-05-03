//write a program to rearrange the elements of an array of n integers 
// such that all even number are placed first and all odd numbers are placed last.
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]%2==0){
            cnt++;
        }
    }
    int b[cnt];
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(a[i]%2==0){
            b[cnt1]=a[i];
            cnt1++;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]%2!=0){
            b[cnt1]=a[i];
            cnt1++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}