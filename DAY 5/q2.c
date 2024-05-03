#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int findMax1(int arr[],int l,int r)
{
    if(l==r)
        return arr[l];
    int mid = (l+r)/2;
    int max1 = findMax1(arr,l,mid);
    int max2 = findMax1(arr,mid+1,r);
    return (max1>max2?max1:max2);
}
int findMin1(int arr[],int l,int r)
{
    if(l==r)
        return arr[l];
    int mid = (l+r)/2;
    int min1 = findMin1(arr,l,mid);
    int min2 = findMin1(arr,mid+1,r);
    return (min1<min2?min1:min2);
}
void findMax2(int arr[],int n)
{
    int max = arr[0];
    for(int i=1;i<n;i++)
        if(arr[i]>max)
            max = arr[i];
}
void findMin2(int arr[],int n)
{
    int min = arr[0];
    for(int i=1;i<n;i++)
        if(arr[i]<min)
            min = arr[i];
}
int main()
{
    clock_t start, end;
    int *a;
    printf("  N\tMax(Recursion)\tMin(Recursion)\tMax(Function)\tMin(Functiont\n");
    for(int i=50000;i<=500000;i=i+50000)
    {
        printf("%d\t",i);   
        a=malloc(i*sizeof(int));
        for(int j=0;j<i;j++)
            a[j]=rand();
        start = clock();
        findMax1(a,0,i);
        end = clock();
        double time_taken=(((double)(end-start))/CLOCKS_PER_SEC);
        printf("%f\t",time_taken);
        start = clock();
        findMin1(a,0,i);
        end = clock();
        time_taken=(((double)(end-start))/CLOCKS_PER_SEC);
        printf("%f\t",time_taken);
        start = clock();
        findMax2(a,i);
        end = clock();
        time_taken=(((double)(end-start))/CLOCKS_PER_SEC);
        printf("%f\t",time_taken);
        start = clock();
        findMin2(a,i);
        end = clock();
        time_taken=(((double)(end-start))/CLOCKS_PER_SEC);
        printf("%f\n",time_taken);
    }
    return 0;
}