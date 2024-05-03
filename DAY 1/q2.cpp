// wap to store nos into an array of n integers where the array must contain some duplicates. 
// Find out the total number of duplicate elements
#include<bits/stdc++.h>
using namespace std;

int ans(int a[],int n)
{   int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    


    
    cout<<ans(a,n);

return 0;
}