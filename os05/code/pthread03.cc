#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS	5

long counter=0;

void* count(void *null){
   for(int i=0;i<10000000;i++) {
		counter++;
   }
   pthread_exit((void *) 0);
}

int main (int argc, char *argv[]){
   pthread_t thread[NUM_THREADS];
//   pthread_attr_t attr;
//   pthread_attr_init(&attr);
//   pthread_attr_setdetachstate(&attr, 
//   			PTHREAD_CREATE_JOINABLE);

   for(int t=0; t<NUM_THREADS; t++){
      printf("Creating thread %d\n", t);
      int rc = pthread_create(&thread[t], NULL, 
      				count, NULL); 
      if (rc){
         printf("ERROR; pthread_create() return %d\n", 
         		rc);
         exit(-1);
      }
   }
//   pthread_attr_destroy(&attr);

   for(int t=0; t<NUM_THREADS; t++){
   	  void *status;
      int rc = pthread_join(thread[t], 
      						(void **)&status);
      if (rc){
         printf("ERROR;  pthread_join() return %d\n", 
         		rc);
         exit(-1);
      }
      printf("Join thread %d status= %ld\n",
      		t, (long) status);
   }
   
   printf("counter=%ld\n",counter);
   pthread_exit(NULL);
   return 0;
}
