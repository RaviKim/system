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

int main(int argc, char *argv[]){


	int fd;
	size_t ret;
	int i;
	INFO data;

	if( argc <2){
		printf("USage: %s <filename>\n", argv[0]);
		exit(1);
	}

	fd = open(argv[1], O_RDONLY);
	if(fd == -1){
		perror("fopen");
		exit(1);
	}

	for(;;){
		ret = read(fd,&data,sizeof(INFO));
		if(ret ==0) break;
		printf("Name : %s, Age : %d, Height : %1f\n", data.name, data.age, data.height);
	}
	close(fd);


	return 0;
}
