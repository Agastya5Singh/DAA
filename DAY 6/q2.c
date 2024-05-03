#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int partition(int *a, int l, int u)
{
    int i,j,piv;
    i=l;
    j=u;
    piv=a[l];
    while(1)
    {
        while(a[i]<=piv&&i<=u)
            i++;
        while(a[j]>piv)
            j--;
        if(i<j)
            swap(&a[i],&a[j]);
        else 
            break;
    }
    swap(&a[l],&a[j]);
    return u;
}
void quicksort(int *a, int l, int u)
{
    if(l<u)
    {
        int p=partition(a,l,u);
        quicksort(a,l,p-1);
        quicksort(a,p+1,u);
    }
}
int main()
{
    int n,i,*arr;
    clock_t start, end;
    double ol,ul,sv,rl,sl5;
    printf("Size\tOrdered List\tUnordered List\tSame Value\tRandom List\t50 Sorted List\n");
    for (n=5000;n<=50000;n+=5000)
    {
        arr = (int *)malloc(sizeof(int) * n);
        //Ordered List
        for (i = 0; i < n; i++)
            arr[i] = i;
        start = clock();
        quicksort(arr, 0, n-1);
        end = clock();
        ol = (((double)(end-start))/CLOCKS_PER_SEC);
        //Unordered List
        for (i = 0; i < n; i++)
            arr[i] = n-i-1;
        start = clock();
        quicksort(arr, 0, n-1);
        end = clock();
        ul = (((double)(end-start))/CLOCKS_PER_SEC);
        //Same Value
        for (i = 0; i < n; i++)
            arr[i] = 1;
        start = clock();
        quicksort(arr, 0, n-1);
        end = clock();
        sv = (((double)(end-start))/CLOCKS_PER_SEC);
        //Random List
        for (i = 0; i < n; i++)
            arr[i] = rand();
        start = clock();
        quicksort(arr, 0, n-1);
        end = clock();
        rl = (((double)(end-start))/CLOCKS_PER_SEC);
        //50% Sorted List
        for (i = 0; i < n; i++)
            arr[i] = rand();
        quicksort(arr, 0, n/2);
        start = clock();
        quicksort(arr, 0, n-1);
        end = clock();
        sl5 = (((double)(end-start))/CLOCKS_PER_SEC);
        printf("%d\t%f\t%f\t%f\t%f\t%f\n",n,ol,ul,sv,rl,sl5);
        free(arr);
    }
}