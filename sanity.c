 	#include "types.h"
	#include "user.h"
	
	
	int
	main(int argc, char *argv[])
	{
		if (argc != 2)
		{
			printf(1, "Usage: sanity <n>\n");
			exit();
		}
		int i;
		int n;
		int j = 0;
		int k;
		int retime;
		int rutime;
		int stime;
		int sums[3];
		n = atoi(argv[1]);
		i = n; //unimportant
		int pid;
		int trial;
		for(trial =0; trial < 50; trial++){
		for (i = 0; i < n; i++) 
		{
			pid = fork();
			if (pid == 0) 
			{
				for (k = 0; k < 100; k++)
				{
					for (j = 0; j < 1000000; j++){}
					//printf(1, "PID : %d\n", getpid());
				}
				exit(); // children exit here
			}
			continue; // father continues to spawn the next child
		}
	for (i = 0; i < n; i++) 
	{
		pid = wait2(&retime, &rutime, &stime);
		printf(1, "CPU-bound, pid: %d, ready: %d, running: %d, sleeping: %d, turnaround: %d \n", pid, retime, rutime, stime, retime + rutime + stime);
		sums[0] += retime;
		sums[1] += rutime;
		sums[2] += stime;
	}
	for (i = 0; i < 3; i++)
		sums[i] /= n;
		printf(1, "\n\nCPU bound:\nAverage ready time: %d\nAverage running time: %d\nAverage sleeping time: %d\nAverage turnaround time: %d\n\n\n", sums[0], sums[1], sums[2], sums[0] + sums[1] + sums[2]);
	retime = 0; 
	rutime = 0;
	stime = 0; 
	}	
	exit();
	}

