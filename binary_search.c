#include<stdio.h>

int binary_search(int arr[], int n, int data)
{
    int l = 0, r = n-1, mid;
    while(l <= r)
    {
        mid = (l+r)/2;
        if(arr[mid] == data)
        {
            return mid;
        }
        else if(data > arr[mid])
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        } 
    }
    return -1;
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
    int index = binary_search(arr, n, data);
    if(index >= 0)
    {
        printf("Element found at index: %d\n", index);
    }
    else
    {
        printf("Element not found\n");
    }
}