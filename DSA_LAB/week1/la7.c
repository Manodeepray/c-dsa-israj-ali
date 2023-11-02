#include <stdio.h>

int zero_count(int mat[,]){
    int i,j,zcount=0
    for (i =0 ; i<n;i++){
        for ( j = 0; j < n; j++)
        {
            if(mat[i,j]==0){
                zcount+=1;
            }
        }
        
        
    }
    return zcount;
}

int sum_diag(int mat[,]){
    int i,j,diag=0;
    for (i =0 ; i<n;i++){
        for ( j = 0; j < n; j++)
        {
            if(i==j){
                diag+=mat[i,j];
            }
        }
        
        
    }
    return diag;
}

void minor_diag(int mat[,]){
    int i,j;
    for (i =0 ; i<n;i++){
        for ( j = 0; j < n; j++)
        {
            if(i>=2 || j>=2){
                printf(" %d \n",mat[i,j]);
            }
        }
        printf("\n");
        
    }
    return diag;
}

int mul_diag(int mat[,]){
    int i,j,diag=1;
    for (i =0 ; i<n;i++){
        for ( j = 0; j < n; j++)
        {
            if(i==j){
                diag=diag*mat[i,j];
            }
        }
        
        
    }
    return diag;
}
int main(){
    int n,i,j;
    printf("enter the size of matrix n = ");
    scanf("%d",&n);
    int mat[n,n];


    printf("1.the no. of zeroes in the matrix = %d",zero_count(mat));

    printf("2.the sum of diagonal elements in the matrix = %d",sum_diag(mat));

    printf("3.the product of diagonal elements in the matrix = %d",mul_diag(mat));

}