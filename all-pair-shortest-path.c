#include<stdio.h>
void allPath(int A[3][3], int n){
    int i, j, k;
    for (k=0; k<n; k++){
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(A[i][j] > A[i][k] + A[k][j]){
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
        }
    }
    printf("Shortest: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int cost [3][3] = {{0,4,11},{6,0,2},{3,999,0}};
    int n = 3;

    allPath(cost, n);
    return 0;
}
