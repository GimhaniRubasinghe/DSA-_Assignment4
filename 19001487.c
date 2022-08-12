#include<stdio.h>
 
int findLRU(int time[], int n){//a function to find least recently used page position
	int i, LRU = time[0], position = 0;//suppose slot one has least recently used page
 
	for(i = 1; i < n; ++i){
		if(time[i] < LRU){
			LRU = time[i];//find least recently used page
			position = i;//find least recently used page slot position
		}
	}
	return position;
}
 
int main()
{
    int no_of_eslots, no_of_pages;
	printf("Enter number of empty slots: ");//to get number of empty slots from user
	scanf("%d", &no_of_eslots);
	
	printf("Enter number of pages: ");//to get length of page string
	scanf("%d", &no_of_pages);
	
	int slots[no_of_eslots], Qpages[no_of_pages], val,front,rear,i, counter = 0, time[no_of_eslots], flag1,pos, faults = 0;
	front=rear=-1;
	printf("Enter reference string: ");//to get pages
	
    for(i = 0; i < no_of_pages; ++i){
    	scanf("%d", &val);//get the page value
    	if(front==-1 && rear==-1){//to add page value to the queue
    		front=rear=0;
    		Qpages[rear]=val;
    		rear++;
		}
		else{
			Qpages[rear] = val;
			rear++;
		}
    }
    
	for(i = 0; i < no_of_eslots; ++i){//Use -1 to show all slots have null value in begin 
    	slots[i] = -1;
    }
    
    do{
    	flag1 = 0;//not to do all three loops to one time
    	
    	for(i = 0; i < no_of_eslots; ++i){//if page is already their no need to  add but sholud show it is the most used page
    		if(slots[i] == Qpages[front]){
	    		counter++;
				printf("1 : %d,%d\n",i,counter);
	    		time[i] = counter;
	   			flag1 =  1;
	   			break;
   			}
    	}
    	
    	if(flag1 == 0){//to add pages to empty slots
			for(i = 0; i < no_of_eslots; ++i){
	    		if(slots[i] == -1){
	    			counter++;
	    			faults++;
	    			printf("2 : %d,%d\n",i,counter);
	    			slots[i] = Qpages[front];
	    			time[i] = counter;
	    			flag1 = 1;
	    			break;
	    		}
    		}	
    	}
    	
    	if(flag1 == 0){//if there is no space and page is not already there,fine least recently used page slot and replace slot by using new page
    		pos = findLRU(time, no_of_eslots);
    		counter++;
    		faults++;
    		printf("3 : %d,%d\n",i,counter);
    		slots[pos] = Qpages[front];
    		time[pos] = counter;
    	}
    	
    	printf("\n");
    	
    	for(i = 0; i < no_of_eslots; ++i){//to print slots values 
    		printf("%d\t", slots[i]);
    	}
    	front++;
	}while(front<rear);//to stop loop,when queue is empty
	
	printf("\n\nTotal Page Faults = %d", faults);//to print page faults 
    
    return 0;
}
