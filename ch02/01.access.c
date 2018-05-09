#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int access(const char *pathname, int mode);
int main(int argc, char *argv[]){

	int ret;

	if(argc < 2){ 
		printf("Usage : %s < filename >\n",argv[0]);
		exit(1);
	}

	printf("File Name is %s\n",argv[1]);
	ret = access(argv[1], F_OK);
	if(ret ==0)
		printf("File Name %s is exist\n", argv[1]);
	else
		printf("File not exist");
	return 0;
}
