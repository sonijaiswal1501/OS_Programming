#include<stdio.h>
#include<stdbool.h>



void findAvgTime(int [], int , int [], int );
void findWaitingTime(int [], int , int [], int [], int );
void findTurnAroundTime(int [], int , int [], int [], int [] );


int main()
{
	int processes[] = {1, 2, 3};
	int n = sizeof processes / sizeof processes[0];	
	int burst_time[] = {10, 5, 8};
	int quantum = 2;

	findAvgTime(processes, n, burst_time, quantum);

	return 0;
}

void findAvgTime(int processes[], int n, int bt[], int quantum)
{
	int i, wt[n], tat[n], total_wt = 0, total_tat = 0;
	
	findWaitingTime(processes, n, bt, wt, quantum);

	findTurnAroundTime(processes, n, bt, wt, tat);

	printf("\nProcesses	Burst Time	Waiting Time	Turn Around Time\n");

	for(i=0; i<n; i++)
	{
	    total_wt = total_wt + wt[i];
	    total_tat = total_tat + tat[i];
	    printf("\n%d		%d		%d		%d\n", i+1, bt[i], wt[i], tat[i]);
	}

	printf("\nAverage waiting time = %f \n", (float)total_wt/ (float)n);
	printf("\nAverage turn around time = %f \n", (float)total_tat/ (float)n);
}

void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum)
{
	int i, t=0, rem_bt[n];
	
	for(i=0; i<n; i++)
	    rem_bt[i] = bt[i];

	while(1)
	{
	   bool done = true;

	   for(i=0; i<n; i++)
	   {
	     if(rem_bt[i] > 0)
	     {
	         done = false;
	         if(rem_bt[i] > quantum) 
	         {
		   t += quantum;
	           rem_bt[i] -= quantum;
	         }
	         else
	         {
		   t = t + rem_bt[i];
		   wt[i] = t - bt[i];
		   rem_bt[i] = 0;
	         }
	      }
	   }

	   if(done == true)
	   break;

	}
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[] )
{
	int i;	
	
	for(i=0; i<n; i++)
	   tat[i] = bt[i] + wt[i];
}

	  
