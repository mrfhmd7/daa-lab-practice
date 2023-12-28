#include <stdio.h>

int a[100], b[100];

void merging(int low, int mid, int high) {
   int h = low, j = mid + 1, i;

   for(i = low; h <= mid && j <= high; i++) {
      if(a[h] <= a[j]){
         //b[i] = a[l1++];
         b[i] = a[h];
         h++;
      }
      else{
         b[i] = a[j];
         j++;
      }
   }

   while(h <= mid)
      b[i++] = a[h++];

   while(j <= high)
      b[i++] = a[j++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void sort(int low, int high) {
   int mid;

   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } else {
      return;
   }
}

int main() {
   int i,maxx;
   printf("Enter the number of element: ");
   scanf("%d",&maxx);
   printf("Enter the elements: ");
   for(i=0;i<maxx;i++){
    scanf("%d",&a[i]);
   }


   printf("List before sorting\n");

   for(i = 0; i < maxx; i++)
      printf("%d ", a[i]);

   sort(0, maxx-1);

   printf("\nList after sorting\n");

   for(i = 0; i < maxx; i++)
      printf("%d ", a[i]);
}
