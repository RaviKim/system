#include <stdio.h>
#include <syslog.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
	pid_t pid;
	int cnt;
	pid = fork();
	if(pid ==-1){
		perror("fork"); 
		exit(1);
	}
	if(pid != 0){
		exit(0);
	}

	setsid();
	if(	chdir("/") == -1){
		perror("chdir");
		exit(1);
	}

	while(1){
		syslog(LOG_INFO|LOG_DAEMON, "Test Daemon Process(%d)\n", ++cnt);
		sleep(1);
	}
	return 0;
}
