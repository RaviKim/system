#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(){
	pid_t pid;
	int pd[2];
	int readfd, writefd = 0;
	char tx_buf[32], rx_buf[32];

	pipe(pd);
	
	readfd = pd[0];
	writefd = pd[1];
	
	pid = fork();

switch(pid){
	case -1:
		perror("fork");
		exit(1);

	case 0:	//	child
		strcpy(tx_buf, "Hello MoM");
		write(writefd,tx_buf,strlen(tx_buf)+1);
		read(readfd, rx_buf, sizeof(rx_buf));		
		printf("Child received from Parent = %s\n", rx_buf);

	default:	// Parent
		read(readfd,rx_buf,sizeof(rx_buf));
		printf("Parent received from child = %s\n", rx_buf);
		strcpy(tx_buf, "Why");
		write(writefd, tx_buf, strlen(tx_buf)+1);
}
	return 0;
}
