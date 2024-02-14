#include <stdio.h>
void main(){
    int row,column,i,j,k;
    int A[10][10],S[10][3];
    
    printf("Enter the number of rows and columns of the sparse matrix : ");
    scanf("%d %d",&row,&column);
   
    printf("\nEnter the elements of the sparse matrix : \n");
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            scanf("%d",&A[i][j]);
        }
    }
        
    k=1;
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            if(A[i][j]!=0){
                S[k][0]=i;
                S[k][1]=j;
                S[k][2]=A[i][j];
                k++;
            }
        }
    }
    
    S[0][0]=row;
    S[0][1]=column;
    S[0][2]=k-1;
    
    printf("\nTuple form\n");
    printf("Rows Columns Values\n");
    for(i=0;i<k;i++){
        for(j=0;j<3;j++){
            printf("%d\t  ",S[i][j]);
            }
        printf("\n");
    }
}
