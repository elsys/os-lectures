#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS	3

void *busy_work(void *null){
   double result=0.0;
   for (int i=0; i<1000000; i++){
     result = result + (double)random();
   }
   printf("result = %e\n",result);
   pthread_exit((void *) 0);
}

int main (int argc, char *argv[]){
   pthread_t thread[NUM_THREADS];
   for(int t=0; t<NUM_THREADS; t++){
      printf("Creating thread %d\n", t);
      int rc = pthread_create(&thread[t], NULL, 
      				busy_work, NULL); 
      if (rc){
         printf("ERROR; pthread_create() return %d\n", 
         		rc);
         exit(-1);
      }
   }

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
   pthread_exit(NULL);
   return 0;
}
