#include <stdio.h>
int A[100],queue_size,front,rear;

void enqueue(){
    int data,i,key;
    if(rear==queue_size-1){
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
        
        rear++;
        A[rear]=data;
    }
    
    key = A[rear];
        for (int i=rear-1;i>=front;i--){//inserting to correct position
            if (key<A[i]){
                A[i+1]=A[i];
                A[i]=key;
            }
            
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
        front++;
    }
}

void display(){
    int i;
    if(front==-1 && rear==-1){
        printf("Queue is empty");
    }
    
    else{
        for(i=front;i<=rear;i++){
            printf("%d\t",A[i]);
        }
    }
}

void isfull(){
    if(rear==queue_size-1){
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
    
    printf("Enter the size of the queue : ");
    scanf("%d",&queue_size);
    
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
