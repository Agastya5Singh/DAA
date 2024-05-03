//let A be n*n sq. matrix array. WAP by using appropriate user defined function.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    int nonZero=0, sum_up_diagn=0;
   cout<<"Matrix is:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if (i<j){
                sum_up_diagn+=a[i][j];
            }
          
            if(a[i][j]!=0)
            {
                nonZero++;
            }
            
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
        cout<<"ELement below the minor diagonal is "<<endl;

    for(int i =0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            if(j>n-i-1)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<"  ";
        }
        cout<<endl;
    }
     int product = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                product*=a[i][j];
            }
            if(j==n-i-1){
                product*=a[i][j];
            }
        }
    }
    cout<<"Non zero elements are "<<nonZero<<endl;
    cout<<"sum of diag is "<<sum_up_diagn<<endl;
    cout<<"product of diag is "<<product<<endl;

    return 0;
}