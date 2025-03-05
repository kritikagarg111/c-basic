#include<stdio.h>
int main()
{
    int i,size,a[10],pos,item;
    printf("enter the size");
    scanf("%d",&size);
    printf("enter the elements of array");
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    
    }
    printf("enter the position");
    scanf("%d",&pos);
    if(pos<1||pos>size)
    {
        printf("invalid data");
    }
    else{
        if(pos==1)
        {
            for(i=0;i<size;i++)
            {
                a[i]=a[i+1];
            }
            size--;
        }
        else{
            for(i=pos-1;i<size-1;i++) 
            {
                a[i]=a[i+1];
            }
            size--;       
            }
            printf("updated array");
                for(i=0;i<size;i++)
            {
              printf("array is %d",a[i]);
                
            }

            
            
    }
return 0;
    
}

