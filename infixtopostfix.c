#include <stdio.h>
#include <ctype.h>
char I[20],P[20];
char S[20];
int top=-1;

int precedence(char c){
    switch(c){
        case '+':
        case '-':
        return 1;
        
        case '/':
        case '*':
        return 2;
        
        case '^':
        return 3;
    }
}

void infix_to_postfix(){
    int i=0,j=0;
    char x,y;
    
    while(I[i]!='\0'){
        if(isdigit(I[i])){
            P[j++]=I[i];
            
        }
        
        else if(I[i]=='('){
            S[++top]=I[i];
            
        }
        
         else if(I[i]==')'){
            while(S[top]!='('){
                P[j++]=S[top--];
                
            }
            top--;
        }
        
        else{
            x=I[i];
            y=S[top];
            if(top==-1 || y=='(' || precedence(y)<precedence(x)){
                S[++top]=I[i];
                
                
            }
            
            else{
                while(top!=-1 && y!='(' && precedence(x)<=precedence(y)){
                    P[j++]=S[top--];
                    y=S[top];
                }
                S[++top]=x;
            }
        }
    i++;
    }
    
    while(top!=-1){
        P[j++]=S[top--];
    }
    
    P[j]='\0';
    printf("Postfix expression is : %s\n",P);
}


int main(){


    printf("Enter the infix expression : ");
    scanf("%s",I);
    
    infix_to_postfix();
    
    return 0;
}
