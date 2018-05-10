#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv){

	struct stat buf;
	char * msg;
	int ret;	
	// IF ther is no command input,

	if(argv < 2){
		printf("Usage: %s <file name> \n", argv[0]);
		exit(1);
	}

	ret = lstat(argv[1],&buf);
	
	if(ret == -1){	//error
		if(errno == EACCES) printf("Permission Denied\n");
		if(errno == ENOENT) printf("File not exist\n");
	}

	if(S_ISREG(buf.st_mode))
		msg = "Regular file";
	else if(S_ISDIR(buf.st_mode))
		msg = "Directory file";
	
	printf("%s is %s\n", argv[1], msg);
	printf("I-node : %lo\n", buf.st_ino);
	printf("Mode : %lo\n", buf.st_mode);

	return 0;


}

