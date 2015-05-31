#include<stdio.h>
struct node
{
    int id;
    struct node *next;
};
typedef struct node * NODE;

void MoveNode(NODE desthead,NODE srchead)
{
    NODE newNode=srchead;
    //assert(newNode !=NULL);
    srchead=newNode->next;
    newNode->next=desthead;
    desthead=newNode;
}

void AlternatingSplit(NODE head, NODE a,NODE b)
{
    NODE atemp=NULL;
    NODE btemp=NULL;
    NODE current=head;

    while(current!=NULL)
    {
        MoveNode(atemp,current);
        if(current !=NULL)
        {
            MoveNode(btemp,current);
        }
    }
    a=atemp;
    b=btemp;
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

void splitList(NODE temp,NODE head2)
{
    NODE list,thead2;
    list=temp->next;
    thead2=head2;
    printf("\nInside split list");
    while(list !=NULL && list->next !=NULL)
    {
        printf("inside while loop");
        head2->next=list->next;
        head2=head2->next;
        list->next=list->next->next;
        list=list->next;
    }
    head2->next=NULL;
    printf("\nAfter while loop inside split list");
    printf("One split list having odd position elements is");
    displayList(temp);
    printf("Another list having even position elements is ");
    displayList(thead2);
}

void main()
{
    NODE head,temp,head2;
    head=createEmpty();
    temp=createList(head);
    printf("Given list is \n");
    displayList(temp);
    head2=createEmpty();
    splitList(temp,head2);
}
