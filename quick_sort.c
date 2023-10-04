#include<stdio.h>
#define SIZE 5

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int start = low;
    int end = high;
    while(start < end)
    {
        while(arr[start] <= pivot)
        {
            start++;
        }
        while(arr[end] > pivot)
        {
            end--;
        }
        if(start < end)
        {
            swap(&arr[start], &arr[end]);
        }
    }
    swap(&arr[low], &arr[end]);
    return end;
}

void quick_sort(int arr[], int low, int high)
{
    if(low < high)
    {
        int loc = partition(arr, low, high);
        quick_sort(arr, low, loc-1);
        quick_sort(arr, loc+1, high);
    }
}

int main()
{
    int arr[SIZE];
    printf("Enter array elements: ");
    for(int i = 0;i < SIZE;i++)
    {
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, SIZE-1);
    printf("Array elements: ");
    for(int i = 0;i < SIZE;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
