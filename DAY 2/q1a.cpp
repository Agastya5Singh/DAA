#include<bits/stdc++.h>
using namespace std;


//function of non zero elements in 2D array
int non_zero_elements(int **a,int n)
{
  int count=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(a[i][j]!=0)
      {
        count++;
      }
    }
  }
  return count;
}

//function of sum of elements above leading diagonal in 2D array
int sum_above_diagonal(int **a,int n)
{
  int sum=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(i<j)
      {
        cout<<a[i][j]<<" ";
        sum+=a[i][j];
      }
    }
  }
  return sum;
}

//funtion to display elements below minor diagonal in 2D array
void display_below_minor_diagonal(int **a,int n)
{
  cout<<"Elements below minor diagonal:";
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<i;j++)
    {
    cout<<a[i][n-j-1]<<" ";
    }
  }
}

int prod_of_diag(int **a,int n)
{
  int prod1=1;
  for(int i=0;i<n;i++)
  {
    prod1*=a[i][i];
  }
  int prod2=1;
  for(int i=0;i<n;i++)
  {
    prod2*=a[i][n-i-1];
  }

  return prod1*prod2;
}

int main()
{
  int n;
  cout<<"Size of 2D array: ";
  cin>>n;
  //dymamic 2D array
  int **a=new int*[n];
  for(int i=0;i<n;i++)
  {
    a[i]=new int[n];
  }
  //input
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>a[i][j];
    }
  }

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
 cout<<"\nnon zero elements:"<<non_zero_elements(a,n)<<endl;
 cout<<"Sum of the elements above leading diagonal:"<< sum_above_diagonal(a,n)<<endl;
 display_below_minor_diagonal(a,n);
 cout<<"\nProduct of the elements on the diagonals:"<<prod_of_diag(a,n)<<endl;

}