#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge_asc(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0;
    j = 0;
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void merge_desc(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0;
    j = 0;
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] >= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void merge_Sort_asc(int arr[], int l, int r) 
{ 
    if (l < r) 
    {
        int m = l+(r-l)/2; 
  
        merge_Sort_asc(arr, l, m); 
        merge_Sort_asc(arr, m+1, r); 
  
        merge_asc(arr, l, m, r); 
    } 
} 
void merge_Sort_desc(int arr[], int l, int r) 
{ 
    if (l < r) 
    {
        int m = l+(r-l)/2; 
  
        merge_Sort_desc(arr, l, m); 
        merge_Sort_desc(arr, m+1, r); 
  
        merge_desc(arr, l, m, r); 
    } 
} 

void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 

int main() 
{ 
    int n,i,ch,a=10;
    printf("Enter the size : ");
    scanf("%d",&n);
    int arr[n];
    clock_t start,end;
    double time_req;
     for (i=0;i<n;i++)
         arr[i]=rand()%100;
         

    while(a>0){
            printf("Enter the choice :  1. Random 2.already sorted 3.Reverse sort");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
                {
        start=clock();
        merge_Sort_asc(arr, 0, n - 1);
        end=clock();
        printArray(arr, n);
            time_req=(double)(end-start)/CLOCKS_PER_SEC;
            printf("\nThe time required is : %lf",time_req);
                    break;
                }
        case 2:
                {
        merge_Sort_asc(arr, 0, n - 1); 
        
        start=clock();
        merge_Sort_asc(arr, 0, n - 1);
        end=clock();
         printArray(arr, n);
            time_req=(double)(end-start)/CLOCKS_PER_SEC;
            printf("\nThe time required is : %lf",time_req);
                    break;
                    
                }
        case 3:
                {
        merge_Sort_desc(arr, 0, n - 1);
        printArray(arr, n);
        
        start=clock();
        merge_Sort_asc(arr, 0, n - 1);
        end=clock();
        printArray(arr, n);

            time_req=(double)(end-start)/CLOCKS_PER_SEC;
            printf("\nThe time required is : %lf",time_req);
                    break;
            }
            
    }
        printf("\nEnter the a number greater than 0 to continue\n");
        scanf("%d",&a);
    }

    return 0; 
}