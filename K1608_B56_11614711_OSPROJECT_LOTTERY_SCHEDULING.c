#include <stdio.h>
#include <sys/types.h>                                       //the are headerfiles
#include <unistd.h>
#include <stdlib.h>                                    //the are headerfiles
#include <string.h>
#include <time.h>                                 //the are headerfiles
                 
void main()                                    //main Function
{
	char process[5] = { 'p1', 'p2', 'p3', 'p4', 'p5'},temp[10];                   //Declaration of process
	int ArrivaTimeofprocess[10];                                                       //arrival time for each process
	int brustTime[10];                                                          //burst time for each process
	int ticketAllotetToProcess[10][10];                                         //tickets allocated for each process
	int lotterySelectionForProcess[10] = {0,0,0,0,0,0,0,0,0,0};                   //lottery selection
	int i,j,z,p=0,max_tickForProcess,q=0,siva=0;                                     //dclarition for other
	
		//Generate ArrivaTimeofprocess time for each process randomly
		
		/* here we are going to give the arrival
		time for 
		all the process according to their priority*/
	for(i=0;i<5;i++)
	{
		int num = (rand()%6)+ 1;                                             //alloting random arrival time
		ArrivaTimeofprocess[i] = num;                                    
	}
	
	                                                                                //Generate brustTime time for each process randomly
	for(j=0;j<5;j++)
	{
		int num = (rand()%6) + 1;                     //random number b/w {1,12}                     //alloting random burst time
		/*we are randomly selecting thethe processes  based on lottaryticketss
		*/
		brustTime[j] = num;
	}
	printf("\n**********THIS IS THE PROGRAM FOR LOTTERY SCHEDULINGGG******************\n");
	
	printf("Process                       ArrivaTimeofprocess                  brustTime ");
	
	/* we are going to print the process and their process time arrival time
	and burst time */
	for(i=0;i<5;i++)
	{
		printf("\n  %c \t                   \t  %d                      \t\t%d",process[i],ArrivaTimeofprocess[i],brustTime[i]);               //giving output for the process
	}
	
	printf("\n\n+++++++++    1  Quantom  =1 second  ++++++++++++++ \n\n");
	
	int time = 0,quantom=1;
	
                                                                                             //arrange them on the bases of there ArrivaTimeofprocess time
                                                                                             
                                                                                             /*we are actually comparing the arrival time for each process
                                                                                             according to it we are giving permission for process 
																							 from ready queqe to process cpu*/
	for (i= 0;i<5;i++)
	{
		for(j=0;j<4;j++) 
		{                                                                             //we are just arranging them according to there arrival process
			if (ArrivaTimeofprocess[j] >= ArrivaTimeofprocess[j + 1])
			{
				int temp2 = ArrivaTimeofprocess[j];
                ArrivaTimeofprocess[j] = ArrivaTimeofprocess[j + 1];
                ArrivaTimeofprocess[j + 1] = temp2;

                char temp1 = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp1;
			}
		}	
	}	
	
	//we are printing output
	printf("Process                       ArrivaTimeofprocess                  brustTime ");
	
	for(i=0;i<5;i++)
	{
		printf("\n  %c \t                   \t  %d                      \t\t%d",process[i],ArrivaTimeofprocess[i],brustTime[i]);         //it will give output  
	}
                 
   while((brustTime[0]+brustTime[1]+brustTime[2]+brustTime[3]+brustTime[4])>0){
   
   	printf("\n\n\nBrust  process    lotterySelectionForProcess \t Tickets");
    p =0;
    max_tickForProcess = 0;
                                                                              //assign 1 0r moree lotterySelectionForProcess numbers to each process
	for(i=0;i<5;i++)
	{
		if(brustTime[i]>0)
		{
			lotterySelectionForProcess[i]=brustTime[i]/2;
			if ((lotterySelectionForProcess[i] == 0) && (brustTime[i] > 0))
                lotterySelectionForProcess[i] = 1;
               
			for (z = 0; z < lotterySelectionForProcess[i]; z++) {
                    ticketAllotetToProcess[i][z] = p++;
                        max_tickForProcess = p;
                    }
                    temp[i] = process[i];   
					
			printf("\n  %d          %c      \t\t\t%d",brustTime[i],temp[i],lotterySelectionForProcess[i]);
			for(z=0;z<lotterySelectionForProcess[i];z++)
			{
				printf("\t*******%d*****",ticketAllotetToProcess[i][z]);
			   }   
		}
		
		else if ((brustTime[i] > 0) && (time < ArrivaTimeofprocess[i]))
		{
			temp[i] = process[p];
            lotterySelectionForProcess[i] = brustTime[i] / 2;
            if ((lotterySelectionForProcess[i] == 0) && (brustTime[i] > 0))
                lotterySelectionForProcess[i] = 1;
                
            for (z = 0; z < lotterySelectionForProcess[i]; z++){
                ticketAllotetToProcess[i][z] = p++;
                max_tickForProcess=p;
            }
            
            if (brustTime[i] > 0) {
                time += quantom;
                } else {
                    time += (brustTime[i] + quantom);
                }
                
            printf("\n  %d\t   %c\t\t%d",brustTime[i],temp[i],lotterySelectionForProcess[i]);
			for(z=0;z<lotterySelectionForProcess[i];z++)
			{
				printf("\t---%d---",ticketAllotetToProcess[i][z]);
			}       
		}
	}
	
	
	int winner = (rand()%max_tickForProcess-1)+ 1;;
    for(i =0;i<10;i++)
        for(z=0;z<lotterySelectionForProcess[i];z++)
            if(ticketAllotetToProcess[i][z]==winner)
                q=i;
    printf("\n\n\n\n\n***********************************");
    printf("************  WinnerProcess fom alll is: %d ************",winner);
    printf("------------------------\n\n");
	
	
	if ((brustTime[q] > 0))  
	{
        temp[q] = process[q];
        brustTime[q] -= quantom;
        
        if (brustTime[q] > 0) {
            time += quantom;
        } else {
            time += (brustTime[q] + quantom);
            }
		
		if (brustTime[q] < 0) {
                brustTime[q] = 0;                                                                // the present process which is  That Are Running Is
            }
	    printf("===================>>Process That Are Running Is: %c",temp[q]);
	    printf("\n(Total Time \t\t    Remaining brustTime time\t\tprocesstime" ); 
		printf("\n %d \t\t\t\t\t   %d  \t\t\t %c \n\n",time,brustTime[q],temp[q]);
	
    }
    
    else if ((brustTime[q] > 0) && (time < ArrivaTimeofprocess[q])) {
        temp[q] = process[p];
        if (brustTime[q] > 0) {
                time += quantom;
        } else {
                time += (brustTime[q] + quantom);
        }
        
        printf("\n++++++++>>>> the running process is: %c",temp[q]);
	    printf("\n%d \t%d \t%c\n\n",time,brustTime[q],temp[q]);
    }
    siva++;
}
    printf("\n...............................-----------------------------------------.....................\n");
     printf("\n\n----------->> Total Time Taken by CPU to Run All The Process: %d Sec  <<----------\n\n\n",time);
     printf("\n\n****************^^^^^^^^^^^^^^^tihs is the program about LOTTERY SCHEDULING*****************^^^^^^^^^^^^");
     
}
