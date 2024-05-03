#include<stdio.h>
#include<stdlib.h>
void sort(int *s,int *f,int n)
{
    int t,i;
    for(i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(f[j]<f[i])
            {
                t=s[i];
                s[i]=s[j];
                s[j]=t;
                t=f[i];
                f[i]=f[j];
                f[j]=t;
            }
        }
    }
}
void activity(int *s,int *f,int n)
{
    sort(s,f,n);
    int a[n],i,j=0;
    for(i=0;i<n;i++)
        a[i]=0;
    a[0]=1;
    for(i=1;i<n;i++)
    {
        if(s[i]>f[j])
        {
            a[i]=1;
            j=i;
        }
    }
    printf("The following activities are selected: ");
    for(i=0;i<n;i++)
        if(a[i]==1)
            printf("%d ",i);
    printf("\n");
}
void main()
{
    int *s,*f,n;
    printf("Enter the no of activities \n");
    scanf("%d",&n);
    s=(int *)malloc(sizeof(int)*n);
    f=(int *)malloc(sizeof(int)*n);
    printf("Enter the start and finish time \n");
    for(int i=0;i<n;i++)
        scanf("%d %d",&s[i],&f[i]);
  
    activity(s,f,n);
}