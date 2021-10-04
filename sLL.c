#include<stdio.h>
#include<stdlib.h>
struct node
{
   int information;
   struct node *next;
}*start=NULL;
typedef struct node NODE;

void creatsll()
{
   NODE *node;
   char ch;
   node=(NODE *)malloc(sizeof(NODE));
   start=node;
   printf("\nEnter data: ");
   scanf("%d",&node->information);
   printf("\nDo you want to more (y/n): ");
   scanf("%c",&ch);
   ch=getchar();
   while(ch !='n' && ch != 'N')
   {
      node->next=(NODE *)malloc(sizeof(NODE));
      node=node->next;
      printf("\nEnter data: ");
      scanf("%d",&node->information);
      printf("\nDo you want to more (y/n): ");
      scanf("%c",&ch);
      ch=getchar();
   }
   node->next=NULL;
}
void display()
{
   NODE *i;
   printf("\nElements are :");
   if(start==NULL)
   {
      printf("List is empty");
      return;
   }
   else
   {
      i=start;
      while(i!=NULL)
      {
         printf(" %d ",i->information);
         i=i->next;
      }
   }
}
void insert_begin()
{
   NODE *head;
   head=(NODE *)malloc(sizeof(NODE));
   printf("\nEnter data at begin: \n");
   scanf("%d",&head->information);
   head->next=start;
   start=head;
   
}

void insert_any_position()
{
   NODE *head,*p; 
   int i,position;
   head=(NODE *)malloc(sizeof(NODE));
   printf("\nEnter the position where you want to insert data: ");
   scanf("%d",&position);
   printf("\nEnter data: ");
   scanf("%d",&head->information);
   if(start==NULL)
   {
      start=head;
      head->next=NULL;
   }
   p=start;
   for(i=1;i<position-1 && p!=NULL;i++)
   {
      p=p->next;
   }
   head->next=p->next;
   p->next=head;
}

void insert_end()
{
   NODE *newnode,*i; 
   newnode=(NODE *)malloc(sizeof(NODE));
   printf("Enter data at end: ");
   scanf("%d",&newnode->information);
   i=start;
   while(i->next!=NULL)
   {
      i=i->next;
   }
   i->next=newnode;
   
}

void delete_begin()
{
   NODE *head;
   if(start==NULL)
   {
      printf("\n List is empty !!");
   }
   head=start;
   start=head->next;
   printf("\nDeleted element from begin: %d\n",head->information);
   free(head); 
}
void delete_end()
{
   NODE *head,*p;  //head = temp
   if(start==NULL)
   {
      printf("\nList is empty");
      return;
   }
   else if(start->next == NULL)
   {
      p=start;
      start=NULL;
      printf("\nElement deleted from end : %d\n",p->information);
      free(p);
   }
   else
   {
      p=start;
      while(p->next!=NULL)
      {
         head=p;
         p=p->next;
      }
      head->next=NULL;
      printf("\nElement deleted from end : %d\n",p->information);
      free(p);
   }
  
} 
void delete_any_position()
{
   NODE *ptr;
   NODE *temp;//temp=prev
   int i,position;
   if(start==NULL)
   {
      printf("\nlist is empty !!");
      return;
   }
   printf("\nEnter postion to delete : ");
   scanf("%d",&position);
   for(i=1,ptr=start;i<position;i++)
   {
      temp=ptr;
      ptr=ptr->next;
   }
   if(temp==NULL)
   {
      printf("\nPosition not valid :");
      return;
   }
   temp->next=ptr->next;
   printf("\nDeleted data is :%d",ptr->information);
   free(ptr);
}  

int main()
{
   int option;
   while(1)
   {
      printf("\n0.creat_SLL\n1.Insert_begin \n2.Insert_end\n3.Insert_any_position\n4.delate_begin\n5.delate_end\n6.delate_any_position\n7.Display_element\n8.Exit\n");
   
      printf("\nEnter your choise: ");
      scanf("%d",&option);
      switch(option)
        {
           case 0:
           creatsll();
           break;
           case 1:
           insert_begin();
           break;
           case 3:
           insert_end();
           break;
           insert_any_position();
           break;
           case 4:
           delete_begin();
           break;
           case 5:
           delete_end();
           break;
           case 6:
           delete_any_position();
           break;
           case 7:
           display();
           break;
           case 8:
           exit(0);
           default:
           printf("\nInvalid choise !!");
        }
    }
      
      
}
   
   


