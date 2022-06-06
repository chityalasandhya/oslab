#include<stdio.h>
int waiting_time(int process[],int n,int burst_time[],int wait_time[])
{
  wait_time[0]=0;
  for(int i=1;i<n;i++)
  wait_time[i]=burst_time[i-1]+wait_time[i-1];
  return 0;
}
int turn_around_time(int process[],int n,int burst_time[],int wait_time[],int tat[])
{
 int i;
 for(i=0;i<n;i++)
 tat[i]=burst_time[i]+wait_time[i];
 return 0;
}
int avgtime(int process[],int n,int burst_time[])
{
  int wait_time[n],tat[n],total_wt=0,total_tat=0;
  int i;
  waiting_time(process,n,burst_time,wait_time);
  turn_around_time (process,n,burst_time,wait_time,tat);
  printf("process    burst      waiting      turnaround\n");
  for(i=0;i<n;i++)
  {
     total_wt=total_wt + wait_time[i];
     total_tat=total_tat + tat[i];
     printf("%d            %d            %d          % d\n",i+1,burst_time[i],wait_time[i],tat[i]);
   }
     printf("average waitingtime=%f\n",(float)total_wt/(float)n);
     printf("average turn around time=%f\n",(float)total_tat/(float)n);
     return 0;
   }
     int main()
     {
       int process[]={1,2,3};
       int n=sizeof process/sizeof process[0];
       int burst_time[]={5,8,12};
       avgtime (process,n,burst_time);
       return 0;
     }
   

       

