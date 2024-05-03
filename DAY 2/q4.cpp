//Given a key in a shorted array A with distinct value. WAP to find i,j,k ssuch that A[i]+A[j]+A[k]==key
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int k;
    cout<<"Enter the value of k"<<endl;
    cin>>k;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int l=j+1;l<n;l++)
            {
                if(a[i]+a[j]+a[l]==k)
                {
                    cout<<a[i]<<" "<<a[j]<<" "<<a[l]<<endl;
                }
            }
        }
    }

}