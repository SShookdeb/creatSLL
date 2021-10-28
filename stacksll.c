#include<stdio.h>
#include<stdlib.h>
struct node
{
   int information;
   struct node *next;
};

struct node *top=NULL;

void push(int valkari)
{
   //create new node
   struct node *newNode;
   newNode = (struct node *)malloc(sizeof(struct node));
   if(!newNode)
   {
      printf( "\nHeap Overflow");
      return;
   }
   newNode->information=valkari;
   
   //make the new node points to the head node
   newNode->next = top;//here top means start or you can say head
   
   //make the new node as top node
   //so that top will always point the last inserted data 
   top = newNode;
}

void pop()
{
   //temp is used to free the top node
   struct node *temp;
   if(top==NULL)
   {
      printf("Stack is empty!");
      return;
   }
   else
   {
      printf("poped element = %d\n",top->information);
      temp=top;
      //make the top node points to the next node
      //logically removing the node
      top=top->next;
      //free the poped elements memory
      free(temp);
    }
}

//print the link list
void printList()
{
   struct node *tempu;
   if(tempu==NULL)
   {
      printf("\nStack Underflow!");
      return;
   }
   
   //itarate the entire linked list and print the data 
   tempu=top;
   while(tempu!=NULL)
   {
      printf("%d->",tempu->information);
      tempu=tempu->next;
   }
   printf("NULL\n");
}


int main()
{
   push(10);
   push(20);
   push(30);
   printf("Linked List!\n");
   printList();
   pop();
   printf("After the , the new linked list\n");
   printList();
   pop();
   printf("After the pop, the new linked list\n");
   printList();
   
   return 0;
}
      
      
      
   
    

