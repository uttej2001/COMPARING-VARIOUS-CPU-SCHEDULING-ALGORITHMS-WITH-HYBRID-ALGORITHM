#include<stdio.h> 

#include<stdlib.h> 

#include<string.h> 

//HYBRID 

void hybrid_schedule(int n,int p[],int at[],int bt[]) 

{ 

int et[10],i,j,temp,lag=0,time=0,flag[]= {1,1,1,1,1,1},ct[]= {0,0,0,0,0,0},tat[10],wt[10],tot_tat=0,tot_wt=0,att[10],ctt; 

float avg_tat,avg_wt; 

for(i=0; i<n; i++) 

{ 

et[i]=at[i]+bt[i]; //Calculating elapsed time=arrival time+burst time 

} 

for(i=0; i<n; i++) 

{ 

for(j=i+1; j<n; j++) 

{ 

if(et[i]>et[j])  //sorting the processes based on elapsed time 

{ 

temp=p[i]; 

p[i]=p[j]; 

p[j]=temp; 

temp=at[i]; 

at[i]=at[j]; 

at[j]=temp; 

temp=bt[i]; 

bt[i]=bt[j]; 

bt[j]=temp; 

temp=et[i]; 

et[i]=et[j]; 

et[j]=temp; 

} 

} 

} 

for(i=0; i<n; i++)  //storing the processes based on their arrival times 

att[i]=at[i]; 

for(i=0; i<n; i++) 

{ 

for(j=i+1; j<n; j++) 

{ 

if(att[i]>att[j]) 

{ 

temp=att[i]; 

att[i]=att[j]; 

att[j]=temp; 

} 

} 

} 

 

if(att[0]==at[0])  // checking if the first process arrived has the least elapsed time 

{ 

time=at[0]; 

while(time!=0) 

{ 

lag=lag+1;  //lag- to calculate the amount of waiting time for a process 

 

time=time-1; //time- to keep a track on the completion of the process 

} 

ct[0]=lag+bt[0];  //calculating the completion time for a process 

flag[0]=0;        // setting flag to zero indicating that the process has been completed 

for(i=0; i<n; i=j) 

{ 

for(j=1; j<n; j++) 

{ 

if(flag[j]!=0) 

{ 

if(at[j]<ct[i]) 

{ 

ct[j]=ct[i]+bt[j];  //calculating the completion time for remaining processes 

flag[j]=0;          // setting flag to zero indicating that the process has been completed 

break; 

} 

} 

} 

} 

} 

else 

{ 

for(i=1; i<n; i++) 

{ 

if(att[0]==at[i])    //computing the position of the first arrived process in the scheduling queue 

{ 

time=at[i]; 

while(time!=0) 

{ 

lag=lag+1;    //lag- to calculate the amount of waiting time for a process 

time=time-1;  //time- to keep a track on the completion of the process 

} 

ct[i]=lag+bt[i]; 

flag[i]=0; 

ctt=ct[i]; 

break; 

} 

} 

ct[0]=ctt+bt[0]; 

flag[0]=0; 

for(i=0; i<n; i=j) 

{ 

for(j=i+1; j<n; j++) 

{ 

if(flag[j]!=0) 

{ 

if(at[j]<ct[i]) 

{ 

ct[j]=ct[i]+bt[j];   //calculating the completion time for remaining processes 

flag[j]=0;           // setting flag to zero indicating that the process has been completed 

break; 

} 

} 

} 

} 

} 

for(i=0; i<n; i++) 

{ 

tat[i]=ct[i]-at[i]; //calculating turn around time for each process 

tot_tat+=tat[i];    //calculating total turn around time 

wt[i]=tat[i]-bt[i];  //calculating waiting time for each process 

tot_wt+=wt[i];      //calculating total waiting time 

} 

avg_tat=(float)tot_tat/(float)n; //calculating average turn around time 

avg_wt=(float)tot_wt/(float)n;   //calculating average waiting time 

printf("Process AT\tBT\tET\tCT\tTAT\tWT\n"); 

for(i=0; i<n; i++) 

{ 

printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],et[i],ct[i],tat[i],wt[i] 

      ); 

} 

