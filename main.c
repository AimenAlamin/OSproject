#include <stdio.h>
#include <stdlib.h>

struct node {
    int pID;
    int burst;
    int arrival;
    int priority;
    struct node *next;
};

struct node *createNode(int pID, int burst, int arrival, int priority) {
    struct node *header = (struct node *)malloc(sizeof(struct node));
    header->pID = pID;
    header->burst = burst;
    header->arrival = arrival;
    header->priority = priority;
    header->next = NULL;
    return header;
}

void display(struct node *header) {
    if (header == NULL) {
        printf("List is empty");

    } 
    else 
    {
        struct node *temp = header;
        while (temp != NULL) {
            printf("P%d  %d  %d  %d -->  ", temp->pID, temp->burst, temp->arrival, temp->priority);
            temp = temp->next;
        }
    }
}


struct node *InsertBack(struct node *header, int pID, int burst, int arrival, int priority) {
    struct node *temp = createNode(pID, burst, arrival, priority);

    if (header == NULL) {
        header = temp;
        return header;
    }

    struct node *headerTemp = header;
    while (headerTemp->next != NULL) {
        headerTemp = headerTemp->next;
    }
    headerTemp->next = temp;

    return header;
}

void SortbyArrival(struct node *header)
{
    struct node *i;
    struct node *j;
    int tempPID, tempBur, tempArr, tempPri;

    if (header == NULL)
    {
        printf("List is empty");

    } 
    else
    {
        for(i=header; i->next!=NULL; i=i->next)
        {
            for(j=i->next; j!=NULL; j=j->next)
            {
                if(i->arrival > j->arrival)
                {
                    tempPID = i->pID;
                    i->pID = j->pID;
                    j->pID = tempPID;

                    tempBur = i->burst;
                    i->burst = j->burst;
                    j->burst = tempBur;
                    
                    tempArr = i->arrival;
                    i->arrival = j->arrival;
                    j->arrival = tempArr;

                    tempPri = i->priority;
                    i->priority = j->priority;
                    j->priority = tempPri;
                }

                 if(i->arrival == j->arrival) // if two process have same arrival time, sort by less process id
                {
                    if(i->pID > j->pID)
                 {
                    tempPID = i->pID;
                    i->pID = j->pID;
                    j->pID = tempPID;

                    tempBur = i->burst;
                    i->burst = j->burst;
                    j->burst = tempBur;
                    
                    tempArr = i->arrival;
                    i->arrival = j->arrival;
                    j->arrival = tempArr;

                    tempPri = i->priority;
                    i->priority = j->priority;
                    j->priority = tempPri;
                 }
                }
            }
        }

    }

}

void SortbyBurst(struct node *header)
{
    struct node *i;
    struct node *j;
    int tempPID, tempBur, tempArr, tempPri;

    if (header == NULL)
    {
        printf("List is empty");

    } 
    else
    {
        for(i=header; i->next!=NULL; i=i->next)
        {
            for(j=i->next; j!=NULL; j=j->next)
            {
                if(i->burst > j->burst)
                {
                    tempPID = i->pID;
                    i->pID = j->pID;
                    j->pID = tempPID;

                    tempBur = i->burst;
                    i->burst = j->burst;
                    j->burst = tempBur;
                    
                    tempArr = i->arrival;
                    i->arrival = j->arrival;
                    j->arrival = tempArr;

                    tempPri = i->priority;
                    i->priority = j->priority;
                    j->priority = tempPri;
                }

                if(i->burst == j->burst) // if two process have same burst time, sort by less arrival time
                {
                    if(i->arrival > j->arrival)
                {
                    tempPID = i->pID;
                    i->pID = j->pID;
                    j->pID = tempPID;

                    tempBur = i->burst;
                    i->burst = j->burst;
                    j->burst = tempBur;
                    
                    tempArr = i->arrival;
                    i->arrival = j->arrival;
                    j->arrival = tempArr;

                    tempPri = i->priority;
                    i->priority = j->priority;
                    j->priority = tempPri;
                }
                }
            }
        }

    }

}

