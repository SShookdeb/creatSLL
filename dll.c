#include<stdio.h>
#include<stdlib.h>
struct double_node
{  
   struct double_node *left;
   int information;
   struct double_node *right;
}*start=NULL;
typedef struct double_node D_NODE; //double_node is rename as D_NODE
//creating dLL

void createdll()
{
   D_NODE *node;
   char ch;
   node=(D_NODE*)malloc(sizeof(D_NODE));
   node->left=NULL;
   start=node;
   printf("\nEnter data: ");
   scanf("%d",&node->information);
   printf("\nDo you insert again (y/n): ");
   scanf("%c",&ch);
   ch=getchar();
   while(ch != 'n' && ch != 'N')
   {
      node->right=(D_NODE*)malloc(sizeof(D_NODE));
      node->right->left=node;
      node=node->right;
      printf("\nEnter data again : ");
      scanf("%d",&node->information);
      printf("\nDo you want to insert again (y/n): ");
      scanf("%c",&ch);
      ch=getchar();
   }
   node->right=NULL;      
}

//Display nodes of DLL

void display()
{
   D_NODE *i;
   int n=1;
   printf("\nDisplay the elements of DLL: \n");
   if(start==NULL)
   {
      printf("\n...List is Empty...!!\n");
      return;
   }
   else
   {
     i=start;
     while(i != NULL)
     { 
        printf("\nnode %d : %d\n",n,i->information);
        n++;
        i=i->right;
        
     }
   }
}
void insert_begin()
{
   D_NODE *ptr;
   ptr=(D_NODE*)malloc(sizeof(D_NODE));
   printf("\n Enter data at begin :");
   scanf("%d",&ptr->information);
   ptr->right=NULL;
   if(start==NULL)
   {
      ptr->right=start;
      start=ptr;
   }
   else{
   start->left=ptr;
   ptr->right=start;
   start=ptr;
   }
   
}

void insert_end_dll()
{
   D_NODE *puti,*litu_khan;
   puti=(D_NODE *)malloc(sizeof(D_NODE));
   printf("Enter data part : ");
   scanf("%d",&puti->information);
   
   if(start->right==NULL)
   {
      puti->left=start;
      start=puti;
   }else{
   litu_khan=start;
   while(litu_khan->right !=NULL)
        {
            litu_khan=litu_khan->right;
        }
   puti->left = litu_khan;
   litu_khan->right =puti;
   puti->right= NULL;
   }
}
//insert an element at specific location

void insert_any_location()
{
   D_NODE *joker,*tail,*stop;//
   int i, loc ;
   joker=(D_NODE *)malloc(sizeof(D_NODE));
   printf ("\n Enter the data: ");
   scanf("%d",&joker->information);
   printf("\nEnter the position: ");
   scanf("%d",&loc);
   stop=start;
   if(stop==NULL)
      {
         printf("List is empty !");
         return;
      }
   for(i=1; i<loc; i++)
   {
      tail=stop;
      stop=stop->right;
   }
   joker->right=stop;
   joker->left=tail;
   tail->right=joker;
   stop->left=joker;
   
}

void delete_at_begin()
{
   D_NODE *head;
   if(start == NULL)
   {
      printf("list is Empty");
      return;
   }
   else if(start->left==NULL && start->right==NULL)
   {
      head=start;
      start=NULL;
      printf("Deleted element is: %d",head->information);
      free(head);
      return;
   }
   else
   {
      head=start;
      start=start->right;
      start->left=NULL;
      printf("\nDelete element from begin: %d",head->information);
      free(head);
   }
}

void delete_from_end()
{
   D_NODE *head,*ptr;
   if(start==NULL)
   {
      printf("List is empty !");
      return;
   }
   else if(start->left==NULL && start->right==NULL)
   {
      head=start;
      start=NULL;
      printf("Deleted element is: %d",head->information);
      free(head);
      return;
   }
   ptr=start;
   while(ptr->right!=NULL)
   {
      ptr=ptr->right;
   }
   ptr->left->right=NULL;
   free(ptr);
   printf("\nNode deleted");
   
}


int main()
{
   createdll();
   display();
   insert_begin();
   display();
   insert_end_dll();
   display();
   insert_any_location();
   display();
   delete_from_end();
   delete_at_begin();
   display();
}






