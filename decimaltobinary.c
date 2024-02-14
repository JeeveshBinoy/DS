#include <stdio.h>

int A[100],top,size;

void push(int data){
    
    
    if(top==size-1){
        printf("Stack Overflow");
    }
    
    else{

        top++;
        A[top]=data;
    }
}

int pop(){
    int v;
    if(top==-1){
        printf("Stack Underflow");
    }
    
    else{
        v=A[top];
        top--;
    }
    return v;
}

void display(){
    
    if(top==-1){
        printf("Stack is empty");
    }
    
    while(top!=-1){
        printf("%d",pop());
    }
}


void deccon(int n){

    while(n!=0){
        push(n%16);
        n=n/16;
        }
        
}
    
   
int main(){
    int n,data;
    top=-1;
    int choice;
    printf("Enter the size of the stack : ");
    scanf("%d",&size);
    
    printf("Enter the decimal number : ");
    scanf("%d",&n);
    
    deccon(n);
    display();
   
    
    
return 0;
}
    