void SortbyPriority(struct node *header)
{
    struct node *i;
    struct node *j;
    int tempPID, tempBur, tempArr, tempPri;

    if (header == NULL)
    {
        printf("List is empty");

    } 
    else
    {
        for(i=header; i->next!=NULL; i=i->next)
        {
            for(j=i->next; j!=NULL; j=j->next)
            {
                if(i->priority > j->priority)
                {
                    tempPID = i->pID;
                    i->pID = j->pID;
                    j->pID = tempPID;

                    tempBur = i->burst;
                    i->burst = j->burst;
                    j->burst = tempBur;
                    
                    tempArr = i->arrival;
                    i->arrival = j->arrival;
                    j->arrival = tempArr;

                    tempPri = i->priority;
                    i->priority = j->priority;
                    j->priority = tempPri;
                }

                if(i->priority == j->priority)
                {
                    if(i->arrival > j->arrival)
                {
                    tempPID = i->pID;
                    i->pID = j->pID;
                    j->pID = tempPID;

                    tempBur = i->burst;
                    i->burst = j->burst;
                    j->burst = tempBur;
                    
                    tempArr = i->arrival;
                    i->arrival = j->arrival;
                    j->arrival = tempArr;

                    tempPri = i->priority;
                    i->priority = j->priority;
                    j->priority = tempPri;
                }

                }
            }
        }

    }

}

void fcfsNonPreemptive(struct node *header, char *outFilepath)
{
    if (header == NULL)
    {
        printf("List is empty");

    } 
    else
    {
        FILE *outFile = fopen(outFilepath, "a");
        SortbyArrival(header);

        struct node *temp = header;
        int sum =0;
        int TAT =0;
        int BT =0;
        int WT =0;
        int CT =0;
        int n=0;
        fprintf(outFile, "\nScheduling method: First Come First Served, Non-Preemptive\n"); 
        fprintf(outFile, "Process waiting times:");

        printf("Scheduling method: First Come First Served, Non-Preemptive\n");
        printf("Process waiting times:");
        
        while(temp!=NULL)
        {
            CT = CT + temp->burst;
            TAT = CT - temp->arrival;
            WT = TAT - temp ->burst;
            if(WT<0)
            {
                WT=0;
            }
            printf("\nP%d : %d ms \t%d \t%d", temp->pID, WT,CT,TAT);
            fprintf(outFile,"\nP%d : %d ms", temp->pID, WT );
            sum = sum + WT;
            n++;
            temp = temp->next;
        }

        float avg = (float)sum/n;
        printf("\n Average waiting time: %.2f ms", avg);
        fprintf(outFile,"\n Average waiting time: %.2f ms\n", avg);
        fclose(outFile);
    }
}

void fcfsPreemptive(struct node *header, char *outFilepath)
{
    if (header == NULL)
    {
        printf("List is empty");

    } 
    else
    {
        FILE *outFile = fopen(outFilepath, "a");
        SortbyArrival(header);

        struct node *temp = header;
        int sum =0;
        int TAT =0;
        int BT =0;
        int WT =0;
        int CT =0;
        int n=0;
        fprintf(outFile, "\nScheduling method: First Come First Served, Preemptive\n"); 
        fprintf(outFile, "Process waiting times:");

        printf("Scheduling method: First Come First Served, Preemptive\n");
        printf("Process waiting times:");
        
        while(temp!=NULL)
        {
            CT = CT + temp->burst;
            TAT = CT - temp->arrival;
            WT = TAT - temp ->burst;
            printf("\nP%d : %d ms", temp->pID, WT);
            fprintf(outFile,"\nP%d : %d ms", temp->pID, WT );
            sum = sum + WT;
            n++;
            temp = temp->next;
        }

        float avg = (float)sum/n;
        printf("\n Average waiting time: %.2f ms", avg);
        fprintf(outFile,"\n Average waiting time: %.2f ms\n", avg);
        fclose(outFile);
    }
}

void sjfNonPreemptive(struct node *header, char *outFilepath)
{
    if (header == NULL)
    {
        printf("List is empty");

    } 
    else
    {
        FILE *outFile = fopen(outFilepath, "a");
        SortbyArrival(header);

        struct node *temp1 = header;
        int sum =0;
        int TAT =0;
        int BT =0;
        int WT =0;
        int CT =0;
        int n=0;
        fprintf(outFile, "\nScheduling method: Shortest Job First. Non-Preemptive\n"); 
        fprintf(outFile, "Process waiting times:");

        printf("Scheduling method: Shortest Job First. Non-Preemptive\n");
        printf("Process waiting times:");
            //execute the first process that arrived
            CT = CT + temp1->burst;
            TAT = CT - temp1->arrival;
            WT = TAT - temp1->burst;
            printf("\nP%d : %d ms", temp1->pID, WT);
            fprintf(outFile,"\nP%d : %d ms", temp1->pID, WT );
            sum = sum + WT;
            n++;
            
            struct node *temp2 = temp1->next; //hold the remaning list in temp2
            SortbyBurst(temp2); //sort them based on burst time

        while(temp2!=NULL)
        { 
            CT = CT + temp2->burst;
            TAT = CT - temp2->arrival;
            WT = TAT - temp2->burst;
            printf("\nP%d : %d ms", temp2->pID, WT);
            fprintf(outFile,"\nP%d : %d ms", temp2->pID, WT );
            sum = sum + WT;
            n++;
            temp2 = temp2->next;
        }

        float avg = (float)sum/n;
        printf("\n Average waiting time: %.2f ms", avg);
        fprintf(outFile,"\n Average waiting time: %.2f ms\n", avg);
        fclose(outFile);
    }
}

