#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

void handler(int signo){
	int ret_pid = waitpid(-1,NULL, WNOHANG);
	printf("Child terminated -%d\n", ret_pid);
	//	return ret_pid;
}

int main(){

	pid_t pid1, pid2, ret_pid;

	int i = 0;
	int j = 0;

	int child1 = 0;
	int child2 = 0;
	int repeat = 0;

	signal(SIGCHLD, handler);

	switch(pid1=fork()){
		case -1:
			perror("fork");
			exit(1);
		case 0:	//child
			while(1){
				if(child1 == 5000){
					write(1,"*",1);
					child1 = 0;
				}
				child1++;
				repeat++;
				if(repeat == 5000000){
					break;
				}
			}
			exit(0);
		default:
			switch(pid2 = fork()){
				case -1:
					perror("fork");
					exit(1);

				case 0:
					for(i = 0; i < 10; ++i){
						printf("\tChild2 process -- %d\n",getpid());
					}
					exit(0);
			}
			while(1){
	//			while((ret_pid = waitpid(-1,NULL,WNOHANG)) 	>0){
	//				printf("Returned PID = %d\n", ret_pid);
	//			}
				if(errno == ECHILD){
					printf("No child\n");
					break;
				}
				if(j == 5000 ){
					write(1,".",1);
					j=0;
				}
				j++;
			}	
	}
	return 0;
}
