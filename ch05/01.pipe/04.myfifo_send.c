#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
	int fd, i; 
	int cnt =0; 
	char buf[128];

	fd = open("tmp/myfifo", O_RDWR);
	if( fd == -1){
		perror("open");
		exit(1);
	}   

	for( i = 0; i < 5; i++){
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "hello(%d)\n", i);
		write(fd, buf, strlen(buf)+1);
		printf("Rx -- %d : %s\n", cnt++, buf);
		sleep(1);
	}

	memset(buf, 0, sizeof(buf));
	sprintf(buf, "end");
	write(fd, buf, strlen(buf)+1);
	close(fd);
	return 0;
}

