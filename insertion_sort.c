#include<stdio.h>

void insertion_sort(int arr[], int size)
{
    int j = 0;
    for(int i = 1;i < size;i++)
    {
        int temp = arr[i];
        for(j = i-1;j >= 0 && arr[j] > temp;j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j+1] = temp;
    }
}

int main()
{
    int n;
    printf("Enter n value: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &arr[i]);
    }
    int data;
    insertion_sort(arr,n);
    printf("After sorting, Array elements are: ");
    for(int i = 0;i < n;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}