#include <stdio.h>

void main(){
    int i,j,size,min,temp;
    
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
    
    for(i=0;i<size-1;i++){
        min=i;
        for(j=i+1;j<size;j++){
            if(a[min]>a[j]){
                min=j;
            }
        }
        
        if(min!=i){
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
    
    printf("Array after sorting : ");
    for(i=0;i<size;i++){
        printf("%d  ",a[i]);
    }
}
