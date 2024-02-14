#include <stdio.h>
#include <ctype.h>
#include <math.h>

char P[20];
int S[20];
int top=-1;

void push(int data){
    top++;
    S[top]=data;
}

int pop(){
    int x;
    x=S[top];
    top--;
    return x;
}

void postfix_eval(){
    int i,op1,op2;
    char str[20];
    
    for(i=0;P[i]!='\0';i++){
        
        if(isdigit(P[i])){
            push(P[i]-48);
        }
        
        else{
            op2=pop();
            op1=pop();
            
            switch(P[i]){
                case '+':
                push(op1+op2);
                break;
                
                case '-':
                push(op1-op2);
                break;
                
                case '*':
                push(op1*op2);
                break;
                
                case '/':
                push(op1/op2);
                break;
                
                case '^':
                push(pow(op1,op2));
                break;
                
                default:
                printf("Invalid operator");
                
            }
          
        }
    }
    
    printf("Result : %d",S[top]);
}
    

int main(){

printf("Enter the postfix expression : ");
scanf("%s",P);

postfix_eval();

return 0;
}
