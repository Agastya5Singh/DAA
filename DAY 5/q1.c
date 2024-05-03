#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int bs(int a[],int key,int lb,int ub)
{
    int mid;
    if(lb<=ub)
    {
        mid=(lb+ub)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]>key)
            return bs(a,key,lb,mid-1);
        else
            return bs(a,key,mid+1,ub);
    }
    return -1;
}
int main()
{
    int *a,index;
    clock_t end,start;
    double time_taken;
    printf("  N\tBest\tRandom\tWorst\n");
    for(int i=50000;i<=500000;i=i+50000)
    {
        printf("%d\t",i);
        a=malloc(i*sizeof(int));
        for(int j=0;j<i;j++)
            a[j]=j;
        start=clock();
        index=bs(a,a[i/2],0,i);
        end=clock();
        time_taken=(((double)(end-start))*1000/CLOCKS_PER_SEC);
        printf("%f\t",time_taken);
        start=clock();
        index=bs(a,a[rand()%(i/2)],0,i);
        end=clock();
        time_taken=(((double)(end-start))*1000/CLOCKS_PER_SEC);
        printf("%f\t",time_taken);
        start=clock();
        index=bs(a,a[0],0,i);
        end=clock();
        time_taken=(((double)(end-start))*1000/CLOCKS_PER_SEC);
        printf("%f\n",time_taken);
    }
}