printf("Average turn-around time:- %.2f\n",avg_tat); 

printf("Average waiting time:- %.2f\n",avg_wt); 

} 

//SJF 

void sjf(int n,int p[],int at[],int bt[]) 

{ 

int wt[20],tat[20],i,j,total=0,pos,temp; 

float avg_wt,avg_tat; 

//sorting burst time in ascending order using selection sort 

for(i=0;i<n;i++) 

{ 

pos=i; 

for(j=i+1;j<n;j++) 

{ 

if(bt[j]<bt[pos]) 

pos=j; 

} 

 

temp=bt[i]; 

bt[i]=bt[pos]; 

bt[pos]=temp; 

 

temp=p[i]; 

p[i]=p[pos]; 

p[pos]=temp; 

} 

 

wt[0]=0; //waiting time for first process will be zero 

//calculate waiting time 

for(i=1;i<n;i++) 

{ 

wt[i]=0; 

for(j=0;j<i;j++) 

wt[i]+=bt[j]; 

 

total+=wt[i]; 

} 

 

avg_wt=(float)total/n; //average waiting time 

total=0; 

 

printf("\nProcess\tBT\tTAT\tWT"); 

for(i=0;i<n;i++) 

{ 

tat[i]=bt[i]+wt[i]; //calculate turnaround time 

total+=tat[i]; 

printf("\n%d\t%d\t%d\t%d",p[i],bt[i],tat[i],wt[i]); 

} 

 

avg_tat=(float)total/n; //average turnaround time 

printf("\n\nAverage Waiting Time=%f",avg_wt); 

printf("\nAverage Turnaround Time=%f\n",avg_tat); 

} 

//FCFS 

void fcfs(int n,int p[], int at[], int bt[]){ 

int i,temp,j,pos,wt[n],tat[n],ct[n],k1; 

int tot_wt=0,tot_tat=0; 

float avg_wt,avg_tat; 

for(i=0;i<n;i++){ 

tat[i]=0; 

wt[i]=0; 

} 

for(i=0;i<n;i++) 

{ 

pos=i; 

for(j=i+1;j<n;j++) 

{ 

if(at[j]<at[pos]) 

pos=j; 

} 

 

temp=bt[i]; 

bt[i]=bt[pos]; 

bt[pos]=temp; 

 

temp=p[i]; 

p[i]=p[pos]; 

p[pos]=temp; 

 

temp=at[i]; 

at[i]=at[pos]; 

at[pos]=temp; 

} 

k1=at[0]+bt[0]; 

ct[0]=k1; 

for(i=1;i<n;i++){ 

k1=k1+bt[i]; 

ct[i]=k1; 

} 

for(i=0;i<n;i++){ 

tat[i]=ct[i]-at[i]; 

tot_tat+=tat[i]; 

wt[i]=tat[i]-bt[i]; 

tot_wt+=wt[i]; 

} 

avg_tat=(float)tot_tat/(float)n; 

avg_wt=(float)tot_wt/(float)n; 

printf("Process\tAT\tBT\tCT\tTAT\tWT\n"); 

for(i=0;i<n;i++) 

{ 

printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]); 

} 

printf("Average waiting time = %.2f\n",avg_wt); 

printf("Average turn-around time = %.2f\n",avg_tat); 

} 

// Main Function 

int main() 

{ 

int n,at[10],bt[10],p[10],pr[10],i; 

printf("enter the number of processes:"); 

scanf("%d",&n); 

for(i=0;i<n;i++) 

{ 

printf("Enter the Process id, Arrival time and Burst time: \n"); 

scanf("%d%d%d",&p[i],&at[i],&bt[i]); 

} 

printf("using hybrid scheduling:\n"); 

hybrid_schedule(n,p,at,bt); 

printf("using sjf scheduling:\n"); 

sjf(n,p,at,bt); 

printf("using fcfs scheduling:\n"); 

fcfs(n,p,at,bt); 

} 