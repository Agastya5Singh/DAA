// Write a program to test whether a number n, entered through keyboard is prime or not by
// using different algorithms you know for atleast 10 inputs and note down the time complexity
// by step/frequency count method for each algorithm & for each input. Finally make a
// comparision of time complexities found for different inputs, plot an appropriate graph &
// decide which algothm is faster.

#include<bits/stdc++.h>
using namespace std;

string isPrime(int n)
{
    if(n==1)
    {
        return "Not Prime";
    }
    else if(n==2)
    {
        return "Prime";
    }
    else
    {
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                return "Not Prime";
            }
        }
        return "Prime";
    }
}
 
int check_prime(int n) {
  int  isprime = true;

 
  if (n == 0 || n == 1) {
    isprime = false;
  }

  for (int i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      isprime = false;
      break;
    }
  }

  return isprime;
}

void isPrime(int n) {
   int i, flag = 0;
   for(i=2; i<=n/2; ++i) {
      if(n%i==0) {
         flag=1;
         break;
      }
   }
    if (flag==0)
   cout<<n<<" is a prime number"<<endl;
   else
   cout<<n<<" is not a prime number"<<endl;

int main()
{
    int n;
    cout<<"Enter the number of elements";
    cin>>n;
    while(n--)
    {   
        int t;
        cin>>t;
     cout<<isPrime(t)<<"\n";
    }
    
      return 0;
}