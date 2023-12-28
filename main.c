#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *createNode(int item) {
    struct node *header = (struct node *)malloc(sizeof(struct node));
    header->data = item;
    header->next = NULL;
    return header;
}

void display(struct node *header) {
    if (header == NULL) {
        printf("List is empty");
    } else {
        struct node *temp = header;
        while (temp != NULL) {
            printf("%d  --> ", temp->data);
            temp = temp->next;
        }
    }
}

struct node *InsertBack(struct node *header, int item) {
    struct node *temp = createNode(item);

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

    struct node *head = NULL;

    char str[100];
    int number; 
    while(fgets(str, 100, fileRead)!=NULL) //reading from file and storing integer to linked list
    {
		number = 0;
		int i;
        // Iterate through the characters and store the integers in linked list
        for (i = 0; str[i] != '\0' && str[i] != '\n'; i++)
		 {
            if (str[i] >= '0' && str[i] <= '9')
			 {
                number = number * 10 + (str[i] - '0');
            } 
			else if (str[i] == ':')
			 {
                // If a colon is encountered, store the integer in the linked list
                head = InsertBack(head, number);
                number = 0; // Reset it for the next integer
            }
        }

        // Store the last integer in the line
        head = InsertBack(head, number);
        // read a new line, repeat the cycle until end of file
    }

    fclose(fileRead);

    display(head);
    
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
    
	fclose(fileAppend);
    
	return 0;
}