#include<stdio.h>
struct node
{
    int id;
    struct node *next;
};
typedef struct node * NODE;

NODE createEmpty()
{
    NODE head;
    head=(NODE)malloc(1*sizeof(NODE));
    head->next=NULL;
    return head;
}


NODE createList(NODE head)
{
    int i,n;
    NODE temp;
    temp=head;
    printf("Enter the no of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int inp;
        NODE nnode;
        nnode=(NODE)malloc(1*sizeof(NODE));
        scanf("%d",&inp);
        nnode->id=inp;
        nnode->next=NULL;
        head->next=nnode;
        head=nnode;
    }
    return temp;
}

NODE displayList(NODE head)
{
    NODE list;
    list=head->next;
    printf("\nBefore while loop in displayList\n");
    while(list!=NULL)
    {
        printf("%d\t",list->id);
        list=list->next;
    }
    printf("\nAfter while loop in displayList\n");
}

NODE findMiddleNode(NODE list)
{
    NODE slowptr,fastptr;
    int f=0;
    slowptr=list;
    fastptr=list;
    while(fastptr->next!=NULL)
    {
        if(f==0)
        {
            fastptr=fastptr->next;
            f=1;
        }
        else
        {
            fastptr=fastptr->next;
            slowptr=slowptr->next;
            f=0;
        }
    }
    return slowptr;

}
void FrontBackSplit(NODE head)
{
    NODE list,mid,list2;
    list2=createEmpty();
    mid=findMiddleNode(head->next);
    list2->next=mid->next;
    mid->next=NULL;
    printf("Front list is");
    displayList(head);
    printf("Back list is");
    displayList(list2);
}

void main()
{
    NODE head,head2;
    head=createEmpty();
    head2=createList(head);
    printf("Given 1st list is \n");
    displayList(head2);
    FrontBackSplit(head2);

}


