#include<bits/stdc++.h>
using namespace std;
int main(){
    int b,g;
    cout<<"Enter no. of boys\n";
    cin>>b;
    int arr1[b];
    for(int i=0;i<b;i++){
        cin>>arr1[i];
    }
        sort(arr1,arr1+b);
        cout<<"Enter the no. of girls\n";
    cin>>g;
    int arr2[g];
    for(int i=0;i<g;i++){
        cin>>arr2[i];
    }

    sort(arr2,arr2+g);
    int i=0,j=0;

    cout<<"Common Ages are : ";
    while(i<b && j<g){
        if(arr1[i]==arr2[j]){
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
        else if(arr1[i]>arr2[j]){
            j++;
        }
        else{
            i++;
        }
    }
    return 0;
}