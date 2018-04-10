#include<stdio.h>
#include<stdlib.h>
    struct process_structure {
	    int process_id, arrival_time, burst_time, priority;
		int w_flag,waiting_time;
		int turnaround_time;
    };
int main () {
    int a, count;
    int TimeQ;
    int waiting_time;
int i, j;
    printf("\n Level 1 : Fixed priority preemptive Scheduling\n Level 2 : Round Robin Scheduling\n\n");
    printf("Enter Total Number of Processes   : ");
    scanf("%d", & a);
    printf("Enter Time Quantum for Round Robin in multiple of 2: ");
    scanf("%d", & TimeQ);
    struct process_structure p1[a];
    struct process_structure p2[a];
    struct process_structure processTree[a];
    int flag = 1;
    int Qlevel=1;
    int q1 = 0, q2 = 0;	
    for (count = 0; count < a; count++) {
            printf("Process ID       : ");
            scanf("%d", & p1[q1].process_id);
           printf("Arrival Time     : ");
            scanf("%d", & p1[q1].arrival_time);
            printf("Burst Time       : ");
            scanf("%d", & p1[q1].burst_time);
            printf("Process Priority : ");
            scanf("%d", & p1[q1].priority);
	    p1[q1].w_flag=0;
            p1[q1].waiting_time=0;
            p1[q1].turnaround_time=0;	
            processTree[count]=p1[q1];
            q1++;
        }
    
    printf("\n\n \t\t\tLEVEL 1 QUEUE IS Running\n\n");
struct process_structure temp;
    for (i = 1; i < q1; i++)
        for (j = 0; j < q1 - i; j++) {
            if (p1[j].arrival_time > p1[j + 1].arrival_time) {
                temp = p1[j];
                p1[j] = p1[j + 1];
                p1[j + 1] = temp;
            }
        }
    for (i = 0; i < q1; i++) {
        printf("\nProcess ID:%d\t Arrival Time:%d \tPriority: %d\tBurst Time:%d", p1[i].process_id, p1[i].arrival_time, p1[i].priority, p1[i].burst_time);
    }
    printf("\n\n");
int total_process_L1 = q1;
    i = 0;
    int run;
    for (run = 0;; run++) {
        if (q1 == 0) {
            break;
        }
 //premepts previous process
        if (p1[i]. priority > p1[i + 1].priority && p1[i + 1].arrival_time == run) {
            p2[q2] = p1[i];
	    p1[i].priority=-1;	
            p2[q2].arrival_time = run;
	    p2[q2].w_flag=0;
            p2[q2].priority = -1;
    
            printf("\t\t\t\t\t Process %d is shifted to Queue 2\n ", p1[i].process_id);
            q1--;
            q2++;
                       i++;
        }
        if (p1[i].arrival_time <= run && p1[i].burst_time != 0) {
		if(p1[i].w_flag==0)
		{	
			p1[i].waiting_time+=((run)-p1[i].arrival_time);
			p1[i].w_flag=1;
		}
            printf("\nProcess ID:%d  Priority: %d Burst Time %d time %d", p1[i].process_id, p1[i].priority, p1[i].burst_time, run);
		 p1[i].burst_time--;
            } else if (p1[i].burst_time == 0) {
            printf("\t\t\t\t\tProcess %d has completed\n"p1[i].process_id);
            q1--;
	    run--;
            i++;
        }
    }
    int k=0;
    for (i = 0; i < total_process_L1; i++) {
	 for(k=0;k<a;k++)
	{	
		if(p1[i].process_id==processTree[k].process_id)
		{	
			processTree[k].waiting_time=p1[i].waiting_time;
		}
	}
	}
	 printf("\n\n");
    printf("\n\n LEVEL 2 is Running\n\n");
    for (i = 1; i < q2; i++) {
        for (j = 0; j < q2 - i; j++) {
            if (p2[j].arrival_time > p2[j + 1].arrival_time) {
                temp = p2[j];
                p2[j] = p2[j + 1];
                p2[j + 1] = temp;
            }
        }
    }
    int total_process_L2 = q2;
    for (i = 0; i < q2; i++) {
        printf("\nProcess ID:%d\t Arrival Time:%d \tBurst Time:%d", p2[i].process_id, p2[i].arrival_time, p2[i].burst_time);
    }
printf("\n\n");
    i = 0;
    int resetter = 0;
    for (run;; run++) 
     {
        if (total_process_L2 == 0)
        {
            break; }
	if(p2[i].burst_time == 0)
        {
            printf("\t\t\t\t\tProcess %d has Completed\n", p2[i].process_id);
            i++;
	    run--;
            total_process_L2--;
            resetter = 0;
            continue;
        }
        else if (resetter == TimeQ)
        {
            printf("\n\n!! Time Quantum Complete of %d seconds !!! \n", resetter);	
            p2[q2] = p2[i];
	    p2[q2].arrival_time=run;	
            i++;
	    q2++;
            resetter = 0;
        }
        if (p2[i].arrival_time <= run && p2[i].burst_time != 0)
        {
 		if(resetter==0&&p2[i].process_id!=p2[i-1].process_id)
		{	
			p2[i].waiting_time+=(run-p2[i].arrival_time);

			p2[i].w_flag=1;
		} 
		printf("\nProcess ID:%d  Burst Time %d Time Taken %d", p2[i].process_id, p2[i].burst_time, run);
		p2[i].burst_time --;
        }
	 else if (p2[i].burst_time == 0)
	 {

     
            printf("\t\t\t\t\t Process %d has Completed\n", p2[i].process_id);
            i++;
	    run--;
            total_process_L2--;
	    resetter = 0;
        }
      resetter++;
    }
 for (i = 0; i < q2; i++) {
	 for(k=0;k<a;k++)
	{	
		if(p2[i].process_id==processTree[k].process_id)
		{	
			processTree[k].waiting_time=p2[i].waiting_time;
		}
	}
	}

	float avg_wait_time=0;
    float avg_turn_time=0;
    for (i = 0; i < a; i++) {
	processTree[i].turnaround_time=processTree[i].burst_time+processTree[i].waiting_time;
        printf("\n\t\t ********** PROCESS TABLE ********** ");
        printf("\n| Process ID:%d | Arrival Time:%d | Burst Time:%d | waiting Time:%d  | Turn Time:%d |", processTree[i].process_id, processTree[i].arrival_time,processTree[i].burst_time, processTree[i].waiting_time,processTree[i].turnaround_time);
	avg_wait_time+=processTree[i].waiting_time;
	avg_turn_time+=processTree[i].turnaround_time;
    }
    printf("\n\n");
	avg_wait_time/=a;
    avg_turn_time/=a;
	printf("Average Waiting Time    : %.2f\n",avg_wait_time);
    printf("Average TurnAround Time : %.2f\n",avg_turn_time);}

