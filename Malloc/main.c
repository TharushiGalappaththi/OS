#include <stdio.h>
#include "myMalloc.c"


int main(){

	int *temp1 = (int*)myMalloc(200*sizeof(int));
	char *temp2 = (char*)myMalloc(150*sizeof(char));
	int *temp3 = (int*)myMalloc(1000*sizeof(int));
	MyFree(temp1);
	char *temp4 = (char*)myMalloc(600);
	int *temp5 = (int*)myMalloc(300*sizeof(int));
	MyFree(temp3);
	int *temp6 = (int*)myMalloc(200*sizeof(int));

	int *s;
	int *a=(int*)myMalloc(12000*sizeof(int));
	MyFree(s);
	

	return 0;
}
