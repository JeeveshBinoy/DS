 #include<stdio.h>
#include<stdlib.h>

struct Node{
       int data;
       struct Node *next;
       };
       
void countnodes(struct Node *head){
     int count=0;
     if(head==NULL)
     printf("Linked list is empty");
     
     struct Node *ptr;
     ptr=head;
     while(ptr!=NULL){
     count++;
     ptr=ptr->next;
     }
     printf("Number of nodes :%d",count);
     }

    
int main(){
    struct Node *head=(struct Node*)malloc(sizeof(struct Node));
    
    head->data=45;
    head->next=NULL;
    
    struct Node *current=(struct Node *)malloc(sizeof(struct Node));
    current->data=90;
    current->next=NULL;
    head->next=current;
    
    current=malloc(sizeof(struct Node));
    current->data=180;
    current->next=NULL;
    
    head->next->next=current;
    
    printf("%d->%d->%d\n",head->data,head->next->data,current->data);
    countnodes(head);
    
    return 0;
    }
