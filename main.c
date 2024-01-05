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


void displayBurst(struct node *header) {
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

void displayArrival(struct node *header) {
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

void displayPriority(struct node *header) {
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

struct node *InsertBurst(struct node *header, int item) {
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

struct node *InsertArrival(struct node *header, int item) {
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

struct node *InsertPriority(struct node *header, int item) {
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

struct node *swapAfterNode(struct node *header, struct node *afterNode) //swap a number with it's next
{
	struct node *headerTemp = header;
	while(headerTemp->next!=afterNode)
	{
		headerTemp = headerTemp->next;
	}
	struct node *temp = afterNode->next->next;
	//swap
	headerTemp->next = afterNode->next;
	afterNode->next= temp;
	headerTemp->next->next = afterNode;
	
	return header;
		
}
void fcfsSorted(struct node *ArrivalHead, struct node *BurstHead)
{
    struct node *tempArrivalHead = ArrivalHead;
    struct node *tempBurstHead = BurstHead;

    while (tempArrivalHead != NULL && tempArrivalHead->next != NULL)
    {
        printf("Before Swap: Arrival=%d Burst=%d\n", tempArrivalHead->data, tempBurstHead->data);
        
        if (tempArrivalHead->data > tempArrivalHead->next->data)
        {
            swapAfterNode(tempArrivalHead, tempArrivalHead->next);
            swapAfterNode(tempBurstHead, tempBurstHead->next);
        }
        
        printf("After Swap: Arrival=%d Burst=%d\n", tempArrivalHead->data, tempBurstHead->data);

        tempArrivalHead = tempArrivalHead->next;
    }
}

void FCFS(struct node *OriginalArrivalHead, struct node *OriginalBurstHead)
{
    
    struct node *ArrivalHead = OriginalArrivalHead;
    struct node *BurstHead = OriginalBurstHead;
    int sum = 0;
    int TAT = 0;
    int BT = 0;
    int WT = 0;
    int CT = 0;
    int n = 0;

    // Sort the linked lists
    fcfsSorted(ArrivalHead, BurstHead);

    printf("Burst: ");
    displayBurst(BurstHead);
    printf("\n\n");

    printf("Arrival: ");
    displayArrival(ArrivalHead);
    printf("\n\n");

    printf("Process waiting times:");
    while (ArrivalHead != NULL)
    {
        CT = CT + BurstHead->data;
        TAT = CT - ArrivalHead->data;
        WT = TAT - BurstHead->data;
        printf("\nP %d : %d ms", n + 1, WT);
        sum = sum + WT;
        n++;
        BurstHead = BurstHead->next;
        ArrivalHead = ArrivalHead->next;
    }

    float avg = (float)sum / n;
    printf("\n Average waiting time: %.2f", avg);
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

    struct node *BurstHead = NULL;
    struct node *ArrivalHead = NULL;
    struct node *PriorityHead = NULL;

    char str[100];
    int number, count; 

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
			 		BurstHead = InsertBurst(BurstHead, number);
			 		count++; // increment count for second integer
                   
			 		
				 }
				 else // count will be 1 which means second integer
				 {
				 	ArrivalHead = InsertArrival(ArrivalHead, number);
                   
				 }
               
                
                
                number = 0; // Reset it for the next integer
            }
        }

        PriorityHead = InsertPriority(PriorityHead, number); // Store the last integer in the line
     
        
        // read a new line, repeat the cycle until end of file
    }
    
    fclose(fileRead);

    printf("Burst: ");
    displayBurst(BurstHead);
    printf("\n\n");
    
    printf("Arrival: ");
    displayArrival(ArrivalHead);
    printf("\n\n");
    
    printf("Priority: ");
    displayPriority(PriorityHead);
    printf("\n\n");
    
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
            FCFS(ArrivalHead, BurstHead);
            
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