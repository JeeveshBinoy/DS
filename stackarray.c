#include <stdio.h>

int A[100],top,size;

void push(){
    int data;
    
    if(top==size-1){
        printf("Stack Overflow");
    }
    
    else{
        printf("Enter the data to be pushed : ");
        scanf("%d",&data);
        top++;
        A[top]=data;
    }
}

void pop(){
    if(top==-1){
        printf("Stack Underflow");
    }
    
    else{
        printf("Popped element is %d",A[top]);
        top--;
    }
}

void display(){
    int i;
    if(top==-1){
        printf("Stack is empty");
    }
    
    else{
        for(i=0;i<=top;i++){
            printf("%d\t",A[i]);
        }
    }
}

void isfull(){
    if(top==size-1){
        printf("Stack is full");
    }
    else{
        printf("Stack is not full");
    }
        
}

void isempty(){
    if(top==-1){
        printf("Stack is empty");
    }
    else{
        printf("Stack is not empty");
    }
}

void peek(){
    printf("Element present at the top of the stack : %d",A[top]);
}

   
int main(){
    top=-1;
    int choice;
    printf("Enter the size of the stack : ");
    scanf("%d",&size);
    
    do{
        printf("\n1-->PUSH\n");
        printf("2-->POP\n");  
        printf("3-->DISPLAY\n");
        printf("4-->ISFULL\n");
        printf("5-->ISEMPTY\n");
        printf("6-->PEEK\n");
        printf("7-->EXIT\n"); 
        printf("Enter the choice\n");
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
            isfull();
            break;
            
            case 5:
            isempty();
            break;
            
            case 6:
            peek();
            break;
            
            case 7:
            break; 
            
            default:
            printf("Invalid choice");
            
        }
    }while(choice!=7);
    
return 0;

}
    
    
