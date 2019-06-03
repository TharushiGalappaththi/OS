#include <stdio.h>
#include <stddef.h>

char memory[25000];

struct block{
	size_t size;
	int free;
	struct block *next;
};

void initialize();
void split(struct block *slot, size_t size);
void *myMalloc(size_t nbytes); //no of bytes
void merge();
void MyFree(void* ptr);


 
