#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};


struct node *head;

void display(){
    if(head==NULL){
        printf("Linked list is empty");
    }
    
    else{
        struct node *ptr;
        ptr=head;
        
        while(ptr!=NULL){
            printf("%d\t",ptr->data);
            ptr=ptr->next;
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
    new->prev=new->next=NULL;
    
    if(head==NULL){
        head=new;
    }
    
    else{
        new->next=head;
        head->prev=new;
        head=new;
    }
}
    
    
    

void insert_at_end(){
    int element;
    printf("Enter the element to be inserted : ");
    scanf("%d",&element);
    
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=element;
    new->prev=new->next=NULL;
    
    if(head==NULL){
        head=new;
    }
    
    else{
        struct node *ptr;
        ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        
        ptr->next=new;
        new->prev=ptr;
    }
}



    

void insert_after(){
    int key,element;
    printf("Enter the element after which node is to be inserted : ");
    scanf("%d",&key);
    
    printf("Enter the element to be inserted : ");
    scanf("%d",&element);
    
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=element;
    new->prev=new->next=NULL;
    
    if(head==NULL){
        printf("List is empty,element not found");
    }
    
    else{
        struct node *ptr;
        ptr=head;
        while(ptr->next!=NULL && ptr->data!=key){
            ptr=ptr->next;
        }
        
            if(ptr->data!=key){
                printf("Entered element is not found");
            }
        
            else{
            
                new->prev=ptr;
                new->next=ptr->next;
                
                if(new->next!=NULL){
                new->next->prev=new;
                }
                ptr->next=new;
             
            }
        
    }
}
    
void delete_at_front(){
    if(head==NULL){
    printf("List is empty");
    }
    
    else if(head->next==NULL){
        struct node *temp;
        temp=head;
        head=NULL;
        free(temp);
    }
    
    else{
        struct node *temp;
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
    
    
}
     
            

void delete_at_end(){
    if(head==NULL){
    printf("List is empty");
    }
    
    else if(head->next==NULL){
        struct node *temp;
        temp=head;
        head=NULL;
        free(temp);
    }
    
    else{
        struct node *ptr,*temp;
        ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        temp=ptr->prev;
        temp->next=NULL;
        free(ptr);
        
        
        
    }
}
    

void delete_node(){
    int key,element;
    printf("Enter the element after which node is to be deleted : ");
    scanf("%d",&key);
    
    if(head==NULL){
        printf("Linked list is empty,cannot delete");
    }
    
    else if(head->next==NULL){
        if(head->data==key){
            struct node *temp;
            temp=head;
            head=NULL;
            free(temp);
        }
        else{
            printf("element not found");
        }
    }
    
    else{
        struct node *ptr,*temp;
        ptr=head;
        while(ptr->next!=NULL && ptr->data!=key){
            ptr=ptr->next;
        }
            if(ptr->data!=key){
                printf("Element not present");
            }
            
            else{
                temp=ptr->prev;
                temp->next=ptr->next;
                if(ptr->next!=NULL){
                    ptr->next->prev=temp;
                }
                free(ptr);
            
            
                
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
        
    
