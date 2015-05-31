#include<stdio.h>
struct poly
{
   int number;
   struct poly *next;
};
struct poly*createempty()
{
    struct poly*head;
    head=(struct poly*)malloc(1* sizeof(struct poly));
    head->next=NULL;
    return(head);
}

void read(struct poly*p)
{
    struct poly*tmp;
    int i,n,a;
    printf("Enter the no of terms");
    scanf("%d",&n);
    tmp=p;
    for(i=0;i<n;i++)
    {
       struct poly*new;
       new=(struct poly*)malloc(1*sizeof(struct poly));
       printf("Enter the number");
       scanf("%d",&a);
       new->number=a;
       new->next=NULL;
       tmp->next=new;
       tmp=new;
    }
}

void printlist(struct poly *result)
{
    struct poly *temp;
    temp=result->next;
    while(temp!=NULL)
    {
        printf("Number\t");
        printf("%d",temp->number);
        printf("\t");
        temp=temp->next;
    }
}

void main()
{
    struct poly*p1;
    p1=createempty();
    read(p1);
    printlist(p1);
}