void priorityNonPreemptive(struct node *header, char *outFilepath)
{
    if (header == NULL)
    {
        printf("List is empty");

    } 
    else
    {
        FILE *outFile = fopen(outFilepath, "a");
        SortbyArrival(header);

        struct node *temp1 = header;
        int sum =0;
        int TAT =0;
        int BT =0;
        int WT =0;
        int CT =0;
        int n=0;
        fprintf(outFile, "\nScheduling method: Priority Scheduling. Non-Preemptive\n"); 
        fprintf(outFile, "Process waiting times:");

        printf("Scheduling method: Priority Scheduling. Non-Preemptive\n");
        printf("Process waiting times:");
        //execute the first process that arrived
            CT = CT + temp1->burst;
            TAT = CT - temp1->arrival;
            WT = TAT - temp1->burst;
            printf("\nP%d : %d ms", temp1->pID, WT);
            fprintf(outFile,"\nP%d : %d ms", temp1->pID, WT );
            sum = sum + WT;
            n++;
            
            struct node *temp2 = temp1->next; //hold the remaning list in temp2
            SortbyPriority(temp2); //sort them based on priority

        while(temp2!=NULL)
        { 
            CT = CT + temp2->burst;
            TAT = CT - temp2->arrival;
            WT = TAT - temp2->burst;
            printf("\nP%d : %d ms", temp2->pID, WT);
            fprintf(outFile,"\nP%d : %d ms", temp2->pID, WT );
            sum = sum + WT;
            n++;
            temp2 = temp2->next;
        }

        float avg = (float)sum/n;
        printf("\n Average waiting time: %.2f ms", avg);
        fprintf(outFile,"\n Average waiting time: %.2f ms\n", avg);
        fclose(outFile);
    }
}

