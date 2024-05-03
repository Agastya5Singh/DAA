#include <stdio.h>
#include <stdlib.h>
#include <time.h> // for clock_t, clock(), CLOCKS_PER_SEC

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 0; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void reverseInsertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 0; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void otherSortingMethod(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

void otherReverseSortingMethod(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

void create(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
    }
    // printf("\nArray of A[%d] is succefully formed", n);
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

double timeTakentoSortUnsorted(int arr[], int n)
{
    // printf("\nUnsorted aaray = ");
    // display(arr, n);

    clock_t begin = clock();
    insertionSort(arr, n);
    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("\nSorted Array = ");
    // display(arr, n);

    // printf("\nThe elapsed time is %f seconds", time_spent);
    return time_spent;
}

double timeTakentoSortSorted(int arr[], int n)
{
    otherSortingMethod(arr, n);
    // printf("\nSorted aaray = ");
    // display(arr, n);

    clock_t begin = clock();
    insertionSort(arr, n);
    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("\nSorted Array = ");
    // display(arr, n);

    // printf("\nThe elapsed time is %f seconds", time_spent);
    return time_spent;
}

double timeTakentoSortReverselySorted(int arr[], int n)
{
    reverseInsertionSort(arr, n);
    // printf("\nReverse Sorted aaray = ");
    // display(arr, n);

    clock_t begin = clock();
    insertionSort(arr, n);
    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("\nSorted Array = ");
    // display(arr, n);

    // printf("\nThe elapsed time is %f seconds", time_spent);
    return time_spent;
}

void table(int arr[])
{
    int k = 5000;
    printf("\nSerial\t\tInput Size\t Timetaken to sort sorted\tTimetaken to sort rev.sorted\tTimetaken to sort unsorted");
    for (int i = 0; i < 10; i++)
    {
        create(arr, k);
        printf("\n   %d\t\t  %d\t\t\t%f\t\t\t%f\t\t\t%f", i + 1, k, timeTakentoSortSorted(arr, k), timeTakentoSortReverselySorted(arr, k), timeTakentoSortUnsorted(arr, k));
        k += 5000;
    }
}

int main()
{
    int n, arr[50001];
    printf("\n\n*** Main Menu ***\n");
    int t;
    while (t != 1)
    {
        printf("\n\n1. Quit the program\n");
        printf("2. Generate n random numbers and store it in an array A[n]\n");
        printf("3. Display the contents of the array A[n]\n");
        printf("4. Sort the Array by using insertion sorting method\n");
        printf("5. Reverse sort the Array by using insertion sorting method\n");
        printf("6. Sort the Array by using any other sorting method\n");
        printf("7. Reverse sort the Array by using any other sorting method\n");
        printf("8. Display CPU time required to sort the unsorted version of A[n]\n");
        printf("9. Display CPU time required to sort the already sorted version of A[n]\n");
        printf("10. Display CPU time required to sort the reversely sorted version of A[n]\n");
        printf("11. Create a table having 10 rows in the following format for different choices of array A[n] where array size n ranges from 5000 to 50000 with step of 5000\n");
        printf("\n\nChoose any option = ");
        scanf("%d", &t);
        switch (t)
        {
        case 1:
            exit(1);
            break;

        case 2:
            printf("\nEnter the value of n = ");
            scanf("%d", &n);
            create(arr, n);
            break;

        case 3:
            printf("\nArray = ");
            display(arr, n);
            break;

        case 4:
            printf("\nSorted Array = ");
            insertionSort(arr, n);
            display(arr, n);
            break;

        case 5:
            printf("\nReverse sorted Array = ");
            reverseInsertionSort(arr, n);
            display(arr, n);
            break;

        case 6:
            printf("\nSorted Array = ");
            otherSortingMethod(arr, n);
            display(arr, n);
            break;

        case 7:
            printf("\nReverse sorted Array = ");
            otherReverseSortingMethod(arr, n);
            display(arr, n);
            break;

        case 8:
            printf("\nThe elapsed time is %f seconds", timeTakentoSortUnsorted(arr, n));
            break;

        case 9:
            printf("\nThe elapsed time is %f seconds", timeTakentoSortSorted(arr, n));
            break;

        case 10:
            printf("\nThe elapsed time is %f seconds", timeTakentoSortReverselySorted(arr, n));
            break;

        case 11:
            table(arr);
            break;

        default:
            printf("Enter a valid choice");
            break;
        }
    }

    return 0;
}