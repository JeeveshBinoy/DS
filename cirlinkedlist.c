#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *head;

void display(){
    if(head==NULL)
        printf("Linked list is empty");
    
    else{
        struct node *ptr;
        ptr=head;
        printf("Linked List : ");
        while(ptr->link!=head){
            printf("\t%d\t",ptr->data);
            ptr=ptr->link;
        }
        printf("\t%d\t",ptr->data);
    }
}

void insert_at_front(){
    int element;
    printf("Enter the element to be inserted : ");
    scanf("%d",&element);
    
    struct node *new;
        new=(struct node*)malloc(sizeof(struct node));
        new->data=element;
        new->link=NULL;
    
    if(head==NULL){
        new->link=new;
        head=new;
        
    }
    
    else{
  
        struct node *ptr;
        ptr=head;
        while(ptr->link!=head){
            ptr=ptr->link;
        }
    
        new->link=head;
        head=new;
        ptr->link=head;
    
    }
    display();
}

void insert_at_end(){
    int element;
    printf("Enter the element to be inserted : ");
    scanf("%d",&element);
    
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=element;
    new->link=NULL;
    
    if(head==NULL){
        new->link=new;
        head=new;
    }
    
    else{   
        struct node *ptr;
        ptr=head;
        
        while(ptr->link!=head){
            ptr=ptr->link;
        }
        ptr->link=new;
        new->link=head;
         
    }
    display();
}

void insert_after(){

    int key,element;
    
    printf("Enter the element after which the node is to be inserted : ");
    scanf("%d",&key);
    
    printf("Enter the element to be inserted : ");
    scanf("%d",&element);
    
    struct node *ptr;
    ptr=head;
    
    if(head==NULL){
        printf("Linked List is empty");
    }
    
    else{
        while(ptr->data!=key && ptr->link!=head){
        ptr=ptr->link;
        }
        
        if(ptr->data!=key){
            printf("Entered element is not present in linked list");
        }
        
        else{
            struct node *new;
            new=(struct node*)malloc(sizeof(struct node));
            new->data=element;
            new->link=NULL;
            
            new->link=ptr->link;
            ptr->link=new;
        }
        display();
    }
    
}
    
void delete_at_front(){
     if(head==NULL)
        printf("Linked list is empty.Cannot delete");
     
     else if(head->link==head){
        struct node *temp;
        temp=head;
        head=NULL;
        free(temp);
        
        display();
    }
    
     else{
        struct node *temp,*ptr;
        temp=head;
        ptr=head;
        
        while(ptr->link!=head){
            ptr=ptr->link;
        }
       
        head=head->link;
        ptr->link=head;
        free(temp);
        
        display();
        
    }
    
}
            

void delete_at_end(){
    if(head==NULL)
        printf("Linked list is empty.Cannot delete");
    
    else if(head->link==head){
        struct node *temp;
        temp=head;
        head=NULL;
        free(temp);
        
        display();
    }
    
    else{
       struct node *prev; 
       struct node *current; 
       
       prev=head;
       current=head->link;
       
       while(current->link!=head){
        prev=current;
        current=current->link;
       }
    
       prev->link=head;
       free(current);
       
       display();
   }
   
}

void delete_node(){
    int key;
    printf("Enter the element after which the node is to be deleted: ");
    scanf("%d",&key);
    
    if(head==NULL){
        printf("Linked list is empty");
    }
    
    else if(head->data==key){
        struct node *temp;
        temp=head;
        head=NULL;
        free(temp);
        
        display();
    }
    
    else{
        struct node *prev,*current;
        prev=head;
        current=head;
        
        while(current->data!=key && current->link!=head){
            prev=current;
            current=current->link;
        }
        
        if(current->data!=key){
            printf("Entered element is not present in linked list");
        }
        
        else{
            prev->link=current->link;
            free(current);
            
            display();
        }
        
        
    }
}
    
    
    
        


void main(){
    int choice,data,position;

    do{
        printf("\n1--INSERTION AT FRONT\n");
        printf("\n2--INSERTION AT END\n");
        printf("\n3--INSERTION AFTER\n");
        printf("\n4--DELETION AT FRONT\n");
        printf("\n5--DELETION AT END\n");
        printf("\n6--DELETION OF SPECIFIC NODE\n");
        printf("\n7--DISPLAY\n");
        printf("\n8--EXIT\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        
        switch(choice){
                
            case 1:
            insert_at_front();
            break;
            
            case 2:
            insert_at_end();
            break;
            
            case 3:
            insert_after();
            break;
            
            case 4:
            delete_at_front();
            break;
            
            case 5:
            delete_at_end();
            break;
            
            case 6:
            delete_node();
            break;
            
            case 7:
            display();
            break;
            
            case 8:
            break;
            
            default :
            printf("Invalid Entry");
            
        }   
    }while(choice!=8);
    
}          
        
    
