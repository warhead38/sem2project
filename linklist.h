#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
   char data[100];
   int key;
   struct node *next;
};
struct node *head=NULL;
struct node *current=NULL;
void printList()
{
   struct node *ptr=head;
   int i=1;
   while(ptr!=NULL){
      //printf("%d \n  %d\n  %s\n",i++,ptr->key,ptr->data);
      printf("(%d) ",i++);
      printf("Name   : %s\n",ptr->data);
      printf("    Rating : (%d/10)\n\n",ptr->key);
      ptr = ptr->next;
   }
}
void insertfirst(int key,int data)
 {
   struct node *link=(struct node*)malloc(sizeof(struct node));
   link->key = key;
   strcpy(link->data,data);
   link->next = head;
   head = link;
}
struct node* deletefirst()
{
   struct node *tempLink = head;
   head = head->next;
   return tempLink;
}
bool isempty()
{
   return head == NULL;
}
int length()
 {
   int length = 0;
   struct node *current;
   for(current=head;current!=NULL;current=current->next)
    {
      length++;
   }
   return length;
}
void sort()
 {

   int i,j,k,tempKey,tempData;
   struct node *current;
   struct node *next;
   int size=length();
   k=size ;
   for(i=0;i<size-1;i++,k--)
    {
      current=head;
      next=head->next;
      for(j=1;j<k;j++)
      {
         if(strcmp(current->data,next->data)>0)
         {
            strcpy(tempData,current->data);
            strcpy(current->data,next->data);
            strcpy(next->data,tempData);
            tempKey = current->key;
            current->key = next->key;
            next->key = tempKey;
         }
         current=current->next;
         next=next->next;
      }
   }
}

