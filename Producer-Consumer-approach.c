#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<pthread.h>
#define N 100

int count = 0;
pthread_mutex_t mylock;

int insert_item(int item){
	
}



void *producer(){
	int item;
	while(true){
		item=produce_item();
		if(count==N)sleep();
		insert_item(item);
		count=count+1;
		if(count==1)wakeup(consumer);
	}
}

void* consumer(){
	int item;
	while(true){
		if(count==0)sleep();
		item=remove_item();
		count=count-1;
		if(count==N-1)wakeup(producer);	
		consume_item(item);
		
	}
}


main(){
	pthread_mutex_init(&mylock,NULL);
		
	pthread_t thread1,thread2;
	
	
		pthread_create(&thread1,NULL,producer,NULL);
		pthread_create(&thread2,NULL,consumer,NULL);
		

	
	
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
	
	
}
