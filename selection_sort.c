#include<stdio.h>
void swap(int *a,int*b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    
}

void selection_sort(int arr[],int n)
{
    
    for(int i=0;i<n-1;i++)
    {
        int SI=i;
        for(int j=i+1;j<n;j++)
        {
           if(arr[j]<arr[SI])
           {
        SI=j;
           }
           swap(&arr[i],&arr[SI]);
        }

    }
}
void print_array(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("the elelments of sorted array are:%d\n",arr[i]);
    }
}
int main()
{

    int arr[5]={3,2,5,4,1};
    
    int n=sizeof(arr)/sizeof (arr[0]);
    selection_sort(arr,n);
    print_array(arr,n);
    return 0;


}