#include<stdio.h>

void selection_sort(int arr[], int size)
{
    for(int i = 0;i < size;i++)
    {
        int min = i;
        for(int j = i+1;j < size;j++)
        {
            if(arr[min] > arr[j])
            {
                min = j;
            }
        }
        if(min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
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
    selection_sort(arr,n);
    printf("After sorting, Array elements are: ");
    for(int i = 0;i < n;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}