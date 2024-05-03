#include<stdio.h>
int count=0;
int expo1(int a,int n)
{
    int m;
    if(n==0)
        return 1;
    else
    {
        count++;
        m = expo1(a, n/2);
        if(n%2==0)
            return m*m;
        else
            return a*m*m;
    }
}
int expo2(int a,int n)
{
    int m=1;
    for(int i=0;i<n;i++)
    {
        count++;
        m*=a;
    }
    return m;
}
int main()
{
    printf("N\t\tRecursion\tFunction\n");
    for(int i=10;i<=1000000;i*=10)
    {
        printf("%d\t\t",i);
        count=0;
        expo1(2,i); 
        printf("%d\t\t",count);
        count=0;
        expo2(2,i);
        printf("%d\n",count);
    }
}