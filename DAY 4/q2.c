#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void is(int *a,int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>temp)
                a[j+1]=a[j];
            else
                break;
        }
        a[j+1]=temp;
    }
}
void is2(int *a,int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(a[j]<temp)
                a[j+1]=a[j];
            else
                break;
        }
        a[j+1]=temp;
    }
}
int main()
{
    int *b;
    clock_t end,start;
    double time_taken;
    printf("  N\tRandom   \tAscending\tDescending\n");
    for(int i=5000;i<=50000;i=i+5000)
    {
        printf("%d\t",i);
        b=malloc(i*sizeof(int));
        for(int j=0;j<i;j++)
            b[j]=rand();
        start=clock();
        is(b,i);
        end=clock();
        time_taken=(((double)(end-start))/CLOCKS_PER_SEC);
        printf("%f\t",time_taken);
        start=clock();
        is(b,i);
        end=clock();
        time_taken=(((double)(end-start))/CLOCKS_PER_SEC);
        printf("%f\t",time_taken);
        is2(b,i);
        start=clock();
        is(b,i);
        end=clock();
        time_taken=(((double)(end-start))/CLOCKS_PER_SEC);
        printf("%f\n",time_taken);
    }
}