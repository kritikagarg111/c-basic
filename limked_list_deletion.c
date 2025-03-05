#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;

};
void traversal(struct Node * ptr)
{
    while(ptr!=NULL)
    {
       printf("%d\n",ptr->data);
       ptr=ptr->next;
    }
}

struct Node * deletion_at_beg(struct Node *head)
{
    struct Node * ptr = (struct Node*)malloc(sizeof (struct Node)) ;
    struct Node * ptr= head;
    head= head->next;
free(ptr);
return head;
}


struct Node * deletion_at_index(struct Node *head,int index)
{
    struct Node * ptr = (struct Node*)malloc(sizeof (struct Node)) ;
    struct Node * q = (struct Node*)malloc(sizeof (struct Node)) ;
    struct Node *ptr=head;
    struct node *q=head->next;
    for(int i=0;i<index-1;i++)
    {
        ptr=ptr->next;
        q=q->next;
    }
    ptr->next=q->next;
    free(q);
    return head;
}


struct Node * deletion_at_end(struct Node *head,int index)
{
     struct Node * ptr = (struct Node*)malloc(sizeof (struct Node)) ;
    struct Node * q = (struct Node*)malloc(sizeof (struct Node)) ;
    struct Node *ptr=head;
    struct node *q=head->next;
    while(q->next!=NULL)
    {
        ptr=ptr->next;
        q=q->next;
    }
    ptr->next=NULL;
    free(q);
    return head;

}

struct Node * deletion_at_value(struct Node *head,int value)
{
    struct Node * ptr = (struct Node*)malloc(sizeof (struct Node)) ;
    struct Node * q = (struct Node*)malloc(sizeof (struct Node)) ;
    struct Node *ptr=head;
    struct node *q=head->next;
    while(q->data!=value && q->next!=NULL)
    {
        ptr=ptr->next;
        q=q->next;
    }
    if(q->data==value){
    ptr->next=q->next;
    free(q);
    }

    return head;
}





int main()
{
    struct Node* head;
    struct Node* second;
    struct Node* third;


    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));

    head->data=7;
    head->next=second;

    second->data=11;
    second->next=third;


    third->data=15;
    third->next=NULL;
    printf("linkedkist before deletion\n");
    traversal(head);
    head=deletion_at_beg(head);
    printf("linked list after deletion\n");

    head=deletion_at_index(head,2);
    printf("linked list after deletion");

    head=deletion_at_end(head,3);
    printf("linkedlist after deletion");

    return 0;
}