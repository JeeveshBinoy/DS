#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};

struct node *front,*rear;

void display(){
    if(front==NULL){
        printf("Queue is empty");
    }
    
    else{
        struct node *ptr;
        ptr=front;
        while(ptr!=NULL){
            printf("\t%d\t",ptr->data);
            ptr=ptr->link;
        }
    }
}

void enqueue(){
    int element;
    printf("Enter the element to be inserted : ");
    scanf("%d",&element);
    
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=element;
    new->link=NULL;
    
    if(front==NULL){
        front=rear=new;
    }
    
    else{
        
        rear->link=new;
        rear=new;
    }
    
    display();
}

void dequeue(){
    if(front==NULL){
        printf("Queue is empty.Cannot delete");
    }
    
    else if(front==rear){
        struct node *temp;
        temp=front;
        front=rear=NULL;
        free(temp);
    }
    
    else{
        struct node *temp;
        temp=front;
        front=front->link;
        free(temp);
        
        display();
    }
    
}
    
 
void main(){
    int choice;

    do{
        printf("\n1--ENQUEUE\n");
        printf("\n2--DEQUEUE\n");
        printf("\n3--DISPLAY\n");
        printf("\n4--EXIT\n");
    
        printf("ENTER YOUR CHOICE : \n");
        scanf("%d",&choice);
    
        switch(choice){
            case 1:
            enqueue();
            break;
        
            case 2:
            dequeue();
            break;
        
            case 3:
            display();
            break;
        
            case 4:
            break;
        
            default :
            printf("Invalid entry");
        }
    }while(choice!=4);
}


        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
