// WAP to find the  missing no. from an array 
#include<iostream>
    using namespace std;
    int main()
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int missing = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=i+1)
            {
                missing = i+1;
                break;
            }
        }
        cout<<"The missing number is "<<missing<<endl;
    }