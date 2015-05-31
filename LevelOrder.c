#include<stdio.h>
#define maxi 100

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node * NODE;

struct queue
{
    NODE a[maxi];
    int front,rear,cap,size;
};
typedef struct queue * QUEUE;
QUEUE empty()
{
    QUEUE q;
    q=(QUEUE)malloc(1*sizeof(QUEUE));
    q->rear=-1;
    q->front=0;
    q->cap=maxi;
    q->size=0;
    return q;
}

int checkempty(QUEUE q)
{
    if(q->size==0)
        return 1;
    else
        return 0;
}

void enqueue(QUEUE q,NODE h)
{
    if(q->size<q->cap)
    {
        if(q->rear<q->cap-1)
        {
            q->rear+=1;
        }
        else
        {
            q->rear=0;
        }
        q->a[q->rear]=h;
        q->size+=1;
    }
}

NODE dequeue(QUEUE q)
{
    if(q->size!=0)
    {
        NODE h;
        h=q->a[q->front];
        if(q->front<q->cap-1)
            q->front+=1;
        else
        {
            q->front=0;
        }
        q->size-=1;
        return h;
    }
}

NODE newNode(int data)
{
    NODE nnode;
    nnode=(NODE)malloc(1*sizeof(NODE));
    if(NULL==nnode)
    {
        printf("\nMemory out of space\n");
        return;
    }
    nnode->data=data;
    nnode->left=NULL;
    nnode->right=NULL;
    return nnode;
}


NODE insert(NODE root,int data)
{
    if(root==NULL)
        return newNode(data);
    else
    {
        if(data<root->data)
        {
            root->left=insert(root->left,data);
        }
        else if(data>root->data)
        {
            root->right=insert(root->right,data);
        }
        else
        {
            printf("\nElement is already present in the tree");
        }
        return root;
    }
}

void inorder(NODE root)
{
    if(root==NULL)
        return;
    else
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

void LevelOrder(NODE root)
{
    printf("\nInside level order\n");
    NODE temp,flgnode;
    flgnode=newNode(-1);
    QUEUE q2=empty();
    if(root==NULL)
        return;
    enqueue(q2,flgnode);
    enqueue(q2,root);
    while(!checkempty(q2))
    {
        //printf("\nQueue size is %d\n",q2->size);
        temp=dequeue(q2);
        if(temp->data==-1)
        {
            printf("--------");
            enqueue(q2,flgnode);
        }
        else
        {
            printf("%d\t",temp->data);
            if(temp->left!=NULL)
                enqueue(q2,temp->left);
            if(temp->right!=NULL)
                enqueue(q2,temp->right);
        }

    }
    printf("\nAfter while loop\n");
}


void main()
{
    NODE head=NULL;
    head=insert(head,4);
    head=insert(head,2);
    head=insert(head,8);
    head=insert(head,9);
    head=insert(head,5);
    head=insert(head,1);
    head=insert(head,7);
    //inorder(head);
    LevelOrder(head);

}
