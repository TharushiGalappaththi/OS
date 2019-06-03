#include <stdio.h>
#include <stddef.h>

#include "myMalloc.h"

//char memory[25000];

struct block *FList=(void*)memory; // freelist
 
void initialize(){
	FList->size=25000-sizeof(struct block);
	FList->free=1;
	FList->next=NULL;
}

void split(struct block *slot,size_t size){ //slot free block
	struct block *new=(void*)slot+size+sizeof(struct block);
	new->size=(slot->size)-size-sizeof(struct block);
	new->free=1;
	new->next=slot->next;
	slot->size=size;
	slot->free=0;
	slot->next=new;
		
}



void *myMalloc(size_t nbytes){
	struct block *current; //current is Null
	void *result; //result is Null
	
	if(!(FList->size)){
		initialize();
		printf("Memory initialized\n");
	}
	current=FList;
	
	while((((current->size)<nbytes)||((current->free)==0))&&(current->next!=NULL)){
		current=current->next;
		printf("check one block\n");
	}
	if((current->size)==nbytes){
		current->free=0;
		result=(void*)(++current);
		printf("exact block allocation\n");
		return result;
	}
	else if((current->size)>(nbytes+sizeof(struct block))){
		split(current,nbytes);
		result=(void*)(++current);
		printf("block allocated with a split\n");
		return result;
		
	}
	else{
		result=NULL;
		printf("No sufficient memory\n");
		return result; 
	}
}





void merge(){
	struct block *current;
	current=FList;
	while((current->next)!=NULL){
		if((current->free)&&(current->next->free)){
			current->size+=(current->next->size)+sizeof(struct block);
			current->next=current->next->next;
			
		}
		current=current->next;
	}
}
void MyFree(void* ptr){
	if(((void*)memory<=ptr)&&(ptr<=(void*)(memory+25000))){
		struct block* current=ptr;
		--current;
		current->free=1;
		merge();
		
	}
	
}




