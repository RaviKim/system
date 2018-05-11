#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int signo){
	printf("Signal caught -- (%d)\n", signo);
}

int main(){
	int i = 0;
	signal(SIGINT, handler);
	signal(3, handler);
	signal(4, SIG_IGN);

	while(1){
		printf("I am doing my job - (%d)\n",i);
		i++;
		sleep(1);
	}

	return 0;
}
