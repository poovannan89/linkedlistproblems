#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node* NODE;

NODE createempty()
{
    NODE llist;
    llist=(NODE)malloc(1* sizeof(struct node));
    llist->next=NULL;
    return llist;
}

void getinputs(int n,NODE header)
{
    NODE temp,tmp2;
    tmp2=header;
    int dt,i;
    for(i=0;i<n;i++)
    {
        temp=(NODE)malloc(1*sizeof(struct node));
        printf("enter input %d",i+1);
        scanf("%d",&dt);
        temp->data=dt;
        temp->next=NULL;
        tmp2->next=temp;
        tmp2=temp;
    }
}

void displaylist(NODE header)
{
    NODE tmpnode;
    tmpnode=header->next;
    while(tmpnode!=NULL)
    {
        printf("%d------->",tmpnode->data);
        tmpnode=tmpnode->next;
    }
    printf("\n");
}

NODE reverselist(NODE header)
{
    NODE temp4;
    temp


}


void main()
{
        NODE header,rev;
        header=createempty();
        getinputs(5,header);
        displaylist(header);
        rev=reverselist(header);
}
