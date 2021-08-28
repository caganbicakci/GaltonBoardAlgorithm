#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#define N 100000

pthread_t tid;
pthread_mutex_t lock;
int cell[20];

void* calculate(void *arg)
{
	int a=0;
	int counter=0;
	int j=0;
	int random=0;
	int b;

	for(j=0; j<19; j++){
		  
		  random = rand() % 2;
		  if(random == 1){
		  counter++;
		  }
	}
	
	pthread_mutex_lock(&lock);
   	cell[counter] += 1; 
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(void)
{
    int i;
    int k;
    int createdThread = 0;
    int sum;
    
	
	srand(time(NULL));
    
    for(i=0;i<N;i++){
    	
    	
        int numOfThread = pthread_create(&(tid), NULL, &calculate, NULL);
		
		if (numOfThread == 0) {
		 createdThread++;
		}
		
                
    }

	for(i=0;i<N;i++){
		pthread_join(tid, NULL);
	}
		

	
	 printf("Cell: Value \n-----------\n");
        for (k=0; k<20; k++){
        	sum += cell[k];
        	printf("\n%d:  %d",k, cell[k]); 
        }
         printf("\n\nSuccessfully created threads: %d\n",createdThread);
         printf("Sum of values in the cells: %d\n",sum);
       
		 
 	return 0;
}
