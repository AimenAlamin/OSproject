#include<stdio.h>

int main(int argc, char *argv[]) // here I'm getting arguments from command line
{
	
	if(argc!=5)
	{
		printf("Invalid number of arguments. write ./Main –f input.txt –o output.txt");
		return 1;
	}
	
	FILE *fpr = fopen(argv[2], "r"); //here I stored the file I will read from as fpr 
	FILE *fpa = fopen(argv[4], "a"); //here I stored the file I will append to as fpa 
	
	if(fpr==NULL)
    {
        printf("Error, can't open file");
        return 1;
    }
    if(fpa==NULL)
    {
        printf("Error, can't open file");
        return 1;
    }
    
    int sh; // used to select which scheduling method
	int sjfOpt; // used to select preemptive or non-preemptive for sjf method
	int priOpt; // used to select preemptive or non-preemptive for priortiy method
	int Tq; //used for time quantum value
	int ch; //for reading from file
		
	printf("\n");
	printf("From the following options\n 1-FCFS \n 2-SJF \n 3-Priority Scheduling \n 4-Round Robbin \n 5-End the program\n");
	printf("Select the scheduling method: ");
	scanf("%d",&sh);
	printf("\n");
	
	while(sh!=5)
	{
		if(sh==1)
		{
			printf("Scheduling method: First Come First Served\n");
			printf("Process waiting time:\n");
			printf("\nAverage waiting time:");
		}
		else if(sh==2)
		{
			printf("Scheduling method: Shortest Job First. Press 18 for non-preemptive or 20 for preemptive: ");
			scanf("%d",&sjfOpt);
			printf("\n");
			if(sjfOpt==18)
			{
				printf("Scheduling method: Shortest Job First. Non-Preemptive\n");
				printf("Process waiting time:\n");
				printf("\nAverage waiting time:");
			}
			else if(sjfOpt==20)
			{
				printf("Scheduling method: Shortest Job First. Preemptive\n");
				printf("Process waiting time:\n");
				printf("\nAverage waiting time:");
			}
			else{
				printf("Error, Press 18 for non-preemptive or 20 for preemptive ");
			}
		}
		else if(sh==3)
		{
			printf("Scheduling method: Priority Scheduling. Press 18 for non-preemptive or 20 for preemptive: ");
			scanf("%d",&priOpt);
			printf("\n");
			if(priOpt==18)
			{
				printf("Scheduling method: Priority Scheduling. Non-Preemptive\n");
				printf("Process waiting time:\n");
				printf("\nAverage waiting time:");
			}
			else if(priOpt==20)
			{
				printf("Scheduling method: Priority Scheduling. Preemptive\n");
				printf("Process waiting time:\n");
				printf("\nAverage waiting time:");
			}
			else{
				printf("\nError, Press 18 for non-preemptive or 20 for preemptive ");
			}
		}
		else if(sh==4)
		{
			printf("Scheduling method: Round Robbin, please enter Time quantum: ");
			scanf("%d",&Tq);
			printf("Time quantum = %d\n", Tq);
			printf("Process waiting time:\n");
			printf("\nAverage waiting time:");
		}
		else
		{
			printf("Error, you didn't specify the scheduling method\n");
		}
		
		printf("\n\nFrom the following options\n 1-FCFS \n 2-SJF \n 3-Priority Scheduling \n 4-Round Robbin \n 5-End the program");
		printf("\nSelect the scheduling method: ");
		scanf("%d",&sh);
		
	}
	printf("\nProgram terminated");
    
	return 0;
}