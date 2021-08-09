//BINARY SERACH TREE
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *rptr,*lptr;
}*root=NULL;
struct node *ptr,*parent;
void insert_bst(int n)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=n;
    new->lptr=NULL;
    new->rptr=NULL;
    if(root==NULL)
    {
        root=new;
    }
    else
    {
        ptr=root;
        parent=NULL;
        while (ptr != NULL)
        {
            parent=ptr;
            if(n<ptr->data)
            ptr=ptr->lptr;
            else
            ptr=ptr->rptr;
        }
        if(n<parent->data)
        parent->lptr=new;
        else
        parent->rptr=new;
    }
}
void search(int x)
{
    int f=0;
    ptr=root;
    while(ptr!=NULL)
    {
        if(ptr->data==x)
        {
            f++;
            break;
        }
        else 
        {
            parent=ptr;
            if(x<ptr->data)
            ptr=ptr->lptr;
            else
            ptr=ptr->rptr;
        }
    }
        if(f==1)
        printf("\n Data is available ");
        else
        printf("\n Data is not available "); 
}
int main()
{
    int c,n,x,e=1;
    while (e==1)
    {
        printf("\n MENU ");
        printf("\n 1. INSERT ");
        printf("\n 2. SERACH ");
        printf("\n 3. EXIT");
        printf("\n 4. ENTER THE CHOICE ");
        scanf("%d",&c);
        switch(c)
        {
            case 1 :
            printf("\n enter the value to enter : ");
            scanf("%d",&n);
            insert_bst(n);
            break;
            case 2 :
            printf("\n enter the element to serach ");
            scanf("%d",&x);
            search(x);
            break;
            case 3 :
            e=0;
            break;
            default :
            printf("\n wrong option ");    
        }
    }
}