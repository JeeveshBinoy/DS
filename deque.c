#include <stdio.h>
int A[100],deque_size,front,rear;

void insertion_at_front(){
    int data,i;
    if(front==0 && rear==deque_size-1){
        printf("Deque Overflow");
    }
    
    else if(rear==-1){
        printf("Enter the data to be inserted : ");
        scanf("%d",&data);
        
        front=0;
        rear=0;
        
        A[front]=data;
    }
    
    else if(front>0){
        printf("Enter the data to be inserted : ");
        scanf("%d",&data);
        
        front--;
        A[front]=data;
    }
    
    else{
        printf("Enter the data to be inserted : ");
        scanf("%d",&data);
        
        for(i=rear;i>=front;i--){
            A[i+1]=A[i];
        }
        
        A[front]=data;
        rear++;
    }
}

void insertion_at_rear(){
    int data,i;
    if(front==0 && rear==deque_size-1){
        printf("Deque Overflow");
    }
    
    else if(rear==-1){
        printf("Enter the data to be inserted : ");
        scanf("%d",&data);
        
        front=0;
        rear=0;
        
        A[rear]=data;
    }
    
    else if(rear<deque_size-1){
        printf("Enter the data to be inserted : ");
        scanf("%d",&data);
        
        rear++;
        A[rear]=data;
    }
    
    else{
        printf("Enter the data to be inserted : ");
        scanf("%d",&data);
        
        for(i=front;i<=rear;i++){
            A[i-1]=A[i];
        }
        A[rear]=data;
        front--;
    }
}

void deletion_at_front(){
    if(front==-1){
        printf("Deque Underflow");
    }
    
    else if(front==rear){
        printf("Deleted element is : %d",A[front]);
        front=-1;
        rear=-1;
    }
    
    else{
       printf("Deleted element is : %d",A[front]);
       front++;
   }
}

void deletion_at_rear(){
    if(front==-1){
        printf("Deque Underflow");
    }
    
    else if(front==rear){
        printf("Deleted element is : %d ",A[rear]);
        front=-1;
        rear=-1;
    }
    
    else{
       printf("Deleted element is : %d ",A[rear]);
       rear--;
   }
}

void display(){
    int i;
    if(front==-1){
        printf("Deque is empty");
    }
    
    else{
        for(i=front;i<=rear;i++){
            printf("%d\t",A[i]);
        }
    }
}

void isfull(){
    if(front==0 && rear==deque_size-1){
        printf("Deque is full");
    }
    
    else{
        printf("Deque is not full");
    }
}

void isempty(){
    if(front==-1){
        printf("Deque is empty");
    }
    
    else{
        printf("Deque is not empty");
    }
}

void size(){
    int size=rear-front+1;
    printf("Size is : %d",size);
}
    
 
int main(){
    front=-1;
    rear=-1;
    int choice;
    
    printf("Enter the size of the deque : ");
    scanf("%d",&deque_size);
    
    do{
        printf("\n1-->INSERTION AT FRONT\n");
        printf("2-->INSERTION AT REAR\n");  
        printf("3-->DELETION AT FRONT\n");
        printf("4-->DELETION AT REAR\n");
        printf("5-->DISPLAY\n");
        printf("6-->ISEMPTY\n");
        printf("7-->ISFULL\n");
        printf("8-->SIZE\n"); 
        printf("9-->EXIT\n"); 
        printf("Enter the choice\n");
        scanf("%d",&choice);
        
        switch(choice){
            
            case 1:
            insertion_at_front();
            break;
            
            case 2:
            insertion_at_rear();
            break;
            
            case 3:
            deletion_at_front();
            break;
            
            case 4:
            deletion_at_rear();
            break;
            
            case 5:
            display();
            break;
            
            case 6:
            isempty();
            break;
            
            case 7:
            isfull();
            break;
            
            case 8:
            size();
            break;
            
            case 9:
            break;    
            
            default:
            printf("Invalid choice");
            
        }
    }while(choice!=9);
    
return 0;

}
