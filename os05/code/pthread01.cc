#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	5

void *print_hello(void *thread_id){
   int tid;
   tid = (int)thread_id;
   printf("Hello World! It's me, thread #%d!\n", tid);
   pthread_exit(NULL);
}

int main(int argc, char *argv[]){
	pthread_t threads[NUM_THREADS];
	for(int t=0;t<NUM_THREADS;t++){
	  printf("In main: creating thread %d\n", t);
	  int rc = pthread_create(&threads[t], NULL, 
	  						print_hello, (void *)t);
	  if (rc){
	    printf("ERROR; pthread_create() return %d\n", 
	    		rc);
	    exit(-1);
	  }
	}
	printf("MAIN going to exit...\n");
	pthread_exit(NULL);
	return 0;
}
