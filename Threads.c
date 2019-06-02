#include<stdio.h>
#include<pthread.h>
#include<inttypes.h>
#define SIZE 40

pthread_mutex_t mylock;
int a[SIZE];
long countl=0;
int wload=SIZE/2;


	void *vCount(void *id){
	int low,high,myid;
	int result=0;
	
	myid=(intptr_t)id;
	low=wload*myid;
	high=low+wload;
	
		int r=1;//initial num of virus
		for(int i=low;i<high;i++){
			result+=a[i];
			
		
				}
	    pthread_mutex_lock(&mylock);
		countl+=result;	
		pthread_mutex_unlock(&mylock);
		
}


main(){
	pthread_mutex_init(&mylock,NULL);
		long r=1;//initial num of virus
		for(int i=0;i<SIZE;i++){
			a[i]=r;
			r=2*r;
			printf("%d ",a[i]);
		}
	printf("\n\n");
	pthread_t thread1,thread2;
	
	
		pthread_create(&thread1,NULL,vCount,(void*)0);
		pthread_create(&thread2,NULL,vCount,(void*)1);
		

	
	
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
	printf("Total Num of virus Count =%d ",countl);
	
}