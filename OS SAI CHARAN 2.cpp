#include<stdio.h>

main()

{
 int n,i,j,avgw=0;
 float avgt=0,temp;
 int burst[10],wait[10],process[10];

 printf("\nProcess Scheduling(SJFS) :\n");

 printf("\nEnter the number of process : ");
 
scanf("%d",&n);
 
printf("Enter the Burst time\n");
 
for(i=0;i<n;i++)

 {
printf("Burst time P %d : ",i+1);
scanf("%d",&burst[i]);
process[i] = i;
 printf("\n");
 }
 
for(i=0;i<n;i++)

 {
for(j=i;j<n;j++)
 {
if(burst[i]>burst[j])
{
temp = burst[i];
burst[i] = burst[j];
burst[j] = temp;
temp = process[i];
process[i] = process[j];
process[j] = temp;
}
}
 }

 printf("\nWaiting time | Turn around time \n");
 
j=0;
 
for(i=0;i<n;i++)

 {
wait[i] = j;
j = burst[i] + j;
printf("\nP%d : %d\t\t%d",process[i]+1,wait[i],wait[i]+burst[i]);
avgw+=wait[i];
avgt+=wait[i]+burst[i];
 }

 printf("\n\n");

 printf("Average waiting time : %f\nAverage Turn around time : %f\n\n",avgw/(float)n,avgt/(float)n);
}


/*Output :
 
Process Scheduling(SJFS) :
 
Enter the number of process : 3

Enter the Burst time
Burst time P1 : 24
 
Burst time P2 : 3
 
Burst time P3 : 3
 

 
Waiting time | Turn around time
 
P2 : 0          3
P3 : 3          6
P1 : 6          30
 
Average waiting time : 3.000000
Average Turn around time : 13.000000*/



