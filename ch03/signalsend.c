#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void signal_send(int pid, int signo){
	int ret;
ret = kill (pid, signo);
if(ret == 0)
	printf("Signal #(%d) successfully sent to (%d)\n", signo, pid);
else
	printf("Failed to send a signal\n");
}

int get_pid(){
	char pidof[128];
	FILE *fp;
	int pid;
	fp = popen("pid of a.out", "r");
	fgets(pidof,128,fp);
	pclose(fp);
	pid=atoi(pidof);
	return pid;
}

int main(int argc, char **argv){
	int pid;
	int signo;

	if(argc <2){
		printf("Usage : %s <filename>\n", argv[0]);
		exit(1);
	}

	signo = atoi(argv[1]);
	pid = get_pid();
	signal_send(pid, signo);
	return 0;
}
