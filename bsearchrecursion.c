#include <stdio.h>

int Bsearch(int A[],int l,int h,int k){
if(l<=h){
int mid=(l+h)/2;
if(A[mid]==k){
return 1;
}
else if(A[mid]>k){
Bsearch(A,l,mid-1,k);
}
else{
Bsearch(A,mid+1,h,k);
}
}
else{
return 0;
}
}


int main(){
int A[100],k,n;
printf("Enter the size of array : ");
scanf("%d",&n);
printf("Enter the elements of the array : ");
for(int i=0;i<n;i++){
scanf("%d",&A[i]);
}
printf("Enter the element to be searched : ");
scanf("%d",&k);
int searchResult=Bsearch(A,0,n-1,k);
if(searchResult==1){
printf("True");
}
else{
printf("False");
}

return 0;
}
