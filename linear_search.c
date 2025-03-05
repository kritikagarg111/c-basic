#include<stdio.h>

int linear_search(int ar[],int n,int key)

{
    for(int i=0;i<n;i++)
    {
        if(ar[i]==key)
        {
          return i;
        }
    }
    return -1;
}



int main()
{
int ar[5]={1,2,3,4,5};
    int n=sizeof(ar)/sizeof(ar[0]);
for(int i=0;i<5;i++)
{
    printf("the ar[%d] is %d\n",i,ar[i]);
}
int key=4;
  int result = linear_search(ar, n, key);

    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array\n", key);
    }


return 0;
}