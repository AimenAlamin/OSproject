#include<stdio.h>

int main(int argc, char *argv[]) // here I'm getting arguments from command line
{
	
	if(argc!=5)
	{
		printf("Invalid number of arguments. write ./Main –f input.txt –o output.txt");
		return 1;
	}
	
	FILE *fileRead = fopen(argv[2], "r"); //here I stored the file I will read from as fpr 
	FILE *fileAppend = fopen(argv[4], "a"); //here I stored the file I will append to as fpa 
	
	if(fileRead==NULL)
    {
        printf("Error, can't open file");
        return 1;
    }
    if(fileAppend==NULL)
    {
        printf("Error, can't open file");
        return 1;
    }
    char str[15]; // buffer to store characters 
    while(fgets(str, 15, fileRead)!=NULL)
    {
		printf("%s",str);  //printing file input
    }
    
    int sh;      // used to select which scheduling method
    int preemptiveOption = 0;  // 0 for non-preemptive, 1 for preemptive. By default it is non-preemptive mode
    int Tq;      // used for time quantum value
	int ch; //for reading from file
		
	printf("\n");
	printf("From the following options\n 1-FCFS \n 2-SJF \n 3-Priority Scheduling \n 4-Round Robbin \n 5-Change Preemptive Mode\n 6-End the program\n ");
    printf("Select the scheduling method: ");
    scanf("%d", &sh);
    printf("\n");
	
    while (sh != 6)
    {
        if (sh == 1)
        {
            printf("Scheduling method: First Come First Served\n");
            printf("Process waiting time:\n");
            printf("\nAverage waiting time:");
        }
        else if (sh == 2)
        {
            printf("Scheduling method: Shortest Job First. ");
            if (preemptiveOption == 0)
            {
                printf("Non-Preemptive\n");
            }
            else if (preemptiveOption == 1)
            {
                printf("Preemptive\n");
            }
            
            printf("Process waiting time:\n");
            printf("\nAverage waiting time:");
        }
        else if (sh == 3)
        {
            printf("Scheduling method: Priority Scheduling. ");
            if (preemptiveOption == 0)
            {
                printf("Non-Preemptive\n");
            }
            else if (preemptiveOption == 1)
            {
                printf("Preemptive\n");
            }
           
            printf("Process waiting time:\n");
            printf("\nAverage waiting time:");
        }
        else if (sh == 4)
        {
            printf("Scheduling method: Round Robin, please enter Time quantum: ");
            scanf("%d", &Tq);
            printf("Time quantum = %d\n", Tq);
            printf("Process waiting time:\n");
            printf("\nAverage waiting time:");
        }
        else if (sh == 5)
        {
            printf("Select 0 for non-preemptive or 1 for preemptive: ");
            scanf("%d", &preemptiveOption);
            if (preemptiveOption != 0 && preemptiveOption != 1)
            {
            	printf("\nError, invalid preemptive option\n");
				return 1;	
			}
            printf("\n");
        }
        else
        {
            printf("Error, you didn't specify the scheduling method\n");
        }

        printf("\n\nFrom the following options\n 1-FCFS \n 2-SJF \n 3-Priority Scheduling \n 4-Round Robbin \n 5-Change Preemptive Mode\n 6-End the program\n");
        printf("\nSelect the scheduling method: ");
        scanf("%d", &sh);
        printf("\n");

       
    }
    printf("\nProgram terminated");
    fclose(fileRead);
	fclose(fileAppend);
    
	return 0;
}