#include <stdio.h>
#define MAX 100

void bubble_sort(int data[], int n){
    int i,j,temp;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-1; j++){
            if(data[j]>data[j+1]){
                temp= data[j];
                data[j]= data[j+1];
                data[j+1]= temp;
            }
        }
    }
}

int binary_search(int data[], int lower, int upper, int item){
    int mid;
    if(lower == upper){
        if(item == data[lower])
            return lower;
        else
            return -1;
    }
    else{
        mid = (lower+upper)/2;
        if(item == data[mid])
            return mid;
        else if (item < data[mid])
            return binary_search(data,lower,mid-1,item);
        else
            return binary_search(data,mid+1,upper,item);
    }
}

int main()
{
    int data[MAX], i, n, item, loc;
    printf("How many elements: ");
    scanf("%d", &n);
    printf("Please enter %d numbers: \n",n);
    for(i=0; i< n; i++){
        scanf("%d", &data[i]);
    }
    bubble_sort(data,n);
    printf("After sorting the array: \n");
    for(i=0; i<n; i++){
        printf("%d ", data[i]);
    }
    printf("\nWhat item you want to search:");
    scanf("%d", &item);
    loc=binary_search(data, 0, n-1, item);
    if(loc==-1)
        printf("\n %d is not in the array data ",item);
    else
        printf("\n\nThe location of %d is %d", item, loc+1);

    return 0;
}
