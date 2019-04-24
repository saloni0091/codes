#include<stdio.h>


void rr(int [],int,int,int [],int [],int []);
void print(int [],int [],int [],int [],int []);
void avgwt(int [],int);
void avgtat(int [],int [],int [],int);

int bt[20],p[20],tat[20],wt[20],n,time=0,counter[20];
float avg_wt,avg_tat;

int main()
{
    int i;
    
    printf("Enter the Time Quantum: ");
    scanf("%d",&time);

    printf("Enter Total Number of Process:");
    scanf("%d",&n);

    printf("\nEnter Burst Time\n");
    for(i=0;i<n;i++)
    {
	printf("\nP[%d]\n",i);
	printf("Burst Time:");
	scanf("%d",&bt[i]);
	p[i]=i;           //contains process number
    }

    
      for(i=0;i<n;i++)
      counter[n]=0;

      rr(bt,n,time,counter,tat,wt);
    //sort(pr,bt,p,n);
    //avgwt(bt,n);


    
    return 0;
}


/*void avgwt(int bt[],int n)
{
  int wt[20],i,j,total=0;
  wt[0]=0;    
    for(i=1;i<n;i++)
    {
	wt[i]=0;
	for(j=0;j<i;j++)
	    wt[i]+=bt[j];
	total+=wt[i];
    }
    avg_wt=total/n;     
    avgtat(bt,wt,p,n) ;
}*/

/*void avgtat(int bt[],int wt[],int p[],int n)
{
 int i,tat[20],total=0;
 printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
	tat[i]=bt[i]+wt[i];     //calculate turnaround time
	total+=tat[i];
	printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
    avg_tat=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}*/

void rr(int bt[],int n,int time,int counter[],int tat[],int wt[])
{
  int i,sub[20],j,k=0,temp=0;

  for(i=0;i<n;i++)
  sub[i]=bt[i];
  
  do
  {
   k=0;
   for(i=0;i<n;i++)
   {
      if(sub[i]==0)
      {
       k++;
       continue;
      } 
      else if(sub[i]<time)
      {
       temp=temp+sub[i]; 
       counter[i]=temp;
       sub[i]=sub[i]-sub[i];
      } 
      else
      {
       sub[i]=sub[i]-time;
       temp=temp+time;
       counter[i]=temp;
      }
   }
  }while(k!=5);
  for(i=0;i<n;i++)
  wt[i]=counter[i]-bt[i];
 print(p,bt,counter,tat,wt);
}
 
void print(int p[],int bt[],int counter[],int tat[],int wt[])
{
  int i;

  printf("\nProcess Number\tBurst Time\tWaiting time\tTurnaround time\n");
  for(i=0;i<n;i++)
    printf("%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],counter[i]);
}
