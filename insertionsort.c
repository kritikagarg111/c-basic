#include<stdio.h>

void insertion_sort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int current = arr[i];
        int prev=i-1;
        while(prev>=0&&arr[prev]>current)
        {
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=current;
    }
}
void print_arr(int arr[],int n){
    for(int i=0;i<n;i++)
    {
        printf("the sorted array is %d\n",arr[i]);
    }
}


int main()
{
    int arr[]={1,7,9,3,5};
    
    int n=sizeof(arr)/sizeof (arr[0]);
    insertion_sort(arr,n);
    print_arr(arr,n);
    return 0;
}