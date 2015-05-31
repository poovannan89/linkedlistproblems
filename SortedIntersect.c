#include<stdio.h>
struct node
{
    int id;
    struct node *next;
};
typedef struct node * NODE;

NODE deleteList(NODE head)
{
    NODE current,next;
    current=head;
    while(current!=NULL)
    {
        next=current->next;
        free(current);
        current=next;
    }
    head=NULL;

}


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
    NODE temp,list=NULL,prev=NULL;
    temp=head;
    printf("Enter the no of elements\n");
    scanf("%d",&n);
    prev=head;
    for(i=0;i<n;i++)
    {
        int inp;
        NODE nnode;
        nnode=(NODE)malloc(1*sizeof(NODE));
        scanf("%d",&inp);
        nnode->id=inp;
        if(head->next==NULL)
        {
            nnode->next=NULL;
            head->next=nnode;
        }
        else
        {
            list=head->next;
            while(list!=NULL && list->id<inp)
            {
                prev=list;
                list=list->next;
            }
            prev->next=nnode;
            nnode->next=list;
        }
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

void sortedIntersect(NODE head,NODE head2)
{
    NODE head3,thead3,list,list2,nnode,list3;
    head3=createEmpty();
    thead3=head3;
    list=head->next;
    list2=head2->next;
    list3=head3->next;
    printf("\nInside sorted Intersect");
    while(list!=NULL && list2!=NULL)
    {
        if(list->id==list2->id)
        {
            printf("\nCommon element is %d\n",list->id);
            nnode=(NODE)malloc(1*sizeof(NODE));
            nnode->id=list->id;
            nnode->next=NULL;
            if(head3->next==NULL)
            {
                head3->next=nnode;
                list3=nnode;
            }
            else
            {
                list3->next=nnode;
                list3=nnode;
            }
            list=list->next;
            list2=list2->next;
        }
        else
        {
            printf("\nInside not intersecting elements\n");
            if(list->id<list2->id)
            {
                while(list->id<list2->id)
                {
                    list=list->next;
                }
            }
            else
            {
                while(list2->id<list->id)
                {
                    list2=list2->next;
                }
            }
        }
    }
    printf("Intersection of given list is");
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
    sortedIntersect(head,head2);
}


