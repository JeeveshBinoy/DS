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
        while(ptr!=NULL){
            printf("\t%d\t",ptr->data);
            ptr=ptr->link;
        }
    }
}

void insert_at_front(){
    int element;
    printf("Enter the element to be inserted : ");
    scanf("%d",&element);
    
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=element;
    new->link=head;
    head=new;
    
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
        head=new;
    }
        
    struct node *ptr;
    ptr=head;
        
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    
    ptr->link=new;
    
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
        while(ptr->data!=key && ptr->link!=NULL){
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
    }
    display();
}
    
void delete_at_front(){
     if(head==NULL)
        printf("Linked list is empty.Cannot delete");
     
     else{
        struct node *temp;
        temp=head;
        
        head=head->link;
        free(temp);
    }
    display();
}
            

void delete_at_end(){
    if(head==NULL)
        printf("Linked list is empty.Cannot delete");
    
    else if(head->link==NULL){
        struct node *temp;
        temp=head;
        head=NULL;
        free(temp);
    }
    
    else{
       struct node *prev; 
       struct node *current; 
       
       prev=head;
       current=head->link;
       
       while(current->link!=NULL){
        prev=current;
        current=current->link;
       }
    
       prev->link=NULL;
       free(current);
   }
   display();
}

void delete_node(){
    int key;
    printf("Enter the element after which the node is to be inserted : ");
    scanf("%d",&key);
    
    if(head==NULL){
        printf("Linked list is empty");
    }
    
    else if(head->data==key){
        struct node *temp;
        temp=head;
        head=NULL;
        free(temp);
    }
    
    else{
        struct node *prev,*current;
        prev=head;
        current=head;
        
        while(current->data!=key && current->link!=NULL){
            prev=current;
            current=current->link;
        }
        
        if(current->data!=key){
            printf("Entered element is not present in linked list");
        }
        
        else{
            prev->link=current->link;
            free(current);
        }
        
        display();
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
        
    
