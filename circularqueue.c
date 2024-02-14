#include <stdio.h>
int A[100],cqueue_size,front,rear;

void enqueue(){
    int data;
    if(front==(rear+1)%cqueue_size){
        printf("Queue Overflow");
    }
    
    else if(rear==-1){
        front=0;
        rear=0;
        printf("Enter the data to be pushed : ");
        scanf("%d",&data);
        
        A[rear]=data;
    }
    
    else{
        printf("Enter the data to be pushed : ");
        scanf("%d",&data);
        
        rear=(rear+1)%cqueue_size;
        A[rear]=data;
    }
}

void dequeue(){
    
    if(front==-1 && rear==-1){
        printf("Queue Underflow");
    }
    
    else if(front==rear){
        printf("Dequeued element is : %d",A[front]);
        front=-1;
        rear=-1;
    }
    
    else{
        printf("Dequeued element is : %d",A[front]);
        front=(front+1)%cqueue_size;
    }
}

void display(){
    int i;
    if(front==-1 && rear==-1){
        printf("Queue is empty");
    }
    
    else if(front<=rear){
        for(i=front;i<=rear;i++){
            printf("%d\t",A[i]);
        }
    }
    else{
        for(i=front;i<=(cqueue_size-1);i++){
            printf("%d\t",A[i]);
        }
        for(i=0;i<=rear;i++){
            printf("%d\t",A[i]);
        }
    }
        
}

void isfull(){
    if(front==(rear+1)%cqueue_size){
        printf("Queue is full");
    }
    else{
        printf("Queue is not full");
    }
        
}

void isempty(){
    if(front==-1 && rear==-1){
        printf("Queue is empty");
    }
    else{
        printf("Queue is not empty");
    }
}

void size(){
    int size=rear-front+1;
    printf("Size : %d",size);
}

int main(){
    front=-1;
    rear=-1;
    int choice;
    
    printf("Enter the size of the circular queue : ");
    scanf("%d",&cqueue_size);
    
    do{
        printf("\n1-->ENQUEUE\n");
        printf("2-->DEQUEUE\n");  
        printf("3-->DISPLAY\n");
        printf("4-->ISFULL\n");
        printf("5-->ISEMPTY\n");
        printf("6-->SIZE\n");
        printf("7-->EXIT\n"); 
        printf("Enter the choice\n");
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
            isfull();
            break;
            
            case 5:
            isempty();
            break;
            
            case 6:
            size();
            break;
            
            case 7:
            break;    
            
            default:
            printf("Invalid choice");
            
        }
    }while(choice!=7);
    
return 0;

}
