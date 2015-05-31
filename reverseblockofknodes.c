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
    return NULL;
}

NODE GetKPlusOneThNode(int k,NODE head)
{
    NODE Kth;
    int i=0;
    if(!head)
        return head;
    for(i=0,Kth=head;Kth&&(i<k);i++,Kth=Kth->next);
    if(i==k &&Kth!=NULL)
        return Kth;
    return head->next;
}

int HasKnodes(NODE head,int k)
{
    int i=0;
    for(i=0;head && (i<k);i++,head=head->next);
    if(i==k)
        return 1;
    return 0;
}

NODE ReverseBlockofKNodesInLinkedList(NODE head,int k)
{
    NODE cur,temp,next,newHead;
    cur=head;
    int i;
    if(k==0||k==1)
        return head;
    if(HasKnodes(cur,k-1))
        newHead=GetKPlusOneThNode(k,cur);
    else
        newHead=head;
    while(cur && HasKnodes(cur,k))
    {
        temp=GetKPlusOneThNode(k,cur);
        i=0;
        while(i<k)
        {
            next=cur->next;
            cur->next=temp;
            temp=cur;
            cur=next;
            i++;
        }

    }

}


NODE NthNodeFromEnd(NODE head,int NthNode)
{
    NODE pTemp=NULL,pNthNode=head;
    int count=0;
    for(pTemp=head;pTemp!=NULL;)
    {
        count++;
        if(NthNode-count>0)
            pNthNode=pNthNode->next;
        pTemp=pTemp->next;
    }


}



