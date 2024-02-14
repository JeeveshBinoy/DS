#include <stdio.h>

struct poly{
    int coeff;
    int expo;
}p1[10],p2[10],p3[10];

int readpoly(struct poly p[10]){
    int i,t1;
    
    printf("Enter the total no: of terms : ");
    scanf("%d",&t1);
    
    printf("Enter the coefficients and exponents in descending order\n");
    
    for(i=0;i<t1;i++){
        printf("Enter the coefficient %d :",i+1);
        scanf("%d",&p[i].coeff);
        
        printf("Enter the exponent %d :",i+1);
        scanf("%d",&p[i].expo);
    }
    return t1;
}

void display(struct poly p[10],int term){
    int k;
    for(k=0;k<term-1;k++){
        printf("%d(x^%d)+",p[k].coeff,p[k].expo);
    }
    printf("%d(x^%d)",p[term-1].coeff,p[term-1].expo);
}

int addpoly(struct poly p1[10],struct poly p2[10],int t1,int t2,struct poly p3[10]){
    int i=0,j=0,k=0;
    while(i<t1 && j<t2){
        if(p1[i].expo==p2[j].expo){
            p3[k].coeff=p1[i].coeff+p2[j].coeff;
            p3[k].expo=p1[i].expo;
            i++;
            j++;
            k++;
        }
        
        else if(p1[i].expo>p2[j].expo){
            p3[k].coeff=p1[i].coeff;
            p3[k].expo=p1[i].expo;
            i++;
            
            k++;
        }
        
        else{
            p3[k].coeff=p2[j].coeff;
            p3[k].expo=p2[j].expo;
            
            j++;
            k++;
        }
    }
    
    while(i<t1){
        p3[k].coeff=p1[i].coeff;
        p3[k].expo=p1[i].expo;
        i++;
        
        k++;
    }
    
    while(j<t2){    
        p3[k].coeff=p2[j].coeff;
        p3[k].expo=p2[j].expo;
            
        j++;
        k++;
    }
    
    return k;
        
}

void main(){
    int t1,t2,t3;
    
    t1=readpoly(p1);
    printf("\n First polynomial : ");
    display(p1,t1);
    
    t2=readpoly(p2);
    printf("\n Second polynomial : ");
    display(p2,t2);
    
    t3=addpoly(p1,p2,t1,t2,p3);
    printf("\n Polynomial after addition : ");
    display(p3,t3);
}    
    
