#include<stdio.h>
void swap(int *a,int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}

void bubble_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        
        for(int j=0;j<n-i-1;j++)
        {
           if(arr[j]>arr[j+1])
           {
            swap(&arr[j],&arr[j+1]);
           }
        }
    }
}
void print_arr(int arr[],int n)
{


        for(int i=0;i<n;i++)
        {
            printf("the sorted array is %d\n",arr[i]);
        }
}

    int main()
    {
int arr[5]={2,9,7,3,4};
int n= sizeof(arr)/sizeof( arr[0]);

bubble_sort(arr,n);
print_arr(arr,n);
return 0;
    }
