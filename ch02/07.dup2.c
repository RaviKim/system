#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char ** argv){
	int fd;
	char *buf = "Hello World \n";

	if(argc <2){
		printf("Usage : %s <filename> \n", argv[0]);
		exit(1);
	}

	open(argv[1], O_WRONLY|O_CREAT|O_TRUNC,0644);
	dup2(fd, 1);
	close(fd);

	write(1, buf, strlen(buf));

	fprintf(stdout,"Let's call it a day\n");

}