int main(int argc, char *argv[]) // here I'm getting arguments from command line
{
	
	if(argc!=5)
	{
		printf("Invalid number of arguments. write ./Main –f input.txt –o output.txt");
		return 1;
	}
	
	FILE *fileRead = fopen(argv[2], "r"); //here I stored the file I will read from
	FILE *fileAppend = fopen(argv[4], "a"); //here I stored the file I will append to  
	
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

    struct node *head = NULL;

    char str[100];
    int number, count; 
    int pID = 1;
    int burst,arrival,priority;

    while(fgets(str, 100, fileRead)!=NULL) //reading from file and storing integer to linked list
    {
		number = 0;
        count = 0;
		int i;
        // Iterate through the characters and store the integers in linked list
        for (i = 0; str[i] != '\0' && str[i] != '\n'; i++)
		 {
            if (str[i] >= '0' && str[i] <= '9')
			 {
                number = number * 10 + (str[i] - '0');
            } 
			else if (str[i] == ':')  // If a colon is encountered, store the integer in the linked list
			 {
			 	if(count==0) //store the first integer here
			 	{
			 		burst = number;
			 		count++; // increment count for second integer
                   
			 		
				 }
				 else // count will be 1 which means second integer
				 {
				 	arrival = number;
                   
				 }
               
                
                
                number = 0; // Reset it for the next integer
            }
        }

       priority = number; // Store the last integer in the line
       
       head = InsertBack(head, pID, burst, arrival, priority);

        // read a new line, repeat the cycle until end of file
        pID++; //increment the process id
    }
    
    fclose(fileRead);
/*
    printf("\nOriginal Linked list\n");
    display(head);

    printf("\n\nSorted by Arrival Linked list\n");
    SortbyArrival(head);
    display(head);

   printf("\n\nSorted by Burst Linked list\n");
    SortbyBurst(head);
    display(head);

   printf("\n\nSorted by Priority Linked list\n");
   SortbyPriority(head);
    display(head);
    printf("\n");
*/
    int op; // used to select which option 
    int sh;      // used to select which scheduling method
    int preemptiveOption = 0;  // 0 for non-preemptive, 1 for preemptive. By default it is non-preemptive mode
    int Tq;      // used for time quantum value
	
		
	printf("\n");
    printf("\tCPU Scheduler Simulator\n 1- View Scheduling Methods \n 2- Change Preemptive Mode \n 3- Show Result \n 4- End Program \n  OPTION > ");
    scanf("%d", &op);
	
    while (op != 4)
    {
        if (op == 1)
        {
            printf("\n 1- FCFS \n 2- SJF \n 3- Priority Scheduling \n 4- Round Robbin\n 5- None\n  OPTION > ");
            scanf("%d", &sh);

            printf("\n");

            if(sh == 1)
            {
                if (preemptiveOption == 0)
                {
                    printf("First Come First Served Non-Preemptive successfully executed\n");
                //FCFSnonPreemptive(head, argv[4]);
                }
                else if (preemptiveOption == 1)
                {
                    printf("First Come First Served Preemptive successfully executed\n");
                //FCFSpreemptive(head, argv[4]);
                }
            }
            else if(sh == 2)
            {
                if (preemptiveOption == 0)
                {
                    printf("Shortest Job First Non-Preemptive successfully executed\n");
                //sjfNonPreemptive(head, argv[4]);
                }
                else if (preemptiveOption == 1)
                {
                    printf("Shortest Job First Preemptive successfully executed\n");
                //sjfPreemptive(head, argv[4]);
                }
            }
            else if(sh == 3)
            {
                if (preemptiveOption == 0)
                {
                    printf("Priority Non-Preemptive successfully executed\n");
                // priorityNonPreemptive(head, argv[4]);
                }
                else if (preemptiveOption == 1)
                {
                    printf("Priority Preemptive successfully executed\n");
                // priorityPreemptive(head, argv[4]);
                }
            }
            else if(sh == 4)
            {
                if (preemptiveOption == 0)
                {
                    printf("\nScheduling method: Round Robin Non-Preemptive, please enter Time quantum: ");
                    scanf("%d", &Tq);
                    printf("\nTime quantum = %d\n", Tq);
                    printf("Round Robbin Non-Preemptive successfully executed\n");
                
                }
                else if (preemptiveOption == 1)
                {
                    printf("\nScheduling method: Round Robin Preemptive, please enter Time quantum: ");
                    scanf("%d", &Tq);
                    printf("\nTime quantum = %d\n", Tq);
                    printf("Round Robbin Preemptive successfully executed\n");
                
                }
            }
            else if(sh == 5)
            {
                printf("None of scheduling method chosen\n");
            }
            else
            {
                printf("Error. Please select one of the available options\n");
            }


             
        }

        else if (op == 2)
        {
            printf("\nSelect 0 for non-preemptive or 1 for preemptive: ");
            scanf("%d", &preemptiveOption);
            if (preemptiveOption != 0 && preemptiveOption != 1)
            {
            	printf("\nError, invalid preemptive option\n");
			
			}
            
        }
        

        else if (op == 3)
        {
            printf("\n");

            if(sh==1 && preemptiveOption == 0)
            {
                fcfsNonPreemptive(head, argv[4]);
            }
            else if(sh==1 && preemptiveOption == 1)
            {
                fcfsPreemptive(head, argv[4]);
            }

            else if(sh==2 && preemptiveOption == 0)
            {
                sjfNonPreemptive(head, argv[4]);
            }
            else if(sh==2 && preemptiveOption == 1)
            {
                //sjfPreemptive(head, argv[4]);
            }

            else if(sh==3 && preemptiveOption == 0)
            {
                priorityNonPreemptive(head, argv[4]);
            }
            else if(sh==3 && preemptiveOption == 1)
            {
                printf("Didn't do it");
                //priorityPreemptive(head, argv[4]);
            }

            else if(sh==4 && preemptiveOption == 0)
            {
                printf("Didn't do it");
                //RoundRobbinNonPreemptive(head, argv[4]);
            }
            else if(sh==3 && preemptiveOption == 1)
            {
                printf("Didn't do it");
                //RoundRobbinPreemptive(head, argv[4]);
            }

            else{

                printf("Nothing to display, you didn't pick a scheduling method");
            }
           
        }
        else
        {
            printf("\nError. Please select one of the available options\n");
            
        }
        

        printf("\n\n");
        printf("\tCPU Scheduler Simulator\n 1- View Scheduling Methods \n 2- Change Preemptive Mode \n 3- Show Result \n 4- End Program \n  OPTION > ");
        scanf("%d", &op);

       
    }
    printf("\n\t\tProgram terminated.....\n");
    fclose(fileAppend);

    FILE *fileEnd = fopen(argv[4], "r");

    if(fileEnd==NULL)
    {
        printf("File is empty");
        
    }

    char str2[100];
    while(fgets(str2, 100, fileEnd)!=NULL) //reading from file output and printing it to screen
    {
        printf("%s",str2);
    }

    
	return 0;
}