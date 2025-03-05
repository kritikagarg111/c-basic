#include<stdio.h>

int binary_search(int arr[],int n,int tar)
{
    int st=0;
    int end=n-1;
    
    while(st<=end)
    {
    int mid = (st+end)/2;
        if(tar>arr[mid])
        {
            st=mid+1;
        }
        else if(tar<arr[mid])
        {
            end=mid-1;
        }

        else
        {
            return mid;
        }


    }
    return -1;

}

void print_arr(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf ( "arr[%d] is %d\n",i,arr[i]);
    }
    
    }

    int main()
    {
    int arr[5]={1,6,4,8,3};
    int tar=8;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    // Print the sorted array
    print_arr(arr, 5);
    
    // Perform binary search
    int result = binary_search(arr, 5, tar);
    
    if (result != -1)
    {
        printf("Element %d found at index %d\n", tar, result);
    }
    else
    {
        printf("Element %d not found in the array\n", tar);
    }
    
    return 0;
}
   