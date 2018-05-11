#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>


int main(){
	pid_t pid;
	pid = fork();

	if(pid == 0){
		printf("ChiLD ---(%d)\n",getpid());
		sleep(3);
		system("ps -l");
		printf("---------------------------\n");
	}
	else{
		printf("PARENT ===(%d)\n",getpid());
		printf("Returned PID = (%d)\n",pid);
		sleep(5);
		system("ps -l");
	}

	return 0;
}
