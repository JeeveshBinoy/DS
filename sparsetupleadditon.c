#include <stdio.h>

int main(){
    int row1,column1,row2,column2,i,j,k;
    int a[10][10],b[10][10],A[10][3],B[10][3],C[10][3];
    
    printf("Enter the rows and columns of 1st sparse matrix : ");
    scanf("%d %d",&row1,&column1);
    
    printf("Enter the rows and columns of 2nd sparse matrix : ");
    scanf("%d %d",&row2,&column2);
    
    if (row1!=row2 || column1!=column2) {
        printf("Sparse matrix addition is not possible\n");
    }
    
    else{
   
    printf("Enter the elements of the 1st sparse matrix : \n");
    for(i=0;i<row1;i++){
        for(j=0;j<column1;j++){
            scanf("%d",&a[i][j]);
        }
    }
    
    printf("Enter the elements of the 2nd sparse matrix : \n");
    for(i=0;i<row2;i++){
        for(j=0;j<column2;j++){
            scanf("%d",&b[i][j]);
        }
    }
    
    k=1;
    A[0][0]=row1;
    A[0][1]=column1;
    
    for(i=0;i<row1;i++){
        for(j=0;j<column1;j++){
            if(a[i][j]!=0){
                A[k][0]=i;
                A[k][1]=j;
                A[k][2]=a[i][j];
                k++;
            }
        }
    }
    
    A[0][2]=k-1;
    
    printf("\nTuple form of 1st sparse matrix\n");
    printf("Rows Columns Values\n");
    for(i=0;i<k;i++){
        for(j=0;j<3;j++){
            printf(" %d\t ",A[i][j]);
        }
        printf("\n");
    }
    
    B[0][0]=row2;
    B[0][1]=column2;
    
    k=1;
    for(i=0;i<row2;i++){
        for(j=0;j<column2;j++){
            if(b[i][j]!=0){
                B[k][0]=i;
                B[k][1]=j;
                B[k][2]=b[i][j];
                k++;
            }
        }
    }
    
    B[0][2]=k-1;
    
    printf("\nTuple form of 2nd sparse matrix\n");
    printf("Rows Columns Values\n");
    for(i=0;i<k;i++){
        for(j=0;j<3;j++){
            printf("%d\t",B[i][j]);
        }
        printf("\n");
    }
    
    row1=A[0][0];
    column1=A[0][1];
    
    row2=B[0][0];
    column2=B[0][1];
    
    int m=1,n=1;
    k=1;
    
    C[0][0]=A[0][0];
    C[0][1]=A[0][1];
    
    for(i=0;i<row1;i++){
        for(j=0;j<column1;j++){
            if(A[m][0]==i && A[m][1]==j && B[n][0]==i && B[n][1]==j){
                C[k][0]=A[m][0];
                C[k][1]=A[m][1];
                C[k][2]=A[m][2]+B[n][2];
                m++;
                n++;
                k++;
            }
            
            else if(A[m][0]==i && A[m][1]==j){
                C[k][0]=A[m][0];
                C[k][1]=A[m][1];
                C[k][2]=A[m][2];
                m++;             
                k++; 
            }
            
            else {
                C[k][0]=B[n][0];
                C[k][1]=B[n][1];
                C[k][2]=B[n][2];
                n++;             
                k++;
            } 
        }
    }
    
    C[0][2]=k-1;
    
    printf("\nTuple form after addition of two sparse matrices\n");
    printf("Rows Columns Values\n");
    for(i=0;i<=C[0][2];i++){
        for(j=0;j<3;j++){
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }

    
    return 0;
    }
}
        
