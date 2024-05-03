// WAP to find the sq. root of a number
#include<iostream>
using namespace std;
int SquareRoot(int n)
{
    int i=1;
    while(i*i<=n)
    {
        i++;
    }
    return i-1;
}
int main(){
    int n ; 
    cout<<"Enter the number"<<endl;
    cin>>n;
    int sqt = SquareRoot(n);
    cout<<"The square root of "<<n<<" is "<<sqt<<endl;
}