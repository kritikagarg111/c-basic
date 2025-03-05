#include<stdio.h>
int main()
{
    int i,size,a[50],pos,num;
    printf("enter the size");
    scanf("%d",&size);
    printf("enter the elements of array");
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
printf("insert element is ");
scanf("%d",&num);
printf("enter the pos");
scanf("%d",&pos);
if(pos==-1||pos>size)
{
    printf("invalid data\n");
}
else{
for(i=size-1;i>=pos-1;i--)
{
    a[i+1]=a[i];
    
    }
    a[pos-1]=num;
    size++;
}
printf("new array");
for(i=0;i<size;i++)
{
    printf("%d\n",a[i]);
}
    return 0;
}
