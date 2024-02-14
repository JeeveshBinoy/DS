#include <stdio.h>

void main(){
    int i,j,size,key;
    int a[20];
    
    printf("Enter the size of array : ");
    scanf("%d",&size);
    
    for(i=0;i<size;i++){
        printf("Enter the %d element : ",i+1);
        scanf("%d",&a[i]);
    }
    
    printf("Array before sorting : ");
    for(i=0;i<size;i++){
        printf("%d  ",a[i]);
    }
    
    for(i=1;i<size;i++){
        key=a[i];
        j=i-1;
        
        while(a[j]>key && j>=0){
            a[j+1]=a[j];
            j=j-1;
        }
        
        a[j+1]=key;
    }
    
    printf("\nArray after sorting : ");
    for(i=0;i<size;i++){
        printf("%d  ",a[i]);
    }
    
}
