#include <stdio.h>
#include <stdlib.h>

struct set{
    int key;
    int data;
};
struct set A[10];
int size = 10;

void insert(int key,int data){
    int index = key % size;
    if(A[index].data==-1){
        A[index].key=key;
        A[index].data=data;
    }
    else{
        printf("Collision");
    }
}

void delete(int key){
    int index = key % size;
    if(A[index].data==-1){
        printf("Not exists");
    }
    else{
        A[index].key=-1;
        A[index].data=-1;
    }
}

void display(){
    int i;
    for(i=0;i<size;i++){
        if(A[i].data==-1){
            printf("\n A[%d] : NULL",i);
        }
        else{
            printf("\n A[%d] : (%d %d)\t",i,A[i].key,A[i].data);
        }
    }
}




int main(){
    int choice,key,data,n,i;
    for(i=0;i<size;i++){
        A[i].key=-1;
        A[i].data=-1;
    }
    
    while(1){
        printf("\n1-Insert\n2-Delete\n3-Display\n4-Exit");
        printf("CHOICE : ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
            printf("Enter the key : ");
            scanf("%d",&key);
            printf("Enter the data : ");
            scanf("%d",&data);
            insert(key,data);
            break;
            
            case 2:
            printf("Enter the key to be deleted : ");
            scanf("%d",&key);
            delete(key);
            break;
            
            case 3:
            display();
            break;
            
            case 4:
            exit(0);
            break;
            
            default:
            printf("Invalid choice");
        }
    }
}
