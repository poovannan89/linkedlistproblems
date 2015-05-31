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

void shuffleMerge(NODE head,NODE head2)
{
    int flag=0;
    NODE head3,thead3,list,list2;
    head3=createEmpty();
    thead3=head3;
    list=head->next;
    list2=head2->next;
    while(list!=NULL && list2!=NULL)
    {
        if(flag==0)
        {
            head3->next=list;
            head3=head3->next;
            list=list->next;
            flag=1;
        }
        else
        {
            head3->next=list2;
            head3=head3->next;
            list2=list2->next;
            flag=0;
        }
    }
    if(list==NULL)
    {
        while(list2!=NULL)
        {
            head3->next=list2;
            head3=head3->next;
            list2=list2->next;
        }
    }
    if(list2==NULL)
    {
        while(list!=NULL)
        {
            head3->next=list;
            head3=head3->next;
            list=list->next;
        }
    }
    printf("Shuffled merge list is");
    displayList(thead3);
}

void main()
{
    NODE head,head2;
    head=createEmpty();
    head=createList(head);
    printf("Given 1st list is \n");
    displayList(head);
    head2=createEmpty();
    head2=createList(head2);
    printf("Given 2nd list is \n");
    displayList(head2);
    shuffleMerge(head,head2);

}

