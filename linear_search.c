#include<stdio.h>

int linear_search(int arr[], int n, int data)
{
    int i = 0;
    for(i = 0;i < n;i++)
    {
        if(arr[i] == data)
        {
            printf("Element found at index: %d\n", i);
            break;
        }
    }
    if(i == n)
    {
        printf("Element not found\n");
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
    printf("Enter data to be searched: ");
    scanf("%d", &data);
    linear_search(arr, n, data);
}