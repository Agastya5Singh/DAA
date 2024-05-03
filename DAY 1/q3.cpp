// Write a program to store numbers into an array of n integers, where the array
// must contain some duplicates. Find out the most repeating element in the array.

#include<bits/stdc++.h>
using namespace std;

int repeat(int arr[],int n)
{	
	
	int maxcount=0;
  int element_having_max_freq;
  for(int i=0;i<n;i++)
  {
    int count=0;
    for(int j=0;j<n;j++)
    {
      if(arr[i] == arr[j])
        count++;
    }
 
    if(count>maxcount)
    {
      maxcount=count;
      element_having_max_freq = arr[i];
    }
     
  }
 
  return element_having_max_freq;

}

int main()
{	
	int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
	cout<<repeat(a,n);
	return 0;
}