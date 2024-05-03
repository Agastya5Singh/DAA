//write a program to store the numbers into an array of n integers. and then find out smallest and largerget numbers in it

#include <bits/stdc++.h>
using namespace std;

void ans(int a[],int &max,int &min,int n)
{
   
    for(int i=0;i<n;i++){
        if(a[i]<min){
            min=a[i];
        }
        if(a[i]>max){
            max=a[i];
        }
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    int min= INT_MAX;
    int max= INT_MIN;
    for(int i=0;i<n;i++)
        cin>>a[i];
        
    
    ans(a,max,min,n);
    cout<<min<<" "<<max;
    
    return 0;
}