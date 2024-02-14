#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};

struct node *top;

void display(){
    if(top==NULL){
        printf("Stack is empty");
    }
    
    else{
        struct node *ptr;
        ptr=top;
        while(ptr!=NULL){
            printf("\t%d\t",ptr->data);
            ptr=ptr->link;
        }
    }
}

void push(){
    int element;
    printf("Enter the element to be pushed : ");
    scanf("%d",&element);
    
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=element;
    new->link=top;
    top=new;
    
    display();
}

void pop(){
    if(top==NULL){
        printf("Stack is empty.Cannot delete");
    }
    
    else{
        struct node *temp;
        temp=top;
        top=top->link;
        free(temp);
        
        display();
    }
    
}
    
 
void main(){
    int choice;

    do{
        printf("\n1--PUSH\n");
        printf("\n2--POP\n");
        printf("\n3--DISPLAY\n");
        printf("\n4--EXIT\n");
    
        printf("ENTER YOUR CHOICE : \n");
        scanf("%d",&choice);
    
        switch(choice){
            case 1:
            push();
            break;
        
            case 2:
            pop();
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


        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
