#include<stdio.h>
#define MAX 20
int val[MAX], wt[MAX];
int max(int a, int b) { 
    if(a>b)
     return a;
    else
     return b;
}
int knapSack(int W, int wt[], int val[], int n)
{
   int i, j;
   int K[n+1][W+1];
   for (i = 0; i <= n; i++)
   {
       for (j = 0; j <= W; j++)
       {
           if (i==0 || j==0)
               K[i][j] = 0;
           else if (wt[i-1] <= j)
                 K[i][j] = max((K[i-1][j]), (val[i-1] + K[i-1][j-wt[i-1]]));
           else
                 K[i][j] = K[i-1][j];
       }
   }
   printf("\nThe table: \n");
   for(i=0; i<n; i++){
    for(j=0; j<=W; j++)
        printf("%4d",K[i][j]);
    printf("\n");
   }
   return K[n][W];
}
int main()
{
    int i, n, capacity;
    printf("Enter number of items:");
    scanf("%d", &n);
    printf("Enter values of items:\n");
    for(i = 0;i < n; i++)
        scanf("%d", &val[i]);
    printf("Enter weights of items:\n");
    for(i = 0;i < n; i++)
        scanf("%d",&wt[i]);
    printf("Enter capacity of knapsack:");
    scanf("%d", &capacity);
    printf("\nmaximum value: %d", knapSack(capacity, wt, val, n));
    return 0;
}