#include<stdio.h>
#include<stdlib.h>

struct process
{
    int pid;
    int at,st;
    int bt,ft;
};

void fcfs(struct process processes[], int n)
{
    int wt[n]; int tat[n];
    for(int i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
    }
    int twt=0;
    int ttat=0;
    //sort
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(processes[j].at > processes[j+1].at)
            {
                struct process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
    int ct=0;
    for(int i=0;i<n;i++)
    {
        int shtest = -1;
        for(int j=0; j<n; j++)
        {
            if(processes[j].at <= ct && processes[j].ft == 0)
            {
                if(shtest == -1 || processes[j].at < processes[shtest].at)
                {
                    shtest=j;
                }
            }
        }

        if(shtest == -1)
        {
            ct++;
        }
        else
        {//calculation
          printf("|P%d",processes[shtest].pid);
            processes[shtest].ft = ct + processes[shtest].bt;
            processes[shtest].st= processes[shtest].ft-processes[shtest].bt;
            wt[shtest] = processes[shtest].ft - processes[shtest].at - processes[shtest].bt;
            if(wt[shtest] < 0)
            {
                wt[shtest] = 0;
            } 
            tat[shtest] = wt[shtest] + processes[shtest].bt;
            twt += wt[shtest]; 
            ttat += tat[shtest];
            ct = processes[shtest].ft;
        }
    }//dispaly part
     printf("\nPID \t AT \t BT \t ST \t ft \t WT \t TAT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d \t %d \t %d \t %d \t %d \t %d \t %d\n",processes[i].pid,processes[i].at,processes[i].st,processes[i].bt,processes[i].ft,wt[i],tat[i]);
    }

    float awt= (float) twt / n;
    float atat= (float) ttat / n ;  
    printf("\nAverage WT is:- %.2f",awt);
    printf("\nAverage TAT is:- %.2f",atat); 
}

void main()
{
    int n;
    printf("Enter the number of processes");
    scanf("%d",&n);
    struct process processes[n];
    int wt[n];
    int tat[n];
    for(int i=0;i<n;i++)
    {
        processes[i].pid=i+1;
        processes[i].ft=0;
        printf("\nEnter the arival time of process %d:-", i+1);
        scanf("%d",&processes[i].at);
        printf("Enter the burst time of process %d:-",i+1);
        scanf("%d",&processes[i].bt);
    }  
     fcfs(processes , n);
}
