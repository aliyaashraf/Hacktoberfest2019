#include<stdio.h>
void main(){
    int prr[20], bt[10], at[10], fin[10], tat[10], wt[10],st[10];
    int i, j, n, temp,total=0;
    printf("Number of processes:");
    scanf("%d",&n);
    printf("Enter the Process,arrival time & burst time:");

    for(i = 0; i < n; i++)
      scanf("%d%d%d",&prr[i],&at[i],&bt[i]);

    for(i = 0; i < n; i++){
        for(j = 0; j < n-i-1; j++){
            if(at[j] > at[j+1]){
                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
                temp = prr[j];
                prr[j] = prr[j+1];
                prr[j+1] = temp;
            }
        }
    }

    wt[0]=0;


    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

        total+=wt[i];
    }

    printf("___________________________________________\n");
    printf(" P\tAT\tBT\tWT\n");
    printf("___________________________________________\n");
    for(i = 0; i < n; i++)
    {
        printf(" %d\t%d\t%d\t%d\n",prr[i], at[i], bt[i], wt[i]);

    }


}
