#include<stdio.h>
#include<string.h>
#include<time.h>

int main(){
	time_t end , start;
	double diff;
	time(&start);
	sleep(2);
	time(&end);
	diff = difftime(end , start);
	printf("%f " , time(NULL));
	return 0;
}
