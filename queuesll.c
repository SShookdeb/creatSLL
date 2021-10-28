#include<stdio.h>
#include<stdlib.h>

struct node 
{
   int information;
   struct node *next;
};
typedef struct node NODE;

NODE *frst_prsn_in_line=NULL, *last_prsn_in_line=NULL;

void enquue(int valkari)
{  
   NODE *newPerson;
   newPerson = (NODE *)malloc(sizeof(NODE));
   newPerson->information = valkari;
   if(frst_prsn_in_line == NULL && last_prsn_in_line == NULL)
   {
      frst_prsn_in_line = last_prsn_in_line = newPerson;
      return;
   }
   else
   {
      last_prsn_in_line->next = newPerson;
      last_prsn_in_line = newPerson;
   }
}

void dequue()
{
   NODE *remove;
   if(frst_prsn_in_line==NULL)
   {
      printf("Queue is Empty !");
   }
   else
   {
      remove = frst_prsn_in_line;
      frst_prsn_in_line = frst_prsn_in_line->next;
      if(frst_prsn_in_line == NULL)
      {
        last_prsn_in_line=NULL;
      }
      free(remove);
   }
}


void DisPlay()
{
   NODE *i;
   i=frst_prsn_in_line;
   while(i)
   {
      printf("%d->",i->information);
      i=i->next;
   }
   printf("NULL\n");
}   
   
int main()
{
  enquue(10);
  enquue(20);
  enquue(30);
  printf("\nQueue: ");
  DisPlay();
  dequue();
  printf("\nAfter dequue new Queue is: ");
  DisPlay();
  dequue();
  printf("\nAfter dequue new Queue is: ");
  DisPlay();
  return 0;
}   
   
   




   
   

