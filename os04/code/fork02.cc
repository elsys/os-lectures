#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main () {
	int status;
	pid_t pid;
	pid = fork ();
	if (pid < 0) {
		/* The fork failed. Report failure. */
		status = -1;
		printf("Unsuccessful fork...\n");
	} else if (pid == 0){
		/* This is the child process. */
		printf("going to run shell from child...\n");
		execl("/bin/sh","/bin/sh",NULL);
	}
	else {
		/* This is the parent process. 
		 * Wait for the child to complete. */
		if (waitpid (pid, &status, 0) != pid) {
			status = -1;
		}
		printf("child process finished %d...\n",status);
	}
	return status;
}
