#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t pid;

	switch (pid = fork()){
		case -1:
			perror("fork");
			exit(1);

		case 0:	//child
			printf("Child process - (%d)\n", getpid());
			execl("./mytask", "mytask", "10",(char*)0);
			perror("execl");

		default:
			system("ps -l");
			printf("Parent process = %d\n", getpid());
			wait((int *)0);

			printf("Parent process ends\n");
			exit(0);
	}
	return 0;
}
