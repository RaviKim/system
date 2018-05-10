#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


typedef struct _INFO{
	char name[20];
	int age;
	float height;
}INFO;

#define BUF_SIZE 4096

int main(int argc, char **argv){

	int fd1, fd2, ret;
	char buf[BUF_SIZE];
	// Find Error Check.
	if(argc !=3){
		printf("Usage: %s <filename>\n", argv[0]);
		exit(1);
	}

	if((fd1 = open(argv[1], O_RDONLY)) == -1){
		perror("file open1 error");
		exit(1);
	}
	if((fd2 = open(argv[2], O_RDONLY|O_CREAT, S_IRWXU|S_IRWXG|S_IRWXO)) == -1){
		perror("file open2 error");
		close(fd1);
		exit(1);
	}

	while(1){
		ret = read(fd1, buf, BUF_SIZE);
		if(ret == 0)break;
		if(write (fd2, buf, ret) != ret){
			perror("write()");
			break;
		}
	}
	close(fd1);
	close(fd2);
}
